#include "Canvas.h"

Canvas::Canvas(Tools& tools, std::string CanvasName, glm::vec2 Size, int CanvasID)
    : 
    m_Viewport(nullptr, 100, 100),
    m_DrawBuffer(nullptr, 100, 100),
    m_Tools(tools),
    m_CanvasSize(Size),
    m_CanvasName(CanvasName),
    m_PixelBuffer(GL_RGBA, Size.x, Size.y, 2),
    m_DrawPixelBuffer(GL_RGBA, Size.x, Size.y, 2),
    m_Focused(false),
    m_CanvasID(CanvasID),
    m_OldWindowSize(0,0),
    m_Open(true),
    m_InitialDraw(true),
    LayerManager(m_CanvasSize)
{
    CanvasData::m_CanvasSize = m_CanvasSize;

    CanvasData::m_CanvasScale = Input::GetInitialScale();



    m_DrawBuffer.Bind();

    m_DrawBuffer.Rescale(nullptr, m_CanvasSize.x, m_CanvasSize.y);
    glViewport(0, 0, m_CanvasSize.x, m_CanvasSize.y);
    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    m_DrawBuffer.Unbind();

    uint64_t BackgroundLayer = AddLayer("Background", glm::vec4(1, 1, 1, 1), m_CanvasSize);
    SetActiveLayer(BackgroundLayer);
    
}
Canvas::~Canvas()
{

}

void Canvas::SetActive()
{
    CanvasData::m_CanvasSize = m_CanvasSize;

    const float window_width = ImGui::GetContentRegionAvail().x;
    const float window_height = ImGui::GetContentRegionAvail().y;

    CanvasData::m_ViewportSize = { window_width, window_height };

    CanvasData::m_CanvasScale = CanvasData::m_CanvasMultiplier * Input::GetInitialScale();
}

void Canvas::Render()
{
    DrawCanvas();
}

