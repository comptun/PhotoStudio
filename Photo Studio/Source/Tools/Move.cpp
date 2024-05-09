#include "Move.h"

Move::Move()
{

}
Move::~Move()
{

}

void Move::MoveLayer(std::shared_ptr<Layer> ActiveLayer)
{
	if (Input::Mouse::m_InitialClick && !Input::Mouse::m_MouseInCanvas) {
		return;
	}
	if (Input::Mouse::Button == SDL_BUTTON_LEFT && Input::Mouse::State == SDL_PRESSED) {
		ActiveLayer->m_LayerOffset += Input::Mouse::Rel / CanvasData::m_CanvasScale;
		Input::Mouse::Rel = { 0,0 };
	}
}