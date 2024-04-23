#pragma once

#include <iostream>
#include <glad/glad.h>

class PixelBuffer
{
public:
	PixelBuffer(GLenum Format, int Width, int Height, int Number);
	~PixelBuffer();
	void Download();

	unsigned char* m_Pixels;
private:
	void Init();

	GLenum m_Format;
	GLuint* m_PBOs;
	uint64_t m_NumPBOs;
	uint64_t m_Index;
	uint64_t m_NumDownloads;
	int m_Width;
	int m_Height;
	int m_NumBytes;
};

