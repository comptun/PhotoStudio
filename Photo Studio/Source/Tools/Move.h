#pragma once

#include <memory>

#include <glm/glm.hpp>

#include "Layer.h"
#include "Input.h"
#include "CanvasData.h"

class Move
{
public:
	Move();
	~Move();

	void MoveLayer(std::shared_ptr<Layer> ActiveLayer);
};

