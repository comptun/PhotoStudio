#include "Canvas.h"

Canvas::Canvas(Tools& tools, std::string CanvasName, glm::vec2 Size)
    : m_CanvasShader(ShaderType::CANVAS_VS, ShaderType::CANVAS_FS),
    m_BackgroundShader(ShaderType::BRUSH_VS, ShaderType::BRUSH_FS),
    m_Viewport(100, 100),
    m_Background(100, 100),
    m_Tools(tools),
    m_CanvasSize(Size),
    m_CanvasName(CanvasName)
{
    SetActive();

    m_Background.Bind();

    m_Background.Rescale(m_CanvasSize.x, m_CanvasSize.y);
    glViewport(0, 0, m_CanvasSize.x, m_CanvasSize.y);
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    m_Background.Unbind();
}
Canvas::~Canvas()
{

}

void Canvas::SetActive()
{
    CanvasData::m_CanvasSize = m_CanvasSize;

    //ImGui::SetWindowFocus(m_CanvasName.c_str());
}

void Canvas::DrawCanvas()
{
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
    ImGui::Begin(m_CanvasName.c_str());
    ImGui::PopStyleVar();

    CanvasData::m_CanvasFocused = ImGui::IsWindowFocused();

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
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


        /*m_BackgroundShader.UseProgram();
        m_BackgroundShader.Uniform<glm::mat4>("model", glm::scale(glm::translate(glm::mat4(1.0f), glm::vec3(window_width / 2.0f, window_height / 2.0f, 0)), glm::vec3(m_CanvasSize.x, m_CanvasSize.y, 0)));
        m_BackgroundShader.Uniform<glm::mat4>("view", glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0)));
        m_BackgroundShader.Uniform<glm::mat4>("projection", glm::ortho(0.0f, (float)window_width, 0.0f, (float)window_height));
        m_BackgroundShader.Uniform<glm::vec4>("Color", { 1.0f,1.0f,1.0f,1.0f });

        Primitive::m_CanvasObject->Draw();*/


        m_CanvasShader.UseProgram();
        m_CanvasShader.Uniform<glm::mat4>("model", glm::scale(glm::translate(glm::mat4(1.0f), glm::vec3(window_width / 2.0f + CanvasData::m_CanvasOffset.x, window_height / 2.0f - CanvasData::m_CanvasOffset.y, 0)), glm::vec3(m_CanvasSize.x, -m_CanvasSize.y, 0) * CanvasData::m_CanvasScale));
        m_CanvasShader.Uniform<glm::mat4>("view", glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0)));
        m_CanvasShader.Uniform<glm::mat4>("projection", glm::ortho(0.0f, (float)window_width, 0.0f, (float)window_height));

        glBindTexture(GL_TEXTURE_2D, m_Background.GetTexture());
        Primitive::m_CanvasObject->Draw();
    }
    m_Viewport.Unbind();

    if (!CanvasData::m_CanvasFocused) {
        glUseProgram(0);
        ImGui::End();
        return;
    }

    glViewport(0, 0, CanvasData::m_CanvasSize.x, CanvasData::m_CanvasSize.y);

    glm::vec3 BrushPosition = GetCanvasMousePosition();
    if (m_Tools.m_Tool == Tool::BrushTool)
    {
        m_Background.Bind();
        m_Tools.DrawInterpolatedPaintbrush(BrushPosition);
        m_Background.Unbind();
    }

    glUseProgram(0);

    

    ImGui::End();
}

glm::vec3 Canvas::GetCanvasMousePosition()
{
    glm::vec2 ViewportPos = { ImGui::GetWindowPos().x, ImGui::GetWindowPos().y };
    glm::vec2 ViewportSize = { ImGui::GetWindowSize().x, ImGui::GetWindowSize().y };
    glm::vec2 mousePos = Input::Mouse::Pos;
    glm::vec<2, int> WindowPos = { 0,0 };
    SDL_GetWindowPosition(SDL_GL_GetCurrentWindow(), &WindowPos.x, &WindowPos.y);
    return glm::vec3(mousePos.x - CanvasData::m_CanvasOffset.x - ViewportPos.x - (ViewportSize.x - m_CanvasSize.x * CanvasData::m_CanvasScale) / 2.0f + WindowPos.x,
                     mousePos.y - CanvasData::m_CanvasOffset.y - ViewportPos.y - (ViewportSize.y - m_CanvasSize.y * CanvasData::m_CanvasScale) / 2.0f + WindowPos.y, 0) / CanvasData::m_CanvasScale;
}