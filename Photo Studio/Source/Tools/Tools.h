#pragma once

#include "Paintbrush.h"
#include "PaintBucket.h"

enum class Tool
{
	None,
	BrushTool,
	PaintBucket,
};

class Tools : 
	public Paintbrush,
	public PaintBucket
{
public:
	Tools();
	Tool m_Tool;
};