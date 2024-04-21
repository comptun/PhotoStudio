#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <SDL2/SDL.h>

#include <cmath>

class Input
{
public:
	struct Mouse
	{
		inline static glm::vec2 Pos; // Position
		inline static glm::vec2 Rel; // Relative motion
		inline static uint8_t Button;
		inline static uint8_t State;
		inline static bool m_MouseInCanvas = false;
		inline static bool m_InitialClick = false;
	};

	static void ProcessMouseMotion(const SDL_MouseMotionEvent& MotionEvent);
	static void ProcessMouseButton(const SDL_MouseButtonEvent& ButtonEvent);
	static void ProcessMouseWheel(const SDL_MouseWheelEvent& WheelEvent);
};