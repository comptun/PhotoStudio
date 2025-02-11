#pragma once

#include "Framebuffer.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Layer : public Framebuffer
{
public:
	Layer(std::string LayerName, uint64_t Index, uint64_t Width, uint64_t Height, glm::vec4 Color);
	~Layer();

	std::string GetName();

	bool m_Visible;

	glm::vec2 m_LayerOffset;
	glm::vec2 m_ActualOffset;
	std::string m_LayerName;
};

