#pragma once

#include <CanvasObject.h>

#include <memory>
#include <vector>

struct Primitive
{
	inline static std::unique_ptr<CanvasObject> m_CanvasObject = nullptr;
	static void Init();
};

