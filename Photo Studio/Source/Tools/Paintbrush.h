#pragma once

#include "Shader.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <SDL2/SDL.h>

#include "CanvasData.h"
#include "Primitives.h"
#include "Utilities.h"
#include "Input.h"

#include <cmath>
#include <algorithm>

class Paintbrush
{
public:
	Paintbrush();
	~Paintbrush();
	void DrawInterpolatedPaintbrush(glm::vec3 Start, glm::vec3 End);
	void DrawPaintbrush(glm::vec3 Position);
private:
	Shader m_BrushShader;

	
};

