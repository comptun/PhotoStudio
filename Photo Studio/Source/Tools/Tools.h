#pragma once

#include "Brush.h"
#include "PaintBucket.h"
#include "Eraser.h"

enum class Tool
{
	None,
	Brush,
	PaintBucket,
	Eraser,
};

class Tools : 
	public Brush,
	public PaintBucket,
	public Eraser
{
public:
	Tools();
	Tool m_Tool;

	void DrawToolPropertiesMenu();
	void DrawToolbar();
};