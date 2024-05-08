#pragma once

#include <memory>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "PixelBuffer.h"
#include "Layer.h"
#include "Input.h"
#include "Primitives.h"
#include "CanvasData.h"

class RectangularSelect
{
public:
	RectangularSelect();
	~RectangularSelect();

	void RectangularSelectStep();
	void DrawRectangularSelect();

private:
	glm::vec2 m_Start, m_End;
};