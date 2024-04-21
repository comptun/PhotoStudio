#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

struct CanvasData
{
	inline static glm::vec2 m_CanvasSize;
	inline static glm::vec2 m_CanvasOffset = { 0, 0 };
	inline static float m_CanvasScale = 1.0f;
	inline static float m_CanvasMultiplier = 1.0f;
	inline static bool m_CanvasFocused = false;
};