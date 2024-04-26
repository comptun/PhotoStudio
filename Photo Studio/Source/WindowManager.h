#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <imgui/imgui.h>
#include <imgui/imgui_internal.h>
#include <imgui/backends/imgui_impl_sdl2.h>
#include <imgui/backends/imgui_impl_opengl2.h>

struct WindowData
{
	inline static glm::vec4 m_Color = {0,0,0,1};
};

class Windows
{
public:
	Windows();
	~Windows();

	void DrawColorWindow();
};

