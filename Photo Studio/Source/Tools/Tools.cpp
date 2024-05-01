#include "Tools.h"

Tools::Tools()
	: m_Tool(Tool::None),
	m_ToolIndex(0)
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

void Tools::ToolButton(Tool SelectedTool, std::string ToolName, std::string Tooltip)
{
	if (ImGui::Button(ToolName.c_str(), ImVec2(40, 40))) {
		m_Tool = SelectedTool;
	}
	if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled)) {
		ImGui::SetTooltip(Tooltip.c_str());
	}

	if (m_ToolIndex % 2 == 0) {
		ImGui::SameLine();
		ImGui::SetCursorPosX(53.0f);
	}

	m_ToolIndex += 1;
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

	m_ToolIndex = 0;

	ToolButton(Tool::None, ICON_MD_HIGHLIGHT_REMOVE, "No tool");
	ToolButton(Tool::Brush, ICON_MD_BRUSH, "Brush tool");
	ToolButton(Tool::Eraser, ICON_MD_SMARTPHONE, "Eraser tool");
	ToolButton(Tool::PaintBucket, ICON_MD_FORMAT_COLOR_FILL, "Paint bucket tool");
	ToolButton(Tool::Eraser, ICON_MD_COLORIZE, "Eyedropper tool");
	ToolButton(Tool::Eraser, ICON_MD_FORMAT_SIZE, "Text tool");
	ToolButton(Tool::Eraser, ICON_MD_CROP, "Crop tool");
	ToolButton(Tool::Eraser, ICON_MD_SELECT_ALL, "Rectangular select tool");

	ImGui::PopFont();
	ImGui::PopStyleVar(2);

	ImGui::End();
}