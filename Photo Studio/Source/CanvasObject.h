#pragma once

#include <iostream>
#include <vector>
#include <glad/glad.h>

class CanvasObject
{
public:
	CanvasObject(std::vector<unsigned int> indices, std::vector<float> vertices);
	~CanvasObject();

	void Draw();
private:
	GLuint m_VAO;
	GLuint m_VBO;
	GLuint m_EBO;

	std::vector<unsigned int> m_Indices;
	std::vector<float> m_Vertices;
};

