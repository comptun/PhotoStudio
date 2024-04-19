#include "Windows.h"

Windows::Windows()
{

}
Windows::~Windows()
{

}

void Windows::DrawColorWindow()
{
    ImGui::Begin("Color");

    float w = (ImGui::GetContentRegionAvail().x - ImGui::GetStyle().ItemSpacing.y);
    ImGui::SetNextItemWidth(w);
    ImGui::ColorPicker3("##MyColor##5", (float*)&WindowData::m_Color, ImGuiColorEditFlags_PickerHueBar | ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoAlpha);

    ImGui::End();
}