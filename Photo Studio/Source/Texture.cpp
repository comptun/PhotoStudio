#include "Texture.h"

Texture::Texture()
	: m_ID(0)
{

}
Texture::~Texture()
{

}

void Texture::Generate()
{
	glGenTextures(1, &m_ID);
}

void Texture::Load(unsigned char* Data, uint64_t Width, uint64_t Height)
{
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, Width, Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, Data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
}

void Texture::Bind()
{
	glBindTexture(GL_TEXTURE_2D, m_ID);
}
void Texture::Unbind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

GLuint Texture::GetID()
{
	return m_ID;
}