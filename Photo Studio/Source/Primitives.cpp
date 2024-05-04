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
    float baseFontSize = 13.0f; // 13.0f is the size of the default font. Change to the font size you use.
    float iconFontSize = 35.0f;
    
    ImGuiIO& io = ImGui::GetIO();
    // merge in icons from Font Awesome
    static const ImWchar icons_ranges[] = { ICON_MIN_MD, ICON_MAX_MD, 0 };
    ImFontConfig icons_config;
    icons_config.MergeMode = true;
    icons_config.PixelSnapH = true;
    icons_config.GlyphMinAdvanceX = iconFontSize;
    
    m_IconFont = io.Fonts->AddFontFromFileTTF("Fonts/" FONT_ICON_FILE_NAME_MD, iconFontSize, &icons_config, icons_ranges);
    // use FONT_ICON_FILE_NAME_FAR if you want regular instead of solid

    Primitive::m_BrushObject = std::make_unique<CanvasObject>(indices, brushverts);
    Primitive::m_CanvasObject = std::make_unique<CanvasObject>(indices, vertices);
    Primitive::m_CanvasShader = std::make_unique<Shader>(ShaderType::CANVAS_VS, ShaderType::CANVAS_FS);
    Primitive::m_BackgroundShader = std::make_unique<Shader>(ShaderType::BACKGROUND_VS, ShaderType::BACKGROUND_FS);
}