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
	
	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(7, 0));
	ImGui::Begin("Tool Properties", nullptr, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);

	/*ImGui::SetCursorPos({ 5,9 });
	ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 4.0f);
	ImGui::PushStyleColor(ImGuiCol_ChildBg, { 0.2,0.2,0.2,1 });;
	ImGui::BeginChild("Tool Properties Child Shadow", { ImGui::GetWindowSize().x - 14, ImGui::GetWindowSize().y - 14 });
	ImGui::PopStyleColor();
	ImGui::PopStyleVar();
	ImGui::EndChild();*/

	ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 4.0f);
	ImGui::BeginChild("Tool Properties Child", { ImGui::GetWindowSize().x - 14, ImGui::GetWindowSize().y });
	ImGui::PopStyleVar();

	ImGui::SetCursorPos({ 8.0f, 13.0f });

	switch (m_Tool)
	{
		case Tool::None:
			ImGui::Text("No tool selected");
			break;
		case Tool::Move:
			ImGui::Text("Move tool");
			break;
		case Tool::Brush:
			DrawPaintbrushMenu();
			break;
		case Tool::Eraser:
			DrawEraserMenu();
			break;
		case Tool::PaintBucket:
			ImGui::Text("Paint bucket tool");
			break;
		case Tool::RectangularSelect:
			ImGui::Text("Rectangular select tool");
			break;
		case Tool::Eyedropper:
			ImGui::Text("Eyedropper tool");
			break;
		case Tool::Crop:
			ImGui::Text("Crop tool");
			break;
		case Tool::Text:
			ImGui::Text("Text tool");
			break;
	}

	ImGui::EndChild();

	ImGui::End();
	ImGui::PopStyleVar();
}

void Tools::ToolButton(Tool SelectedTool, std::string ToolName, std::string Tooltip)
{
	if (m_ToolIndex % 2 == 0) {
		ImGui::SetCursorPosX(5);
	}

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
		ImGui::SetCursorPosX(50.0f);
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

	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
	ImGui::Begin("Toolbar");

	ImGui::PushStyleVar(ImGuiStyleVar_ButtonTextAlign, ImVec2(0.0f, 1.1f));
	ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 8.0f);
	ImGui::PushFont(Primitive::m_IconFont);

	//ImGui::SetCursorPos({ 5,2 });
	//ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 4.0f);
	//ImGui::PushStyleColor(ImGuiCol_ChildBg, { 0.2,0.2,0.2,1 });;
	//ImGui::BeginChild("Tool Properties Child Shadow", { ImGui::GetWindowSize().x - 14, ImGui::GetWindowSize().y - 7 });
	//ImGui::PopStyleColor();
	//ImGui::PopStyleVar();
	//ImGui::EndChild();


	ImGui::SetCursorPos({ 7,0 });
	ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 4.0f);
	ImGui::BeginChild("Toolbar Child", { ImGui::GetWindowSize().x, ImGui::GetWindowSize().y - 7 });
	ImGui::PopStyleVar();

	ImGui::SetCursorPosY(5);

	m_ToolIndex = 0;

	m_ToolHovered = false;

	ToolButton(Tool::None, ICON_MD_HIGHLIGHT_REMOVE, "No tool");
	ToolButton(Tool::Move, ICON_MD_PAN_TOOL_ALT, "Move tool");
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

	ImGui::EndChild();

	ImGui::End();
	ImGui::PopStyleVar();
}