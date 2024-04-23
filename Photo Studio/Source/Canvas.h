#pragma once

#include "Framebuffer.h"
#include "Shader.h"
#include "CanvasObject.h"
#include "Tools/Tools.h"
#include "Input.h"
#include "Primitives.h"
#include "CanvasData.h"
#include "PixelBuffer.h"

#include <imgui/imgui.h>
#include <imgui/imgui_internal.h>
#include <imgui/backends/imgui_impl_sdl2.h>
#include <imgui/backends/imgui_impl_opengl2.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Canvas
{
public:
	Canvas(Tools& tools, std::string CanvasName, glm::vec2 Size);
	~Canvas();

	void SetActive();
	void DrawCanvas();
	bool MouseInCanvas();

	Tools& m_Tools;
	glm::vec2 m_CanvasSize;
	std::string m_CanvasName;
	Framebuffer m_Background;
	PixelBuffer m_PixelBuffer;
private:
	Shader m_CanvasShader;
	Shader m_BackgroundShader;
	Framebuffer m_Viewport;
	Framebuffer m_DrawBuffer;
	
	glm::vec3 GetCanvasMousePosition();
};

