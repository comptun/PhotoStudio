#pragma once

#include "Framebuffer.h"
#include "Shader.h"
#include "CanvasObject.h"
#include "Tools/Tools.h"
#include "Input.h"
#include "Primitives.h"
#include "CanvasData.h"

#include <imgui/imgui.h>
#include <imgui/imgui_internal.h>
#include <imgui/backends/imgui_impl_sdl2.h>
#include <imgui/backends/imgui_impl_opengl2.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <SDL2/SDL.h>

class Canvas : public Tools
{
public:
	Canvas(glm::vec2 Size);
	~Canvas();

	Tool GetTool();
	void SetTool(Tool tool);

	void DrawCanvas();
private:
	Shader m_CanvasShader;
	Shader m_BackgroundShader;
	Framebuffer m_Viewport;
	Framebuffer m_Background;
	glm::vec3 GetCanvasMousePosition();
};

