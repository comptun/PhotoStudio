#include "Input.h"

#include "Application.h"

void Application::ProcessMouseMotion(const SDL_MouseMotionEvent& MotionEvent)
{
	Input::Mouse::Pos = { MotionEvent.x, MotionEvent.y };
	Input::Mouse::Rel = { MotionEvent.xrel, MotionEvent.yrel };

	if (Input::Mouse::Button == SDL_BUTTON_MIDDLE && Input::Mouse::State == SDL_PRESSED) {
		CanvasData::m_CanvasOffset += Input::Mouse::Rel;
	}
}

void Application::ProcessMouseButton(const SDL_MouseButtonEvent& ButtonEvent)
{
	Input::Mouse::Button = ButtonEvent.button;
	Input::Mouse::State = ButtonEvent.state;
	Input::Mouse::Pos = { ButtonEvent.x, ButtonEvent.y };
}

void Application::ProcessMouseWheel(const SDL_MouseWheelEvent& WheelEvent)
{

}