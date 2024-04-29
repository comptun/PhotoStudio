#include "Primitives.h"

#include <cmath>

std::vector<float> vertices = {
     0.5f,  0.5f, 0.0f, // top right
     0.5f, -0.5f, 0.0f, // bottom right
    -0.5f, -0.5f, 0.0f, // bottom left
    -0.5f,  0.5f, 0.0f,   // top left 
};
std::vector<unsigned int> indices = {  // note that we start from 0!
    0, 1, 3,   // first triangle
    1, 2, 3    // second triangle
};



std::vector<float> brushverts = {
    1.0f,  1.0f, 0.0f, // top right
     1.0f, -1.0f, 0.0f, // bottom right
    -1.0f, -1.0f, 0.0f, // bottom left
    -1.0f,  1.0f, 0.0f,   // top left 
};


void Primitive::Init()
{
    Primitive::m_BrushObject = std::make_unique<CanvasObject>(indices, brushverts);
    Primitive::m_CanvasObject = std::make_unique<CanvasObject>(indices, vertices);
    Primitive::m_CanvasShader = std::make_unique<Shader>(ShaderType::CANVAS_VS, ShaderType::CANVAS_FS);
    Primitive::m_BackgroundShader = std::make_unique<Shader>(ShaderType::BACKGROUND_VS, ShaderType::BACKGROUND_FS);
}