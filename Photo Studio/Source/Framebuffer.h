#pragma once

#include <glad/glad.h>
#include <iostream>

#include "Texture.h"

class Framebuffer
{
public:
	Framebuffer(unsigned char* Data, uint64_t Width, uint64_t Height);
	~Framebuffer();

	void Rescale(unsigned char* Data, uint64_t Width, uint64_t Height);

	void Bind();
	void Unbind();

	GLuint GetTexture();

	uint64_t m_Width, m_Height;
private:
	GLuint m_FBO;
	GLuint m_RBO;
	Texture m_Texture;
};

