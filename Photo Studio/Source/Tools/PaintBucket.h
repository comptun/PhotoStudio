#pragma once

#include <vector>

#include "PixelBuffer.h"
#include "Windows.h"
#include "Input.h"
#include "Framebuffer.h"
#include "CanvasData.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <algorithm>

class PaintBucket
{
public:
    void FloodFill4Stack(Framebuffer& FBuffer, PixelBuffer& PBuffer, glm::vec3 Pos);
};

