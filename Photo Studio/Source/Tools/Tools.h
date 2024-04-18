#pragma once

#include "Paintbrush.h"

enum class Tool
{
	None,
	Paintbrush,
	FillBucket,
};

class Tools : public Paintbrush
{
public:
	Tools();
protected:
	Tool m_Tool;
};