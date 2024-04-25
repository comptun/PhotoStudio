#pragma once

#include <iostream>

#include <glad/glad.h>

class Texture
{
public:
	Texture();
	~Texture();

	void Generate();
	void Load(unsigned char* Data, uint64_t Width, uint64_t Height);

	void Bind();
	void Unbind();

	GLuint GetID();
private:
	GLuint m_ID;
};

