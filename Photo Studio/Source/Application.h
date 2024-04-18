#pragma once

#include <SDL2/SDL.h>

#include <glad/glad.h>

#include <imgui/imgui.h>
#include <imgui/imgui_internal.h>
#include <imgui/backends/imgui_impl_sdl2.h>
#include <imgui/backends/imgui_impl_opengl2.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>
#include <memory>

#include "CanvasObject.h"
#include "Shader.h"
#include "Framebuffer.h"
#include "Canvas.h"
#include "Tools/Tools.h"

class Application
{
public:
	Application();
	~Application();

	void Run();
	static void InitGL();
private:
	SDL_Window* m_Window;
	inline static SDL_GLContext m_GLContext = nullptr;
	SDL_Event m_Event;
	Canvas m_Canvas;
	Tool m_Tool;
	bool m_Running;

	int m_Height, m_Width;

	void UpdateWindow();
	void InitImGui();
	void Render();
	void RenderUI();
	void Cleanup();

	void ProcessMouseMotion(const SDL_MouseMotionEvent& MotionEvent);
	void ProcessMouseButton(const SDL_MouseButtonEvent& ButtonEvent);
	void ProcessMouseWheel(const SDL_MouseWheelEvent& WheelEvent);
};

