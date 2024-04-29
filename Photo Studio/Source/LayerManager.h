#pragma once

#include <memory>
#include <vector>
#include <string>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Layer.h"

class LayerManager
{
public:
	LayerManager(glm::vec2& CanvasSize);
	~LayerManager();

	void SetActiveLayer(uint64_t LayerID);
	uint64_t AddLayer(std::string LayerName);
	void BindActiveLayer();
	void UnbindActiveLayer();
	void DrawLayers();
	std::shared_ptr<Layer> GetActiveLayer();

private:
	glm::vec2& m_CanvasSize;
	uint64_t m_ActiveLayer;
protected:
	std::vector<std::shared_ptr<Layer>> m_Layers;
};