#include "Tools.h"

Tools::Tools()
	: m_Tool(Tool::None)
{

}

void Tools::DrawToolPropertiesMenu()
{
	ImGuiWindowClass window_class;
	window_class.DockNodeFlagsOverrideSet = ImGuiDockNodeFlags_NoTabBar | ImGuiDockNodeFlags_NoResize;
	ImGui::SetNextWindowClass(&window_class);
	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(10, 13));
	ImGui::Begin("Tool Properties", nullptr, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);

	switch (m_Tool)
	{
		case Tool::None:
			ImGui::Text("No tool selected");
			break;
		case Tool::BrushTool:
			DrawPaintbrushMenu();
			break;
		case Tool::PaintBucket:
			ImGui::Text("Paint bucket");
			break;
	}

	ImGui::End();
	ImGui::PopStyleVar();
}