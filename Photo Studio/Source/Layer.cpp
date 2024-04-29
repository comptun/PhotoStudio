#include "Layer.h"

Layer::Layer(std::string LayerName, uint64_t Index, uint64_t Width, uint64_t Height)
	: Framebuffer(nullptr, Width, Height),
	m_LayerName(LayerName)
{
    Bind();

    Rescale(nullptr, Width, Height);
    glViewport(0, 0, Width, Height);
    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    Unbind();
}
Layer::~Layer()
{

}