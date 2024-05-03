#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <glad/glad.h>

#include <imgui/imgui.h>
#include <imgui/imgui_internal.h>
#include <imgui/backends/imgui_impl_sdl2.h>
#include <imgui/backends/imgui_impl_opengl2.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>
#include <memory>
#include <vector>
#include <thread>

#include "CanvasObject.h"
#include "Shader.h"
#include "Framebuffer.h"
#include "Canvas.h"
#include "Tools/Tools.h"
#include "Primitives.h"
#include "Windows.h"
#include "Input.h"

class Application : public Windows
{
public:
	Application();
	~Application();

	void Run();
	static void InitGL();
	void RenderUI();
private:
	SDL_Window* m_Window;
	inline static SDL_GLContext m_GLContext = nullptr;
	SDL_Event m_Event;
	std::vector<std::shared_ptr<Canvas>> m_Canvases;
	Tools m_Tools;
	bool m_Running;

	int m_Height, m_Width;

	void DrawTitleBar();

	void UpdateWindow();
	void InitImGui();
	void Render();
	void Cleanup();
};

