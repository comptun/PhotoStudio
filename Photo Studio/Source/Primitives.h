#pragma once

#include <CanvasObject.h>

#include <memory>
#include <vector>

struct Primitive
{
	inline static std::unique_ptr<CanvasObject> m_CanvasObject = nullptr;
	inline static std::unique_ptr<CanvasObject> m_BrushObject = nullptr;
	static void Init();
};

