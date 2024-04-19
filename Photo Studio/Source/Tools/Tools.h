#pragma once

#include "Paintbrush.h"

enum class Tool
{
	None,
	Paintbrush,
	PaintBucket,
};

class Tools : public Paintbrush
{
public:
	Tools();
	Tool m_Tool;
};