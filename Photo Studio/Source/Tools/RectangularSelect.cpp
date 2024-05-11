#include "RectangularSelect.h"

RectangularSelect::RectangularSelect()
	: m_Start({-1,-1}), m_End({-1, -1})
{

}
RectangularSelect::~RectangularSelect()
{

}

void RectangularSelect::RectangularSelectStep(std::shared_ptr<Layer> ActiveLayer)
{
	glm::vec3 Pos = Input::Mouse::CanvasPos;
	//std::cout << m_Start.x << " " << m_Start.y << " | " << m_End.x << " " << m_End.y << "\n";
	if (Input::Mouse::Button == SDL_BUTTON_LEFT) {
		if (Input::Mouse::State == SDL_PRESSED) {
			if (Input::Mouse::m_InitialClick) {
				m_SelectedLayer = ActiveLayer;
				m_Start = Input::Mouse::CanvasPos;
				m_End = m_Start;
			}
			m_End = Input::Mouse::CanvasPos;
		}
		else if (Input::Mouse::State == SDL_RELEASED) {
			if (m_Start == m_End) {
				m_Start = { -1,-1 };
				m_End = { -1,-1 };
			}
		}
	}
}

void RectangularSelect::DrawRectangularSelect()
{
	if (m_Start == m_End) {
		return;
	}

	glm::vec2 Offset = { 0,0 };
	if (m_SelectedLayer) {
		Offset = m_SelectedLayer->m_LayerOffset;
	}

	Primitive::m_RectShader->UseProgram();
	Primitive::m_RectShader->Uniform<glm::mat4>("model",
		glm::scale(glm::translate(glm::mat4(1.0f),
			glm::vec3(m_Start.x + (m_End.x - m_Start.x) / 2.0f + Offset.x, m_Start.y + (m_End.y - m_Start.y) / 2.0f + Offset.y, 0.0f)
		), glm::vec3(m_End.x - m_Start.x, m_End.y - m_Start.y, 0))
	);
	Primitive::m_RectShader->Uniform<glm::mat4>("view", glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0)));
	Primitive::m_RectShader->Uniform<glm::mat4>("projection", glm::ortho(0.0f, CanvasData::m_CanvasSize.x, 0.0f, CanvasData::m_CanvasSize.y));
	Primitive::m_RectShader->Uniform<glm::vec4>("color", { 0.5f, 0.5f, 0.5f, 0.5f });

	Primitive::m_CanvasObject->Draw();
}