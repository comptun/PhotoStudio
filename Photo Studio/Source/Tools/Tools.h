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
protected:
	Tool m_Tool;
};