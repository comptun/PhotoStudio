#pragma once

#include "Brush.h"
#include "PaintBucket.h"
#include "Eraser.h"
#include "IconsMaterialDesign.h"
#include "Primitives.h"

#include <imgui/imgui.h>
#include <imgui/imgui_internal.h>
#include <imgui/backends/imgui_impl_sdl2.h>
#include <imgui/backends/imgui_impl_opengl2.h>

enum class Tool
{
	None,
	Brush,
	PaintBucket,
	Eraser,
};

class Tools : 
	public Brush,
	public PaintBucket,
	public Eraser
{
public:
	Tools();
	Tool m_Tool;
	void DrawToolPropertiesMenu();
	void DrawToolbar();
};