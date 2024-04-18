#include "Paintbrush.h"

Paintbrush::Paintbrush()
	: m_BrushShader(ShaderType::BRUSH_VS, ShaderType::BRUSH_FS)
{

}
Paintbrush::~Paintbrush()
{

}
void Paintbrush::DrawInterpolatedPaintbrush(glm::vec3 Start, glm::vec3 End)
{
    if (!(Input::Mouse::Button == SDL_BUTTON_LEFT && Input::Mouse::State == SDL_PRESSED))
        return;

    glViewport(0, 0, CanvasData::m_CanvasSize.x, CanvasData::m_CanvasSize.y);

    m_BrushShader.UseProgram();

    float Diff = glm::length(Start - End);
    std::cout << Diff << "\n";

    DrawPaintbrush(End);

    if (Diff > 5.0f) {
        glm::vec3 mid = glm::lerp(Start, End, 0.5);
        DrawInterpolatedPaintbrush(Start, mid);
        Start = mid;
    }

    //Diff = glm::length(Start - End);
    int Steps = Diff;
    for (int i = 1; i < Steps; ++i) {
        glm::vec3 Pos = glm::lerp(Start, End, std::clamp(1.0f / (float)i, 0.0f, 1.0f));
        DrawPaintbrush(Pos);
    }

}

void Paintbrush::DrawPaintbrush(glm::vec3 Position)
{
    m_BrushShader.Uniform<glm::mat4>("model", glm::scale(glm::translate(glm::mat4(1.0f), Position), glm::vec3(10, 10, 0)));
    m_BrushShader.Uniform<glm::mat4>("view", glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0)));
    m_BrushShader.Uniform<glm::mat4>("projection", glm::ortho(0.0f, (float)CanvasData::m_CanvasSize.x, 0.0f, (float)CanvasData::m_CanvasSize.y));
    m_BrushShader.Uniform<glm::vec4>("Color", { 1.0f,0.0f,0.0f,1.0f });

    Primitive::m_CanvasObject->Draw();
}