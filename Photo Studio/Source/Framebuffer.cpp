#include "Framebuffer.h"

Framebuffer::Framebuffer(unsigned char* Data, uint64_t Width, uint64_t Height)
	: m_Width(Width), m_Height(Height)
{
	glGenFramebuffers(1, &m_FBO);
	glBindFramebuffer(GL_FRAMEBUFFER, m_FBO);

	m_Texture.Generate();
	m_Texture.Bind();
	m_Texture.Load(Data, Width, Height);

	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_Texture.GetID(), 0);

	glGenRenderbuffers(1, &m_RBO);
	glBindRenderbuffer(GL_RENDERBUFFER, m_RBO);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, Width, Height);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, m_RBO);

	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		std::cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!\n";

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	m_Texture.Unbind();
	glBindRenderbuffer(GL_RENDERBUFFER, 0);
}

Framebuffer::~Framebuffer()
{
	glDeleteRenderbuffers(1, &m_RBO);
	glDeleteFramebuffers(1, &m_FBO);
}

void Framebuffer::Rescale(unsigned char* Data, uint64_t Width, uint64_t Height)
{
	m_Texture.Bind();
	m_Texture.Load(Data, Width, Height);

	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_Texture.GetID(), 0);

	glBindRenderbuffer(GL_RENDERBUFFER, m_RBO);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, Width, Height);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, m_RBO);
	m_Texture.Unbind();
}

void Framebuffer::Bind()
{
	glBindFramebuffer(GL_FRAMEBUFFER, m_FBO);
}
void Framebuffer::Unbind()
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

GLuint Framebuffer::GetTexture()
{
	return m_Texture.GetID();
}