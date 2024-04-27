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
	Canvas(Tools& tools, std::string CanvasName, glm::vec2 Size, int CanvasID);
	~Canvas();

	void SetActive();
	void DrawCanvas();
	bool MouseInCanvas();

	Tools& m_Tools;
	PixelBuffer m_PixelBuffer;
	glm::vec2 m_CanvasSize;
	std::string m_CanvasName;
	Framebuffer m_Background;
private:
	Shader m_CanvasShader;
	Shader m_BackgroundShader;
	Framebuffer m_Viewport;
	Framebuffer m_DrawBuffer;

	int m_CanvasID;
	bool m_Focused;
	bool m_Open;
	bool m_InitialDraw;

	glm::vec2 m_OldWindowSize;
	
	glm::vec3 GetCanvasMousePosition();
};

