#include "LayerManager.h"

LayerManager::LayerManager(glm::vec2& CanvasSize)
	: m_CanvasSize(CanvasSize),
	m_ActiveLayer(0),
	m_LayerYPos(0),
	m_InitialLayerClick(true),
	m_DraggingLayer(false)
{

}
LayerManager::~LayerManager()
{

}

void LayerManager::SetActiveLayer(uint64_t LayerID)
{
	m_ActiveLayer = LayerID;
}

uint64_t LayerManager::AddLayer(std::string LayerName)
{
	uint64_t ID = AddLayer(LayerName, glm::vec4(0,0,0,0));
	return ID;
}
uint64_t LayerManager::AddLayer(std::string LayerName, glm::vec4 Color)
{
	uint64_t ID = m_Layers.size();
	auto NewLayer = std::make_unique<Layer>(LayerName, ID, static_cast<uint64_t>(m_CanvasSize.x), static_cast<uint64_t>(m_CanvasSize.y), Color);
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

void LayerManager::NextLayerDraggable(int LayerIndex, int LayerNum)
{
	if (Input::Mouse::Button == SDL_BUTTON_LEFT) {
		if (Input::Mouse::State == SDL_PRESSED && (m_SelectedLayers.at(LayerIndex) || DraggingLayer)) {
			if (!m_InitialLayerClick)
				m_LayerYPos += Input::Mouse::Rel.y;
			Input::Mouse::Rel = { 0,0 };
			ImGui::SetCursorPosY(LayerNum * 55.0f + 27.0f + m_LayerYPos);
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

void LayerManager::DrawLayer(int LayerIndex, int LayerNum)
{
	if (LayerIndex == m_ActiveLayer) {
		ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.0f, 0.409f, 1.0f, 1.0f));
		NextLayerDraggable(LayerIndex, LayerNum);
	}
	else {
		ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.137f, 0.263f, 0.424f, 1.0f));
		ImGui::SetCursorPosY(LayerNum * 55.0f + 27.0f);
	}


	ImGui::PushStyleVar(ImGuiStyleVar_CellPadding, ImVec2(10.0f, 10.0f));
	ImGui::BeginChild(m_Layers[LayerIndex]->GetName().c_str(), ImVec2(ImGui::GetWindowWidth(), 50.0f));
	{
		ImGui::SetCursorPos(ImVec2(6, 13));
		ImGui::Checkbox("", &m_Layers[LayerIndex]->m_Visible);

		ImGui::SameLine();

		ImGui::SetCursorPosY(4);
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
		
		bool Button = ImGui::ButtonEx(("               " + m_Layers[LayerIndex]->GetName()).c_str(), ImVec2(ImGui::GetWindowWidth() - 30.0f, 50.0f), ImGuiButtonFlags_PressedOnClick);
		m_SelectedLayers.at(LayerIndex) = ImGui::IsItemHovered() || ImGui::IsWindowHovered();
		if (Button) {
			SetActiveLayer(LayerIndex);
		}

		ImGui::PopStyleColor(3);
	}
	ImGui::EndChild();
	ImGui::PopStyleVar();
	ImGui::PopStyleColor();
}

void LayerManager::DrawLayersWindow()
{
	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 5.0f));
	ImGui::Begin("Layers", nullptr, ImGuiWindowFlags_AlwaysVerticalScrollbar);
	ImGui::PopStyleVar();

	for (int i = m_Layers.size() - 1, Num = 0; i >= 0; --i, ++Num) {
		DrawLayer(i, Num);
	}

	ImGui::End();
}