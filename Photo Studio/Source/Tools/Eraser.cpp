#include "Eraser.h"

Eraser::Eraser()
    : m_EraserSize(10.0f)
{

}
Eraser::~Eraser()
{

}

float Eraser::GetEraserSize()
{
    return m_EraserSize;
}

void Eraser::DrawEraserMenu()
{
    ImGui::Text("Eraser tool");

    ImGui::SameLine();

    ImGui::SeparatorEx(ImGuiSeparatorFlags_Vertical);

    ImGui::SameLine();

    static ImGuiSliderFlags flags = ImGuiSliderFlags_None;
    ImGui::SetNextItemWidth(200.0f);
    ImGui::SetCursorPosY(10.0f);
    ImGui::SliderFloat("Size", &m_EraserSize, 0.0f, 300.0f, "%f", flags);
}