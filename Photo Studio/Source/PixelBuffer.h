#pragma once

#include <iostream>
#include <glad/glad.h>

class PixelBuffer
{
public:
	PixelBuffer(GLenum Format, int Width, int Height, int Number);
	~PixelBuffer();
	void Download();

	uint32_t* GetPixels32Bit();

	unsigned char* m_Pixels;
	uint32_t* m_Pixels32;

	int m_Width;
	int m_Height;
	int m_NumBytes;
private:
	void Init();

	GLenum m_Format;
	GLuint* m_PBOs;
	uint64_t m_NumPBOs;
	uint64_t m_Index;
	uint64_t m_NumDownloads;
};

