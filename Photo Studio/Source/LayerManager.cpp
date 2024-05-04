#include "LayerManager.h"

LayerManager::LayerManager(glm::vec2& CanvasSize)
	: m_CanvasSize(CanvasSize),
	m_ActiveLayer(0),
	m_LayerYPos(0),
	m_InitialLayerClick(true),
	m_DraggingLayer(false),
	m_LayersWindowPos({0,0}),
	m_LayerOffset(0)
{

}
LayerManager::~LayerManager()
{

}

void LayerManager::SetActiveLayer(uint64_t LayerID)
{
	m_ActiveLayer = LayerID;
}
uint64_t LayerManager::AddLayer()
{
	std::string Name = "Layer " + std::to_string(m_Layers.size() + 1);
	uint64_t ID = AddLayer(Name);
	return ID;
}
uint64_t LayerManager::AddLayer(std::string LayerName)
{
	uint64_t ID = AddLayer(LayerName, glm::vec4(0,0,0,0));
	return ID;
}
uint64_t LayerManager::AddLayer(std::string LayerName, glm::vec4 Color)
{
	uint64_t ID = m_Layers.size();
	auto NewLayer = std::make_shared<Layer>(LayerName, ID, static_cast<uint64_t>(m_CanvasSize.x), static_cast<uint64_t>(m_CanvasSize.y), Color);
	m_Layers.push_back(std::move(NewLayer));
	m_SelectedLayers.push_back(false);
	return ID;
}
void LayerManager::BindActiveLayer()
{
	m_Layers.at(m_ActiveLayer)->Bind();
}
void LayerManager::UnbindActiveLayer()
{
	m_Layers.at(m_ActiveLayer)->Unbind();
}
void LayerManager::DrawLayers()
{

}
std::shared_ptr<Layer> LayerManager::GetActiveLayer()
{
	return m_Layers[m_ActiveLayer];
}

void LayerManager::NextLayerDraggable(int LayerIndex)
{
	int LayerNum = m_Layers.size() - 1 - LayerIndex;

	if (Input::Mouse::Button == SDL_BUTTON_LEFT) {
		if (Input::Mouse::State == SDL_PRESSED && (m_SelectedLayers.at(LayerIndex) || m_DraggingLayer)) {
			if (m_InitialLayerClick)
				m_LayerYPos = (m_WindowYPos + Input::Mouse::Pos.y - m_LayersWindowPos.y + ImGui::GetScrollY()) - (LayerNum * 50.0f);

			Input::Mouse::Rel = { 0,0 };
			m_InitialLayerClick = false;
			m_DraggingLayer = true;
		}
		else if (Input::Mouse::State == SDL_RELEASED) {
			m_LayerYPos = 0.0f;
			m_InitialLayerClick = true;
			m_DraggingLayer = false;
		}
	}
}

