#include "Move.h"

Move::Move()
{

}
Move::~Move()
{

}

void Move::MoveLayer(std::shared_ptr<Layer> ActiveLayer)
{
	static bool Unpressed = false;
	if (Input::Mouse::m_InitialClick && !Input::Mouse::m_MouseInCanvas) {
		return;
	}
	if (Input::Mouse::Button == SDL_BUTTON_LEFT) {
		if (Input::Mouse::State == SDL_PRESSED) {
			ActiveLayer->m_LayerOffset += Input::Mouse::Rel / CanvasData::m_CanvasScale;
			ActiveLayer->m_ActualOffset += Input::Mouse::Rel;
			Input::Mouse::Rel = { 0,0 };
			Unpressed = true;
		}
		else if (Input::Mouse::State == SDL_RELEASED && Unpressed) {
			//ActiveLayer->Rescale(nullptr, ActiveLayer->m_Width + ActiveLayer->m_LayerOffset.x, ActiveLayer->m_Height + ActiveLayer->m_LayerOffset.y);
			Unpressed = false;
		}
	}
}