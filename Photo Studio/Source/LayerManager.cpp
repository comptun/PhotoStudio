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