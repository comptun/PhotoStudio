#include "WindowManager.h"
//#include <iostream>
Windows::Windows()
{

}
Windows::~Windows()
{

}

void Windows::DrawColorWindow()
{
    ImGuiWindowClass window_class;
    window_class.DockNodeFlagsOverrideSet = ImGuiDockNodeFlags_NoWindowMenuButton;
    ImGui::SetNextWindowClass(&window_class);

    ImGui::BeginPS("Color", ImGuiWindowFlags_NoScrollbar);

    float w = (ImGui::GetContentRegionAvail().x - ImGui::GetStyle().ItemSpacing.y - 10);
    ImGui::SetNextItemWidth(w);

    ImGui::SetCursorPos({ 7,7 });
    
    ImGui::ColorPicker4("##MyColor##5", (float*)&WindowData::m_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoSidePreview);
    //std::cout << WindowData::m_Color.a << "\n";
    //WindowData::m_Color.a = 1.0f;
    ImGui::EndPS();
}