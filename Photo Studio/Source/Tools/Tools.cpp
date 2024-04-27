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
	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(11, 13));
	ImGui::Begin("Tool Properties", nullptr, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);

	switch (m_Tool)
	{
		case Tool::None:
			ImGui::Text("No tool selected");
			break;
		case Tool::Brush:
			DrawPaintbrushMenu();
			break;
		case Tool::Eraser:
			DrawEraserMenu();
			break;
		case Tool::PaintBucket:
			ImGui::Text("Paint bucket");
			break;
	}

	ImGui::End();
	ImGui::PopStyleVar();
}

void Tools::DrawToolbar()
{
	ImGuiWindowClass window_class;
	window_class.DockNodeFlagsOverrideSet = ImGuiDockNodeFlags_NoTabBar;
	
	ImGui::SetNextWindowClass(&window_class);

	ImGui::Begin("Toolbar");

	if (ImGui::Button("None")) {
		m_Tool = Tool::None;
	}
	if (ImGui::Button("Brush tool")) {
		m_Tool = Tool::Brush;
	}
	if (ImGui::Button("Eraser tool")) {
		m_Tool = Tool::Eraser;
	}
	if (ImGui::Button("Paint Bucket tool")) {
		m_Tool = Tool::PaintBucket;
	}

	ImGui::End();
}