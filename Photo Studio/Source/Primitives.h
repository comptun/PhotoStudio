#pragma once

#include <imgui/imgui.h>
#include <imgui/imgui_internal.h>
#include <imgui/backends/imgui_impl_sdl2.h>
#include <imgui/backends/imgui_impl_opengl2.h>

#include "CanvasObject.h"
#include "Shader.h"
#include "IconsMaterialDesign.h"

#include <memory>
#include <vector>

struct Primitive
{
	inline static std::unique_ptr<CanvasObject> m_CanvasObject = nullptr;
	inline static std::unique_ptr<CanvasObject> m_BrushObject = nullptr;
	inline static std::unique_ptr<Shader> m_CanvasShader = nullptr;
	inline static std::unique_ptr<Shader> m_RectShader = nullptr;
	inline static ImFont* m_IconFont = nullptr;
	static void Init();
};

