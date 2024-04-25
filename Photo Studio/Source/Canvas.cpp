#include "Canvas.h"

Canvas::Canvas(Tools& tools, std::string CanvasName, glm::vec2 Size)
    : m_CanvasShader(ShaderType::CANVAS_VS, ShaderType::CANVAS_FS),
    m_BackgroundShader(ShaderType::BACKGROUND_VS, ShaderType::BACKGROUND_FS),
    m_Viewport(nullptr, 100, 100),
    m_Background(nullptr, 100, 100),
    m_DrawBuffer(nullptr, 100,100),
    m_Tools(tools),
    m_CanvasSize(Size),
    m_CanvasName(CanvasName),
    m_PixelBuffer(GL_RGBA, Size.x, Size.y, 2)
{
    SetActive();

    m_Background.Bind();

    m_Background.Rescale(nullptr, m_CanvasSize.x, m_CanvasSize.y);
    glViewport(0, 0, m_CanvasSize.x, m_CanvasSize.y);
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    m_Background.Unbind();


    m_DrawBuffer.Bind();

    m_DrawBuffer.Rescale(nullptr, m_CanvasSize.x, m_CanvasSize.y);
    glViewport(0, 0, m_CanvasSize.x, m_CanvasSize.y);
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    m_DrawBuffer.Unbind();
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

    Input::Mouse::m_MouseInCanvas = MouseInCanvas();

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
        static ImVec2 OldWinSize = ImGui::GetWindowSize();
        ImVec2 WinSize = ImGui::GetWindowSize();
        if (!(OldWinSize.x == WinSize.x && OldWinSize.y == WinSize.y)) {
            m_Viewport.Rescale(nullptr, window_width, window_height);
        }
        OldWinSize = WinSize;
        glViewport(0, 0, window_width, window_height);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        m_BackgroundShader.UseProgram();
        m_BackgroundShader.Uniform<glm::mat4>("model", glm::scale(glm::translate(glm::mat4(1.0f), glm::vec3(window_width / 2.0f + CanvasData::m_CanvasOffset.x, window_height / 2.0f - CanvasData::m_CanvasOffset.y, -900.0f)), glm::vec3(m_CanvasSize.x, -m_CanvasSize.y, 0) * CanvasData::m_CanvasScale));
        m_BackgroundShader.Uniform<glm::mat4>("view", glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0)));
        m_BackgroundShader.Uniform<glm::mat4>("projection", glm::ortho(0.0f, (float)window_width, 0.0f, (float)window_height, 0.1f, 1000.0f));

        Primitive::m_CanvasObject->Draw();

        // https://stackoverflow.com/questions/14154704/how-to-avoid-transparency-overlap-using-opengl

        m_CanvasShader.UseProgram();
        m_CanvasShader.Uniform<glm::mat4>("model", glm::scale(glm::translate(glm::mat4(1.0f), glm::vec3(window_width / 2.0f + CanvasData::m_CanvasOffset.x, window_height / 2.0f - CanvasData::m_CanvasOffset.y, -800.0f)), glm::vec3(m_CanvasSize.x, -m_CanvasSize.y, 0) * CanvasData::m_CanvasScale));
        m_CanvasShader.Uniform<glm::mat4>("view", glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0)));
        m_CanvasShader.Uniform<glm::mat4>("projection", glm::ortho(0.0f, (float)window_width, 0.0f, (float)window_height, 0.1f, 1000.0f));

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
    m_Background.Bind();

    m_PixelBuffer.Download();

    glm::vec3 BrushPosition = GetCanvasMousePosition();
    if (m_Tools.m_Tool == Tool::Brush)
    {
        m_Tools.m_BrushMode = BrushMode::Pencil;
        m_Tools.DrawInterpolatedPaintbrush(BrushPosition);
    }
    else if (m_Tools.m_Tool == Tool::Eraser) 
    {
        m_Tools.m_BrushMode = BrushMode::Eraser;
        m_Tools.DrawInterpolatedPaintbrush(BrushPosition, m_Tools.GetEraserSize());
    }
    else if (m_Tools.m_Tool == Tool::PaintBucket) {
        m_Tools.FloodFill4Stack(m_Background, m_PixelBuffer, BrushPosition);
    }

    m_Background.Unbind();

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
                     mousePos.y - CanvasData::m_CanvasOffset.y - ViewportPos.y - (ViewportSize.y - m_CanvasSize.y * CanvasData::m_CanvasScale) / 2.0f + WindowPos.y, -1.0f) / glm::vec3(CanvasData::m_CanvasScale, CanvasData::m_CanvasScale, 1.0f);
}

bool Canvas::MouseInCanvas()
{
    ImVec2 winpos = ImGui::GetWindowPos();
    ImVec2 winsize = ImGui::GetContentRegionAvail();
    //std::cout << winpos.x << " " << winpos.y << "\n";

    int xpos, ypos;
    SDL_GetGlobalMouseState(&xpos, &ypos);
    glm::vec2 diff = { xpos - winpos.x, ypos - winpos.y };

    if (diff.x < 0 || diff.y < 0) {
        return false;
    }
    else if (diff.x > winsize.x || diff.y > winsize.y) {
        return false;
    }

    return true;
}