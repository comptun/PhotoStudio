#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

struct Input
{
	struct Mouse
	{
		inline static glm::vec2 Pos; // Position
		inline static glm::vec2 Rel; // Relative motion
		inline static uint8_t Button;
		inline static uint8_t State;

		inline static bool m_InitialClick = false;
	};
};