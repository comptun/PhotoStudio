#include "Input.h"

#include "Application.h"

void Input::ProcessMouseMotion(const SDL_MouseMotionEvent& MotionEvent)
{
	Input::Mouse::Pos = { MotionEvent.x, MotionEvent.y };
	Input::Mouse::Rel = { MotionEvent.xrel, MotionEvent.yrel };
	
	if (!CanvasData::m_CanvasFocused)
		return;

	Input::Mouse::m_InitialClick = false;

	if (Input::Mouse::Button == SDL_BUTTON_MIDDLE && Input::Mouse::State == SDL_PRESSED) {
		CanvasData::m_CanvasOffset += Input::Mouse::Rel;
	}
}

void Input::ProcessMouseButton(const SDL_MouseButtonEvent& ButtonEvent)
{
	Input::Mouse::Button = ButtonEvent.button;
	Input::Mouse::State = ButtonEvent.state;
	Input::Mouse::Pos = { ButtonEvent.x, ButtonEvent.y };

	Input::Mouse::m_InitialClick = true;
}

void Input::ProcessMouseWheel(const SDL_MouseWheelEvent& WheelEvent)
{
	if (!CanvasData::m_CanvasFocused || !CanvasData::m_CanvasHovered)
		return;
	static float ScrolledAmount = 0;
	if (CanvasData::m_CanvasScale == GetInitialScale()) {
		ScrolledAmount = 0;
	}
	ScrolledAmount -= static_cast<float>(WheelEvent.y) / 10.0f;
	//CanvasData::m_CanvasScale = std::pow(2, -ScrolledAmount);
	CanvasData::m_CanvasMultiplier = std::pow(2, -ScrolledAmount);
}

float Input::GetInitialScale()
{
	float Scale = 1.0f;
	for (; Scale >= 0; Scale -= 0.01f) {
		if (Scale * CanvasData::m_CanvasSize.y < CanvasData::m_ViewportSize.y - 100) {
			return Scale;
		}
	}
	return 1.0f;
}