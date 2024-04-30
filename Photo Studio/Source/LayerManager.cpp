#include "LayerManager.h"

LayerManager::LayerManager(glm::vec2& CanvasSize)
	: m_CanvasSize(CanvasSize),
	m_ActiveLayer(0)
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
void LayerManager::DrawLayersWindow()
{
	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 5.0f));
	ImGui::Begin("Layers");
	ImGui::PopStyleVar();
	
	//ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(1, 1, 1, 1));

	for (int i = m_Layers.size() - 1; i >= 0; --i) {
		/*if (i == m_ActiveLayer) {
			ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.0f, 0.509f, 1.0f, 1.0f));
		}
		bool Answer = ImGui::Button(m_Layers[i]->GetName().c_str(), ImVec2(ImGui::GetWindowWidth(), 40.0f));
		if (i == m_ActiveLayer) {
			ImGui::PopStyleColor();
		}
		if (Answer) {
			SetActiveLayer(i);
		}*/
		
		if (i == m_ActiveLayer) {
			ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.0f, 0.409f, 1.0f, 1.0f));
		}
		else {
			ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.137f, 0.263f, 0.424f, 1.0f));
		}
		ImGui::PushStyleVar(ImGuiStyleVar_CellPadding, ImVec2(10.0f, 10.0f));
		ImGui::BeginChild(m_Layers[i]->GetName().c_str(), ImVec2(ImGui::GetWindowWidth(), 50.0f));

		ImGui::SetCursorPos(ImVec2(5, 13));
		ImGui::Checkbox("", &m_Layers[i]->m_Visible);

		ImGui::SameLine();

		ImGui::SetCursorPosY(4);
		ImVec2 pos = ImGui::GetCursorScreenPos();
		ImGui::GetWindowDrawList()->AddImage(
			(void*)m_Layers[i]->GetTexture(),
			ImVec2(pos.x, pos.y),
			ImVec2(pos.x + 42.0f, pos.y + 42.0f),
			ImVec2(0, 1),
			ImVec2(1, 0)
		);

		ImGui::SameLine();

		ImGui::SetCursorPos(ImVec2(84.0f, 4));
		if (ImGui::Button(m_Layers[i]->GetName().c_str(), ImVec2(ImGui::GetWindowWidth() - 88.0f, 42.0f))) {
			SetActiveLayer(i);
		}

		ImGui::EndChild();
		ImGui::PopStyleVar();
		ImGui::PopStyleColor();
	}

	ImGui::End();
}