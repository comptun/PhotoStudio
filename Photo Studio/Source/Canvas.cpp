#include "Canvas.h"

Canvas::Canvas(glm::vec2 Size)
    : m_CanvasShader(ShaderType::CANVAS_VS, ShaderType::CANVAS_FS),
    m_BackgroundShader(ShaderType::BRUSH_VS, ShaderType::BRUSH_FS),
    m_Viewport(100,100),
    m_Background(100,100),
    Tools()
{
    CanvasData::m_CanvasSize = Size;

    m_Background.Bind();

    m_Background.Rescale(CanvasData::m_CanvasSize.x, CanvasData::m_CanvasSize.y);
    glViewport(0, 0, CanvasData::m_CanvasSize.x, CanvasData::m_CanvasSize.y);
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    m_Background.Unbind();
}
Canvas::~Canvas()
{

}

void Canvas::DrawCanvas()
{
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
    ImGui::Begin("Viewport");
    ImGui::PopStyleVar();

    const float window_width = ImGui::GetContentRegionAvail().x;
    const float window_height = ImGui::GetContentRegionAvail().y;

    ImVec2 pos = ImGui::GetCursorScreenPos();

    ImGui::GetWindowDrawList()->AddImage(
        (void*)m_Viewport.GetTexture(),
        ImVec2(pos.x, pos.y),
        ImVec2(pos.x + window_width, pos.y + window_height),
        ImVec2(0, 1),
        ImVec2(1, 0)
    );



    m_Viewport.Bind();
    {
        m_Viewport.Rescale(window_width, window_height);
        glViewport(0, 0, window_width, window_height);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


        m_BackgroundShader.UseProgram();
        m_BackgroundShader.Uniform<glm::mat4>("model", glm::scale(glm::translate(glm::mat4(1.0f), glm::vec3(window_width / 2.0f, window_height / 2.0f, 0)), glm::vec3(CanvasData::m_CanvasSize.x, CanvasData::m_CanvasSize.y, 0)));
        m_BackgroundShader.Uniform<glm::mat4>("view", glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0)));
        m_BackgroundShader.Uniform<glm::mat4>("projection", glm::ortho(0.0f, (float)window_width, 0.0f, (float)window_height));
        m_BackgroundShader.Uniform<glm::vec4>("Color", { 1.0f,1.0f,1.0f,1.0f });

        Primitive::m_CanvasObject->Draw();


        m_CanvasShader.UseProgram();
        m_CanvasShader.Uniform<glm::mat4>("model", glm::scale(glm::translate(glm::mat4(1.0f), glm::vec3(window_width / 2.0f, window_height / 2.0f, 0)), glm::vec3(CanvasData::m_CanvasSize.x, -CanvasData::m_CanvasSize.y, 0)));
        m_CanvasShader.Uniform<glm::mat4>("view", glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0)));
        m_CanvasShader.Uniform<glm::mat4>("projection", glm::ortho(0.0f, (float)window_width, 0.0f, (float)window_height));

        glBindTexture(GL_TEXTURE_2D, m_Background.GetTexture());
        Primitive::m_CanvasObject->Draw();
    }
    m_Viewport.Unbind();

    glm::vec3 BrushPosition = GetCanvasMousePosition();
    if (m_Tool == Tool::Paintbrush)
    {
        m_Background.Bind();
        DrawInterpolatedPaintbrush(BrushPosition);
        m_Background.Unbind();
    }

    glUseProgram(0);

    

    ImGui::End();
}

Tool Canvas::GetTool()
{
    return m_Tool;
}
void Canvas::SetTool(Tool tool)
{
    m_Tool = tool;
}

glm::vec3 Canvas::GetCanvasMousePosition()
{
    glm::vec2 ViewportPos = { ImGui::GetWindowPos().x, ImGui::GetWindowPos().y };
    glm::vec2 ViewportSize = { ImGui::GetWindowSize().x, ImGui::GetWindowSize().y };
    glm::vec2 mousePos = Input::Mouse::Pos;
    glm::vec<2, int> WindowPos = { 0,0 };
    SDL_GetWindowPosition(SDL_GL_GetCurrentWindow(), &WindowPos.x, &WindowPos.y);
    return glm::vec3(mousePos.x - ViewportPos.x - (ViewportSize.x - CanvasData::m_CanvasSize.x) / 2.0f + WindowPos.x, mousePos.y - ViewportPos.y - (ViewportSize.y - CanvasData::m_CanvasSize.y) / 2.0f + WindowPos.y, 0);
}