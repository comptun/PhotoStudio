#include "Windows.h"
//#include <iostream>
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
    ImGui::ColorPicker4("##MyColor##5", (float*)&WindowData::m_Color, 1);
    //std::cout << WindowData::m_Color.a << "\n";
    //WindowData::m_Color.a = 1.0f;
    ImGui::End();
}