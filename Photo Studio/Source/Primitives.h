#pragma once

#include "CanvasObject.h"
#include "Shader.h"

#include <memory>
#include <vector>

struct Primitive
{
	inline static std::unique_ptr<CanvasObject> m_CanvasObject = nullptr;
	inline static std::unique_ptr<CanvasObject> m_BrushObject = nullptr;
	inline static std::unique_ptr<Shader> m_CanvasShader = nullptr;
	inline static std::unique_ptr<Shader> m_BackgroundShader = nullptr;
	static void Init();
};