void Canvas::DrawCanvas()
{
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    ImGuiWindowClass window_class;
    window_class.DockNodeFlagsOverrideSet = ImGuiDockNodeFlags_NoCloseButton | ImGuiDockNodeFlags_NoWindowMenuButton;
    ImGui::SetNextWindowClass(&window_class);

    if (m_InitialDraw) {
        ImGui::SetNextWindowDockID(4);
        m_InitialDraw = false;
    }
    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
    ImGui::Begin(m_CanvasName.c_str(), &m_Open);
    ImGui::PopStyleVar(2);

    Input::Mouse::m_MouseInCanvas = MouseInCanvas();

    float window_width = ImGui::GetContentRegionAvail().x;
    float window_height = ImGui::GetContentRegionAvail().y;

    if (!CanvasData::m_CanvasHovered)
        CanvasData::m_CanvasHovered = ImGui::IsWindowHovered();

    if (ImGui::IsWindowHovered()) {
        ImGui::SetWindowFocus();
        CanvasData::m_CanvasFocused = true;
        SetActive();
    }
    else if (ImGui::IsWindowFocused()) {
        CanvasData::m_CanvasFocused = true;
        SetActive();
    }

    if (CanvasData::m_ActiveCanvas == m_CanvasID) {
        SetActive();
    }

    ImVec2 pos = ImGui::GetCursorScreenPos();

    ImGui::GetWindowDrawList()->AddImageRounded(
        (void*)m_Viewport.GetTexture(),
        ImVec2(pos.x, pos.y),
        ImVec2(pos.x + window_width, pos.y + window_height),
        ImVec2(0, 1),
        ImVec2(1, 0),
        0xFFFFFFFF,
        4.0f
    );

    m_Viewport.Bind();
    {
        if (!(m_OldWindowSize.x == window_width && m_OldWindowSize.y == window_height)) {
            m_Viewport.Rescale(nullptr, window_width, window_height);
        }
        m_OldWindowSize = glm::vec2(window_width, window_height);
        glViewport(0, 0, window_width, window_height);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


        Primitive::m_RectShader->UseProgram();
        Primitive::m_RectShader->Uniform<glm::mat4>("model", 
            glm::scale(glm::translate(glm::mat4(1.0f), 
                glm::vec3(window_width / 2.0f + CanvasData::m_CanvasOffset.x, window_height / 2.0f - CanvasData::m_CanvasOffset.y, 0.0f)
            ), glm::vec3(m_CanvasSize.x, -m_CanvasSize.y, 0) * CanvasData::m_CanvasScale)
        );
        Primitive::m_RectShader->Uniform<glm::mat4>("view", glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0)));
        Primitive::m_RectShader->Uniform<glm::mat4>("projection", glm::ortho(0.0f, (float)window_width, 0.0f, (float)window_height));
        Primitive::m_RectShader->Uniform<glm::vec4>("color", { 0.5f, 0.5f, 0.5f, 1.0f });

        Primitive::m_CanvasObject->Draw();



        Primitive::m_CanvasShader->UseProgram();
        Primitive::m_CanvasShader->Uniform<glm::mat4>("model",
            glm::scale(glm::translate(glm::mat4(1.0f),
                glm::vec3(window_width / 2.0f + CanvasData::m_CanvasOffset.x, window_height / 2.0f - CanvasData::m_CanvasOffset.y, 0.0f)
            ), glm::vec3(m_CanvasSize.x, -m_CanvasSize.y, 0) * CanvasData::m_CanvasScale)
        );

        Primitive::m_CanvasShader->Uniform<glm::mat4>("view", glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0)));
        Primitive::m_CanvasShader->Uniform<glm::mat4>("projection", glm::ortho(0.0f, (float)window_width, 0.0f, (float)window_height));

        glBindTexture(GL_TEXTURE_2D, m_DrawBuffer.GetTexture());
        Primitive::m_CanvasObject->Draw();
    }
    m_Viewport.Unbind();






    glViewport(0, 0, CanvasData::m_CanvasSize.x, CanvasData::m_CanvasSize.y);

    m_DrawBuffer.Bind();
    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    Primitive::m_CanvasShader->UseProgram();



    Primitive::m_CanvasShader->Uniform<glm::mat4>("view", glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0)));

    Primitive::m_CanvasShader->Uniform<glm::mat4>("projection", glm::ortho(0.0f, m_CanvasSize.x, 0.0f, m_CanvasSize.y));



    for (int i = 0; i < m_Layers.size(); ++i) {
        if (!m_Layers[i]->m_Visible) {
            continue;
        }

        Primitive::m_CanvasShader->Uniform<glm::mat4>("model",
            glm::scale(glm::translate(glm::mat4(1.0f),
                glm::vec3(m_CanvasSize.x / 2.0f + m_Layers[i]->m_LayerOffset.x, m_CanvasSize.y / 2.0f + m_Layers[i]->m_LayerOffset.y, 0.0f)
            ), glm::vec3(m_Layers[i]->m_Width, m_Layers[i]->m_Height, 0))
        );

        glBindTexture(GL_TEXTURE_2D, m_Layers[i]->GetTexture());
        Primitive::m_CanvasObject->Draw();
    }

    m_DrawPixelBuffer.Download();

    // Draw widgets

    m_Tools.DrawRectangularSelect();

    m_DrawBuffer.Unbind();





    if (!ImGui::IsWindowFocused()) {
        glUseProgram(0);
        ImGui::End();
        return;
    }

    if (CanvasData::m_ActiveCanvas != m_CanvasID) {
        CanvasData::m_ActiveCanvas = m_CanvasID;
        SetActive();
        m_Viewport.Rescale(nullptr, window_width, window_height);
    }


    glViewport(0, 0, CanvasData::m_CanvasSize.x, CanvasData::m_CanvasSize.y);
    BindActiveLayer();

    m_PixelBuffer.Download();

    glm::vec3 BrushPosition = GetCanvasMousePosition();
    if (m_Tools.m_Tool == Tool::Brush)
    {
        m_Tools.m_BrushMode = BrushMode::Pencil;
        m_Tools.DrawInterpolatedPaintbrush();
    }
    else if (m_Tools.m_Tool == Tool::Eraser)
    {
        m_Tools.m_BrushMode = BrushMode::Eraser;
        m_Tools.DrawInterpolatedPaintbrush(m_Tools.GetEraserSize());
    }
    else if (m_Tools.m_Tool == Tool::PaintBucket) {
        m_Tools.FloodFill4Stack(GetActiveLayer(), m_PixelBuffer);
    }
    else if (m_Tools.m_Tool == Tool::RectangularSelect) {
        m_Tools.RectangularSelectStep(GetActiveLayer());
    }
    else if (m_Tools.m_Tool == Tool::Move) {
        m_Tools.MoveLayer(GetActiveLayer());
    }

    UnbindActiveLayer();

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
    glm::vec3 FinalPos = glm::vec3(mousePos.x - CanvasData::m_CanvasOffset.x - ViewportPos.x - (ViewportSize.x - GetActiveLayer()->m_Width * CanvasData::m_CanvasScale) / 2.0f + WindowPos.x,
        mousePos.y - CanvasData::m_CanvasOffset.y - ViewportPos.y - (ViewportSize.y - GetActiveLayer()->m_Height * CanvasData::m_CanvasScale) / 2.0f + WindowPos.y, 0.0f) 
        / glm::vec3(CanvasData::m_CanvasScale, CanvasData::m_CanvasScale, 1.0f)
        - glm::vec3(GetActiveLayer()->m_LayerOffset.x, GetActiveLayer()->m_LayerOffset.y, 0.0f);
    Input::Mouse::CanvasPos = FinalPos;
    return FinalPos;
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

void Canvas::SaveAs()
{
    const uint32_t format = SDL_PIXELFORMAT_RGBA32;
    SDL_Surface* IMGSurface = SDL_CreateRGBSurfaceWithFormatFrom(m_DrawPixelBuffer.m_Pixels, m_CanvasSize.x, m_CanvasSize.y, 32, 4 * m_CanvasSize.x, format);

    if (IMGSurface == NULL) {
        std::cout << SDL_GetError();
    }

    std::string Path = "Images/" + m_CanvasName + ".png";

    IMG_SavePNG(IMGSurface, Path.c_str());

    SDL_FreeSurface(IMGSurface);
}