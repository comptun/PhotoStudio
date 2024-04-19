#include "Paintbrush.h"

Paintbrush::Paintbrush()
	: m_BrushShader(ShaderType::BRUSH_VS, ShaderType::BRUSH_FS)
{

}
Paintbrush::~Paintbrush()
{

}
void Paintbrush::DrawInterpolatedPaintbrush(glm::vec3 Position)
{
    static glm::vec3 PreviousPosition = Position;
    static glm::vec3 PreviousDrawnPosition = Position;
    static bool Pressed = true;

    if (!(Input::Mouse::Button == SDL_BUTTON_LEFT && Input::Mouse::State == SDL_PRESSED)) {
        PreviousPosition = Position;
        Pressed = false;
        return;
    }

    float DrawDist = glm::length(PreviousDrawnPosition - Position);

    if (DrawDist <= 1.0f && Pressed) {
        return;
    }
    Pressed = true;

    glViewport(0, 0, CanvasData::m_CanvasSize.x, CanvasData::m_CanvasSize.y);

    m_BrushShader.UseProgram();

    float Dist = glm::length(PreviousPosition - Position);

    int Steps = Dist + 1;

    m_BrushShader.Uniform<glm::mat4>("view", glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0)));
    m_BrushShader.Uniform<glm::mat4>("projection", glm::ortho(0.0f, (float)CanvasData::m_CanvasSize.x, 0.0f, (float)CanvasData::m_CanvasSize.y));
    m_BrushShader.Uniform<glm::vec4>("Color", WindowData::m_Color);

    for (int i = 1; i <= Steps; ++i) {
        glm::vec3 Pos = glm::lerp(PreviousPosition, Position, (float)i * 1.0/(float)Steps);
        DrawPaintbrush(Pos);
    }

    PreviousDrawnPosition = Position;
    PreviousPosition = Position;
}

void Paintbrush::DrawPaintbrush(glm::vec3 Position)
{
    m_BrushShader.Uniform<glm::mat4>("model", glm::scale(glm::translate(glm::mat4(1.0f), Position), glm::vec3(5, 5, 0)));

    Primitive::m_CanvasObject->Draw();
}