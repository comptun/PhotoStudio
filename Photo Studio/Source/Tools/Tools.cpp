#include "Tools.h"

Tools::Tools()
	: m_Tool(Tool::Brush),
	m_HoveredTool(Tool::NullTool),
	m_ToolHovered(false),
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
	if (m_Tool == SelectedTool)
		ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.3, 0.3, 0.3, 0.5));

	if (m_Tool!=SelectedTool)
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, { 0,0,0,0 });

	if (m_HoveredTool == SelectedTool || m_Tool == SelectedTool) {
		ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1, 1, 1, 1));
	}
	else {
		ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.6, 0.6, 0.6, 1));
	}

	if (ImGui::Button(ToolName.c_str(), ImVec2(40, 40))) {
		m_Tool = SelectedTool;
	}

	ImGui::PopStyleColor();

	if (m_Tool != SelectedTool)
		ImGui::PopStyleColor();

	if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled)) {
		m_HoveredTool = SelectedTool;
		m_ToolHovered = true;
		ImGui::SetTooltip(Tooltip.c_str());
	}

	if (m_ToolIndex % 2 == 0) {
		ImGui::SameLine();
		ImGui::SetCursorPosX(53.0f);
	}

	if (m_Tool == SelectedTool)
		ImGui::PopStyleColor();

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

	m_ToolHovered = false;

	ToolButton(Tool::None, ICON_MD_HIGHLIGHT_REMOVE, "No tool");
	ToolButton(Tool::Brush, ICON_MD_BRUSH, "Brush tool");
	ToolButton(Tool::Eraser, ICON_MD_SMARTPHONE, "Eraser tool");
	ToolButton(Tool::PaintBucket, ICON_MD_FORMAT_COLOR_FILL, "Paint bucket tool");
	ToolButton(Tool::Eyedropper, ICON_MD_COLORIZE, "Eyedropper tool");
	ToolButton(Tool::Text, ICON_MD_FORMAT_SIZE, "Text tool");
	ToolButton(Tool::Crop, ICON_MD_CROP, "Crop tool");
	ToolButton(Tool::RectangularSelect, ICON_MD_SELECT_ALL, "Rectangular select tool");

	if (!m_ToolHovered) {
		m_HoveredTool = Tool::NullTool;
	}

	ImGui::PopFont();
	ImGui::PopStyleVar(2);

	ImGui::End();
}