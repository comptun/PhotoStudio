#pragma once

#include "Brush.h"
#include "PaintBucket.h"
#include "Eraser.h"
#include "RectangularSelect.h"

#include "IconsMaterialDesign.h"
#include "Primitives.h"

#include <imgui/imgui.h>
#include <imgui/imgui_internal.h>
#include <imgui/backends/imgui_impl_sdl2.h>
#include <imgui/backends/imgui_impl_opengl2.h>

enum class Tool
{
	NullTool,
	None,
	Brush,
	PaintBucket,
	Eraser,
	Eyedropper,
	Text,
	Crop,
	RectangularSelect,
	Move,
};

class Tools : 
	public Brush,
	public PaintBucket,
	public Eraser,
	public RectangularSelect
{
public:
	Tools();
	Tool m_Tool;
	void DrawToolPropertiesMenu();
	void DrawToolbar();
private:
	Tool m_HoveredTool;
	bool m_ToolHovered;
	uint64_t m_ToolIndex;
	void ToolButton(Tool SelectedTool, std::string ToolName, std::string Tooltip);
};