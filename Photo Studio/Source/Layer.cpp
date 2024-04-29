#include "Layer.h"

Layer::Layer(std::string LayerName, uint64_t Index, uint64_t Width, uint64_t Height, glm::vec4 Color)
	: Framebuffer(nullptr, Width, Height),
	m_LayerName(LayerName)
{
    Bind();

    Rescale(nullptr, Width, Height);
    glViewport(0, 0, Width, Height);
    glClearColor(Color.r, Color.g, Color.b, Color.a);
    glClear(GL_COLOR_BUFFER_BIT);

    Unbind();
}
Layer::~Layer()
{

}