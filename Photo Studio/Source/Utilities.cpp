#include "Utilities.h"

#include <imgui/imgui.h>
#include <imgui/imgui_internal.h>
#include <imgui/backends/imgui_impl_sdl2.h>
#include <imgui/backends/imgui_impl_opengl2.h>

namespace glm
{
	glm::vec3 lerp(glm::vec3 x, glm::vec3 y, float t) {
		return x * (1.f - t) + y * t;
	}
}

namespace ImGui 
{
	void BeginPS(std::string Name, ImGuiWindowFlags Flags) {
		ImGuiWindowClass window_class;
		window_class.DockNodeFlagsOverrideSet = ImGuiDockNodeFlags_NoWindowMenuButton;
		ImGui::SetNextWindowClass(&window_class);

		ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 4.0f);

		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
		ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);

		//foinally, brexitium
		//ImGui::PushStyleColor(ImGuiCol_Tab, ImVec4(1.0f, 0.4f, 0.4f, 1.0f));

		ImGui::Begin(Name.c_str(), nullptr, Flags);
		//ImGui::PopStyleColor();

		ImVec2 LayerWinSize = ImGui::GetWindowSize();

		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, { 5,5 });
		ImGui::BeginChild((Name + " Child").c_str(), {LayerWinSize.x, LayerWinSize.y - 22}, ImGuiChildFlags_None, Flags);
		ImGui::PopStyleVar();
		LayerWinSize = ImGui::GetWindowSize();

		ImGui::PopStyleVar(3);
	}

	void EndPS() {
		ImGui::EndChild();

		ImGui::End();
	}
}