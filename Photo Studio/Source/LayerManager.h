#pragma once

#include <memory>
#include <vector>
#include <string>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <imgui/imgui.h>
#include <imgui/imgui_internal.h>
#include <imgui/backends/imgui_impl_sdl2.h>
#include <imgui/backends/imgui_impl_opengl2.h>

#include "Layer.h"
#include "Primitives.h"
#include "Input.h"
#include "WindowManager.h"
#include "Utilities.h"

class LayerManager
{
public:
	LayerManager(glm::vec2& CanvasSize);
	~LayerManager();

	void SetActiveLayer(uint64_t LayerID);
	uint64_t AddLayer();
	uint64_t AddLayer(glm::vec2 Size);
	uint64_t AddLayer(std::string LayerName);
	uint64_t AddLayer(std::string LayerName, glm::vec4 Color, glm::vec2 Size);
	void BindActiveLayer();
	void UnbindActiveLayer();
	void DrawLayers();
	void DrawLayersWindow();
	void DrawLayerPropertiesWindow();
	std::shared_ptr<Layer> GetActiveLayer();
	std::vector<std::shared_ptr<Layer>> m_Layers;
private:
	std::vector<bool> m_SelectedLayers;
	glm::vec2& m_CanvasSize;
	uint64_t m_ActiveLayer;
	glm::vec2 m_LayersWindowPos;
	int m_WindowYPos;
	float m_LayerOffset;
	float m_LayerYPos;
	bool m_InitialLayerClick;
	bool m_DraggingLayer;
	int m_TotalLayersAllTime;

	void NextLayerDraggable(int LayerIndex);
	void DrawLayer(int LayerIndex, bool Dragging=false, float Opacity=1.0f);
};