void LayerManager::DrawLayer(int LayerIndex, bool Dragging, float Opacity)
{
	int LayerNum = m_Layers.size() - 1 - LayerIndex;

	if (Dragging) {
		
		float DragPos = (m_WindowYPos + Input::Mouse::Pos.y - m_LayersWindowPos.y + ImGui::GetScrollY()) - m_LayerYPos;
		ImGui::SetCursorPosY(DragPos);

		int Index = (int)m_Layers.size() - (int)(DragPos + 25.0f) / 50 - 1;

		// the hell is this?

		if (Index >= 0 && Index < m_Layers.size() && m_ActiveLayer != Index) {
			std::shared_ptr<Layer> LayerPtr = m_Layers.at(LayerIndex);
			if (Index > LayerIndex) {
				m_Layers.insert(m_Layers.begin() + Index + 1, LayerPtr);
				m_Layers.erase(m_Layers.begin() + LayerIndex);
				m_ActiveLayer = Index;
			}
			else if (Index < LayerIndex) {
				m_Layers.erase(m_Layers.begin() + LayerIndex);
				m_Layers.insert(m_Layers.begin() + Index, LayerPtr);
				m_ActiveLayer = Index;
			}
			return;
		}
	}
	else {
		ImGui::SetCursorPosY(LayerNum * 50.0f);
	}

	if (m_ActiveLayer == LayerIndex) {
		ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.0f, 0.409f, 1.0f, Opacity));
		NextLayerDraggable(LayerIndex);
	}
	else {
		ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.137f, 0.263f, 0.424f, Opacity));
	}

	std::string LayerName = m_Layers[LayerIndex]->GetName();
	if (Dragging) {
		LayerName += " ";
	}

	ImGui::PushStyleVar(ImGuiStyleVar_CellPadding, ImVec2(10.0f, 10.0f));
	ImGui::BeginChild(LayerName.c_str(), ImVec2(ImGui::GetWindowWidth(), 50.0f));
	{
		ImGui::SetCursorPos(ImVec2(6, 13));
		ImGui::Checkbox("", &m_Layers[LayerIndex]->m_Visible);

		ImGui::SameLine();

		/*ImGui::PushStyleColor(ImGuiCol_Separator, ImVec4(1, 1, 1, 1));
		ImGui::SeparatorEx(ImGuiSeparatorFlags_Vertical);
		ImGui::PopStyleColor();*/

		ImGui::SetCursorPosY(0);
		ImVec2 ps = ImGui::GetCursorScreenPos();
		ImGui::GetWindowDrawList()->AddLine({ ps.x, ps.y-1}, { ps.x,ps.y+51}, IM_COL32(255, 255, 255, 100), 0.5f);

		ImGui::SetCursorPos({ 40, 3.5 });
		ps = ImGui::GetCursorScreenPos();
		ImGui::GetWindowDrawList()->AddRectFilled({ ps.x, ps.y }, { ps.x + 42,ps.y + 42 }, IM_COL32(255, 255, 255, 100));

		ImGui::SetCursorPos({ 40, 3.5 });
		ImVec2 pos = ImGui::GetCursorScreenPos();
		ImGui::GetWindowDrawList()->AddImage(
			(void*)m_Layers[LayerIndex]->GetTexture(),
			ImVec2(pos.x, pos.y),
			ImVec2(pos.x + 42.0f, pos.y + 42.0f),
			ImVec2(0, 1),
			ImVec2(1, 0)
		);

		ImGui::SameLine();

		ImGui::SetCursorPos(ImVec2(30.0f,0));

		ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0, 0, 0, 0));
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0, 0, 0, 0));
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0, 0, 0, 0));
		
		ImGui::PushStyleVar(ImGuiStyleVar_ButtonTextAlign, ImVec2(0, 0.5));
		
		bool Button = ImGui::ButtonEx(("                 " + LayerName).c_str(), ImVec2(ImGui::GetWindowWidth() - 30.0f, 50.0f), ImGuiButtonFlags_PressedOnClick);
		if (!Dragging) {
			m_SelectedLayers.at(LayerIndex) = ImGui::IsItemHovered();
			if (Button) {
				SetActiveLayer(LayerIndex);
			}
		}

		ImGui::PopStyleColor(3);

		ImGui::SetCursorPos({0,49});
		ps = ImGui::GetCursorScreenPos();
		ImGui::GetWindowDrawList()->AddLine({ ps.x, ps.y }, { ps.x+ImGui::GetWindowSize().x,ps.y}, IM_COL32(255, 255, 255, 100), 0.5f);
	}
	ImGui::EndChild();
	ImGui::PopStyleVar();
	ImGui::PopStyleColor();
}

void LayerManager::DrawLayersWindow()
{
	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
	ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
	ImGui::Begin("Layers");

	ImVec2 LayerWinSize = ImGui::GetWindowSize();

	ImGui::BeginChild("LayerList", { LayerWinSize.x, LayerWinSize.y - 55.0f }, ImGuiChildFlags_None, ImGuiWindowFlags_AlwaysVerticalScrollbar);
	ImGui::PopStyleVar(2);

	ImVec2 WindowPos = ImGui::GetWindowPos();
	m_LayersWindowPos = { WindowPos.x, WindowPos.y };

	int xPos;
	SDL_GetWindowPosition(SDL_GL_GetCurrentWindow(), &xPos, &m_WindowYPos);

	for (int i = 0; i < m_Layers.size(); ++i) {
		DrawLayer(i);
	}

	if (m_DraggingLayer) {
		DrawLayer(m_ActiveLayer, true, 0.5f);
	}

	ImGui::EndChild();

	ImGui::SetCursorPosY(LayerWinSize.y - 33.0f);

	ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.15f, 0.15f, 0.15f, 1.0f));
	ImGui::BeginChild("LayerProperties");
	ImGui::PopStyleColor();

	ImGui::SetWindowFontScale(0.6f);
	ImGui::PushFont(Primitive::m_IconFont);

	ImGui::PushStyleVar(ImGuiStyleVar_ButtonTextAlign, ImVec2(0.0f, 1.5f));

	ImGui::SetCursorPos({ 5, 5 });
	if (ImGui::Button(ICON_MD_ADD, ImVec2(28, 22))) {
		AddLayer();
	}

	ImGui::PopStyleVar();

	ImGui::PopFont();

	ImGui::EndChild();

	ImGui::End();

	/*ImGuiWindowClass window_class;
	window_class.DockNodeFlagsOverrideSet = ImGuiDockNodeFlags_NoTabBar | ImGuiDockNodeFlags_NoUndocking;
	ImGui::SetNextWindowClass(&window_class);*/
}