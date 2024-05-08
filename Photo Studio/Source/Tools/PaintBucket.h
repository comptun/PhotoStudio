#pragma once

#include <vector>

#include "PixelBuffer.h"
#include "WindowManager.h"
#include "Input.h"
#include "Framebuffer.h"
#include "CanvasData.h"
#include "Layer.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <algorithm>
#include <memory>

class PaintBucket
{
public:
    PaintBucket();
    ~PaintBucket();

    void FloodFill4Stack(std::shared_ptr<Layer> Layer, PixelBuffer& PBuffer);
};

