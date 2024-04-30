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
	window_class.DockNodeFlagsOverrideSet = ImGuiDockNodeFlags_NoTabBar | ImGuiDockNodeFlags_NoResize;
	
	ImGui::SetNextWindowClass(&window_class);
	ImGui::Begin("Toolbar");

	ImGui::PushStyleVar(ImGuiStyleVar_ButtonTextAlign, ImVec2(0.0f, 1.1f));
	ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 8.0f);
	ImGui::PushFont(Primitive::m_IconFont);

	if (ImGui::Button(ICON_MD_HIGHLIGHT_REMOVE, ImVec2(40,40))) {
		m_Tool = Tool::None;
	}
	ImGui::SameLine();
	ImGui::SetCursorPosX(53.0f);
	if (ImGui::Button(ICON_MD_BRUSH, ImVec2(40, 40))) {
		m_Tool = Tool::Brush;
	}

	if (ImGui::Button(ICON_MD_PHONELINK_ERASE, ImVec2(40, 40))) {
		m_Tool = Tool::Eraser;
	}
	ImGui::SameLine();
	ImGui::SetCursorPosX(53.0f);
	if (ImGui::Button(ICON_MD_FORMAT_COLOR_FILL, ImVec2(40, 40))) {
		m_Tool = Tool::PaintBucket;
	}

	if (ImGui::Button(ICON_MD_COLORIZE, ImVec2(40, 40))) {
		m_Tool = Tool::Eraser;
	}
	ImGui::SameLine();
	ImGui::SetCursorPosX(53.0f);

	ImGui::PopFont();
	ImGui::PopStyleVar(2);

	ImGui::End();
}