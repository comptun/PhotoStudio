#pragma once

#include <imgui/imgui.h>
#include <imgui/imgui_internal.h>


class Eraser
{
public:
	Eraser();
	~Eraser();

	void DrawEraserMenu();

	float GetEraserSize();
private:
	float m_EraserSize;
};

