#include "Input.h"

#include "Application.h"

void Input::ProcessMouseMotion(const SDL_MouseMotionEvent& MotionEvent)
{
	Input::Mouse::Pos = { MotionEvent.x, MotionEvent.y };
	Input::Mouse::Rel = { MotionEvent.xrel, MotionEvent.yrel };

	Input::Mouse::m_InitialClick = false;
	
	if (!CanvasData::m_CanvasFocused)
		return;

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
	if (!CanvasData::m_CanvasFocused)
		return;

	CanvasData::m_CanvasScale += WheelEvent.preciseY / 10.0f;
}