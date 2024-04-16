#pragma once

#include <SDL2/SDL.h>

#include <glad/glad.h>

#include <imgui/imgui.h>
#include <imgui/imgui_internal.h>
#include <imgui/backends/imgui_impl_sdl2.h>
#include <imgui/backends/imgui_impl_opengl2.h>

#include <iostream>
#include <memory>

#include "CanvasObject.h"
#include "Shader.h"
#include "Framebuffer.h"

class Application
{
public:
	Application();
	~Application();

	void Run();
private:
	SDL_Window* m_Window;
	SDL_GLContext m_GLContext;
	SDL_Event m_Event;
	std::unique_ptr<CanvasObject> Canvas;
	std::unique_ptr<Shader> CanvasShader;
	std::unique_ptr<Framebuffer> Viewport;
	bool m_Running;

	void UpdateWindow();
	void Init();
	void Render();
	void RenderUI();
	void Cleanup();
};

