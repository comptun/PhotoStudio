#pragma once

#include "Shader.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <SDL2/SDL.h>

#include "CanvasData.h"
#include "Primitives.h"
#include "Utilities.h"
#include "Input.h"
#include "WindowManager.h"
#include "IconsMaterialDesign.h"

#include <cmath>
#include <algorithm>

enum class BrushMode
{
	Pencil,
	Eraser,
};

constexpr float DefaultCustomSize = -1.0f;

class Brush
{
public:
	Brush();
	~Brush();
	BrushMode m_BrushMode;
	void DrawInterpolatedPaintbrush(float CustomSize = DefaultCustomSize);
	void DrawPaintbrushMenu();
private:
	float m_BrushSize;
	Shader m_BrushShader;
	void DrawPencil(glm::vec3 Position, float Size);
};

