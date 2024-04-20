#pragma once

#include "Shader.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <SDL2/SDL.h>

#include "CanvasData.h"
#include "Primitives.h"
#include "Utilities.h"
#include "Input.h"
#include "Windows.h"

#include <cmath>
#include <algorithm>

class Paintbrush
{
public:
	Paintbrush();
	~Paintbrush();
	void DrawInterpolatedPaintbrush(glm::vec3 Position);
	void DrawPaintbrushMenu();
private:
	float m_BrushSize;
	Shader m_BrushShader;
	void DrawPaintbrush(glm::vec3 Position);
};

