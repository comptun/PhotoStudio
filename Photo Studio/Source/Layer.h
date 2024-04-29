#pragma once

#include "Framebuffer.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Layer : public Framebuffer
{
public:
	Layer(std::string LayerName, uint64_t Index, uint64_t Width, uint64_t Height);
	~Layer();
private:
	std::string m_LayerName;
};

