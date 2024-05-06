#include "Brush.h"

Brush::Brush()
	: m_BrushShader(ShaderType::BRUSH_VS, ShaderType::BRUSH_FS),
    m_BrushSize(10.0f)
{

}
Brush::~Brush()
{

}
void Brush::DrawInterpolatedPaintbrush(glm::vec3 Position, float CustomSize)
{
    static glm::vec3 PreviousPosition = Position;
    static glm::vec3 PreviousDrawnPosition = Position;
    static bool Pressed = true;

    if (!(Input::Mouse::Button == SDL_BUTTON_LEFT && Input::Mouse::State == SDL_PRESSED)) {
        PreviousPosition = Position;
        Pressed = false;
        return;
    }

    if (Input::Mouse::m_InitialClick) {
        PreviousPosition = Position;
        PreviousDrawnPosition = Position;
    }

    if (!Input::Mouse::m_MouseInCanvas) {
        PreviousPosition = Position;
        PreviousDrawnPosition = Position;
        return;
    }

    float DrawDist = glm::length(PreviousDrawnPosition - Position);

    if (DrawDist <= 1.0f && Pressed) {
        return;
    }
    Pressed = true;

    m_BrushShader.UseProgram();

    float Dist = glm::length(PreviousPosition - Position);

    int Steps = Dist / 4.0f + 1;

    m_BrushShader.Uniform<glm::mat4>("view", glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0)));
    m_BrushShader.Uniform<glm::mat4>("projection", glm::ortho(0.0f, (float)CanvasData::m_CanvasSize.x, 0.0f, (float)CanvasData::m_CanvasSize.y));
    m_BrushShader.Uniform<glm::vec4>("Color", WindowData::m_Color);
    //glDisable(GL_BLEND);
    for (int i = 1; i <= Steps; ++i) {
        glm::vec3 Pos = glm::lerp(PreviousPosition, Position, (float)i * 1.0/(float)Steps);
        
        switch (m_BrushMode)
        {
        case BrushMode::Eraser:
            glDisable(GL_BLEND);
            m_BrushShader.Uniform<glm::vec4>("Color", {0.0f,0.0f,0.0f,0.0});
            DrawPencil(Pos, CustomSize);
            glEnable(GL_BLEND);
            break;
        case BrushMode::Pencil:
            DrawPencil(Pos, m_BrushSize);
            break;
        }
    }
    //glEnable(GL_BLEND);
    PreviousDrawnPosition = Position;
    PreviousPosition = Position;
}

void Brush::DrawPencil(glm::vec3 Position, float Size)
{
    /*static float offset = -1.0f;
    Position.z = offset;*/
    //offset += 0.0000001f;
    m_BrushShader.Uniform<glm::mat4>("model", glm::scale(glm::translate(glm::mat4(1.0f), Position), glm::vec3(Size, Size, 0)));

    Primitive::m_BrushObject->Draw();
}

void Brush::DrawPaintbrushMenu()
{
    ImGui::Text("Brush tool");

    ImGui::SameLine();

    ImGui::SeparatorEx(ImGuiSeparatorFlags_Vertical);

    ImGui::SameLine();

    static ImGuiSliderFlags flags = ImGuiSliderFlags_None;
    ImGui::SetNextItemWidth(200.0f);
    ImGui::SetCursorPosY(11.0f);
    ImGui::SliderFloat("Size", &m_BrushSize, 0.0f, 300.0f, "%f", flags);
}