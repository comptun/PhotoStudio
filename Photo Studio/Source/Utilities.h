#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <imgui/imgui.h>
#include <imgui/imgui_internal.h>
#include <imgui/backends/imgui_impl_sdl2.h>
#include <imgui/backends/imgui_impl_opengl2.h>

#include <string>

namespace glm
{
	glm::vec3 lerp(glm::vec3 x, glm::vec3 y, float t);
}

namespace ImGui
{
	void BeginPS(std::string Name, ImGuiWindowFlags Flags=ImGuiWindowFlags_None);

	void EndPS();
}