#pragma once

#include <glad/glad.h>
#include <iostream>

class Framebuffer
{
public:
	Framebuffer(uint64_t Width, uint64_t Height);
	~Framebuffer();

	void Rescale(uint64_t Width, uint64_t Height);

	void Bind();
	void Unbind();

	GLuint GetTexture();
private:
	GLuint m_FBO;
	GLuint m_RBO;
	GLuint m_Texture;
	uint64_t m_Width, m_Height;
};

