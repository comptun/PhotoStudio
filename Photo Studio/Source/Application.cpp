#include "Application.h"

int RedrawWindow(void* userdata, SDL_Event* ev) {
    if (ev->type == SDL_WINDOWEVENT) {
        if (ev->window.event == SDL_WINDOWEVENT_EXPOSED)
            reinterpret_cast<Application*>(userdata)->RenderUI();
    }
    return 0;
}

Application::Application()
    : m_Running(true)
{
    m_Window = SDL_GL_GetCurrentWindow();
    SDL_AddEventWatch(RedrawWindow, (void*)this);
    auto Canv = std::make_shared<Canvas>(m_Tools, "Example Canvas", glm::vec2(1000, 1000), m_Canvases.size());

    m_Canvases.push_back(std::move(Canv));
}
Application::~Application()
{

}

void Application::UpdateWindow()
{
    while (SDL_PollEvent(&m_Event))
    {
        ImGui_ImplSDL2_ProcessEvent(&m_Event);
        if (m_Event.type == SDL_QUIT)
            m_Running = false;
        else if (m_Event.type == SDL_WINDOWEVENT) {
            if (m_Event.window.event == SDL_WINDOWEVENT_CLOSE && m_Event.window.windowID == SDL_GetWindowID(m_Window)) {
                m_Running = false;
            }
            else if (m_Event.window.event == SDL_WINDOWEVENT_RESIZED) {
                SDL_GetWindowSize(m_Window, &m_Width, &m_Height);
            }
            /*else if (m_Event.window.event == SDL_WINDOWEVENT_EXPOSED) {
                std::cout << "test\n";
            }*/
        }
        else if (m_Event.type == SDL_MOUSEMOTION) {
            Input::ProcessMouseMotion(m_Event.motion);
        }
        else if (m_Event.type == SDL_MOUSEBUTTONUP || m_Event.type == SDL_MOUSEBUTTONDOWN) {
            Input::ProcessMouseButton(m_Event.button);
        }
        else if (m_Event.type == SDL_MOUSEWHEEL) {
            Input::ProcessMouseWheel(m_Event.wheel);
        }
    }
}

void Application::InitGL()
{
    // Setup SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER) != 0)
    {
        printf("Error: %s\n", SDL_GetError());
        return;
    }

    // From 2.0.18: Enable native IME.
#ifdef SDL_HINT_IME_SHOW_UI
    SDL_SetHint(SDL_HINT_IME_SHOW_UI, "1");
#endif

    /*SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);*/

    // Setup window
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
    //SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_DEBUG_FLAG);
    int window_flags = SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI;// | SDL_WINDOW_MAXIMIZED;
    SDL_Window* Window = SDL_CreateWindow("Photo Studio", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 900, (SDL_WindowFlags)window_flags);
    if (Window == nullptr)
    {
        printf("Error: SDL_CreateWindow(): %s\n", SDL_GetError());
        return;
    }

    m_GLContext = SDL_GL_CreateContext(Window);
    SDL_GL_MakeCurrent(Window, m_GLContext);
    gladLoadGLLoader(SDL_GL_GetProcAddress);
    printf("OpenGL loaded\n");
    printf("Vendor:   %s\n", glGetString(GL_VENDOR));
    printf("Renderer: %s\n", glGetString(GL_RENDERER));
    printf("Version:  %s\n", glGetString(GL_VERSION));

    SDL_GL_SetSwapInterval(1); // Enable vsync

    //glEnable(GL_DEPTH_TEST);

    glEnable(GL_BLEND);
    //glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ONE);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    //glDepthFunc(GL_LEQUAL);
}

static ImVec4 Color32(const ImVec4& Colors) {
    return ImVec4(Colors.x / 255.0f, Colors.y / 255.0f, Colors.z / 255.0f, Colors.w / 255.0f);
}

void Application::InitImGui()
{
    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // Enable Docking
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;       // Enable Multi-Viewport / Platform Windows
    //io.ConfigViewportsNoAutoMerge = true;
    //io.ConfigViewportsNoTaskBarIcon = true;

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsLight();

    // When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
    ImGuiStyle& style = ImGui::GetStyle();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        style.WindowRounding = 0.0f;
        style.Colors[ImGuiCol_WindowBg].w = 1.0f;
    }

    style.Colors[ImGuiCol_Tab] = { 0.1f, 0.1f, 0.1f, 1.0f };
    style.Colors[ImGuiCol_TabActive] = { 0.3f, 0.3f, 0.3f, 1.0f };
    style.Colors[ImGuiCol_TabHovered] = { 0.4f, 0.4f, 0.4f, 1.0f };
    style.Colors[ImGuiCol_TabUnfocused] = { 0.2f, 0.2f, 0.2f, 1.0f };
    style.Colors[ImGuiCol_TabUnfocusedActive] = { 0.3f, 0.3f, 0.3f, 1.0f };

    style.Colors[ImGuiCol_TitleBg] = Color32({ 16,16,16,255 });
    style.Colors[ImGuiCol_TitleBgActive] = Color32({ 16,16,16,255 });
    style.Colors[ImGuiCol_TitleBgCollapsed] = Color32({16,16,16,255});
    
    style.Colors[ImGuiCol_MenuBarBg] = Color32({ 24, 24, 24, 255 });
    style.Colors[ImGuiCol_WindowBg] = Color32({ 36, 36, 36, 255 });
    style.Colors[ImGuiCol_Button] = Color32({ 0,0,0,0 });
    style.Colors[ImGuiCol_ButtonHovered] = Color32({ 100,100,100,100 });
    style.Colors[ImGuiCol_ButtonActive] = Color32({ 150,150,150,100 });

    style.Colors[ImGuiCol_FrameBg] = Color32({ 100,100,100,255 });
    style.Colors[ImGuiCol_FrameBgActive] = Color32({ 120,120,120,255 });
    style.Colors[ImGuiCol_FrameBgHovered] = Color32({ 150,150,150,255 });
    style.Colors[ImGuiCol_CheckMark] = Color32({255,255,255,255});

    style.DockingSeparatorSize = 1.0f;
    style.WindowBorderSize = 0.0f;

    // Setup Platform/Renderer backends
    ImGui_ImplSDL2_InitForOpenGL(m_Window, m_GLContext);
    ImGui_ImplOpenGL2_Init();

    glDisable(GL_CULL_FACE);

    /*glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);*/

    ImFont* roboto = io.Fonts->AddFontFromFileTTF("Fonts/Roboto-Regular.ttf", 16.0f);
    //ImGui::PushFont(roboto);
}
void Application::Run()
{
    InitImGui();
    Primitive::Init();
	while (m_Running) {
		UpdateWindow();
		Render();
		RenderUI();
	}
    Cleanup();
}
void Application::Render()
{

}

void Application::RenderUI()
{
    // Start the Dear ImGui frame
    ImGui_ImplOpenGL2_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();

    ImGuiIO& io = ImGui::GetIO(); (void)io;

    //ImGui::ShowDemoWindow();
    
    ImGuiDockNodeFlags dockspace_flags = 0;// = ImGuiDockNodeFlags_NoUndocking;

    ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;

    const ImGuiViewport* viewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(viewport->WorkPos);
    ImGui::SetNextWindowSize(viewport->WorkSize);
    ImGui::SetNextWindowViewport(viewport->ID);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));


    ImGui::Begin("DockSpace Demo", nullptr, window_flags);

    ImGui::PopStyleVar(3);

    ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
    ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);

    DrawTitleBar();


    m_Tools.DrawToolPropertiesMenu();

    m_Tools.DrawToolbar();

    CanvasData::m_CanvasFocused = false;
    CanvasData::m_CanvasHovered = false;
    for (int i = 0; i < m_Canvases.size(); ++i) {
        m_Canvases[i]->DrawCanvas();
    }
    
    {
        DrawColorWindow();

        ImGuiWindowClass window_class;
        window_class.DockNodeFlagsOverrideSet = ImGuiDockNodeFlags_NoWindowMenuButton;
        ImGui::SetNextWindowClass(&window_class);

        ImGui::Begin("Properties");

        ImGui::End();

        m_Canvases.at(CanvasData::m_ActiveCanvas)->DrawLayersWindow();
        /*ImGui::Begin("Layers");
        ImGui::End();*/
    }

    ImGui::End();



    // Rendering
    ImGui::Render();


    ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());

    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        SDL_Window* backup_current_window = SDL_GL_GetCurrentWindow();
        SDL_GLContext backup_current_context = SDL_GL_GetCurrentContext();
        ImGui::UpdatePlatformWindows();
        ImGui::RenderPlatformWindowsDefault();
        SDL_GL_MakeCurrent(backup_current_window, backup_current_context);
    }

    SDL_GL_SwapWindow(m_Window);
}

void Application::DrawTitleBar()
{
    ImGuiWindowClass window_class;
    window_class.DockNodeFlagsOverrideSet = ImGuiDockNodeFlags_NoTabBar | ImGuiDockNodeFlags_NoResize;
    
    ImGui::SetNextWindowClass(&window_class);

    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0, 10));
    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
    ImGui::Begin("Title Bar", nullptr, ImGuiWindowFlags_MenuBar);

    bool CreateNewProject = false;
    bool SaveProject = false;
    bool ResetView = false;
    bool CreateNewLayer = false;

    if (ImGui::BeginMenuBar()) {
        ImGui::PopStyleVar(2);

        //ImGui::SetCursorPosX(5);

        ImGui::Text(" Photo Studio ");

        ImGui::PushStyleColor(ImGuiCol_HeaderHovered, ImVec4(0.4, 0.4, 0.4, 0.5));
        ImGui::PushStyleColor(ImGuiCol_Header, ImVec4(0.3, 0.3, 0.3, 0.5));

        ImGui::PushStyleVar(ImGuiStyleVar_PopupRounding, 10.0f);

        /*ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(10, 20));
        if (ImGui::BeginMenu("Photo Studio"))
        {
            ImGui::PopStyleVar();
            ImGui::MenuItem("About", "", nullptr, true);
            ImGui::EndMenu();
        }
        else {
            ImGui::PopStyleVar();
        }*/


        ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(10, 20));
        if (ImGui::BeginMenu("File"))
        {
            ImGui::PopStyleVar();

            ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(9, 9));
            
            ImGui::MenuItem("New project", "Ctrl+N", &CreateNewProject, true);
            ImGui::MenuItem("Save", "Ctrl+S", &SaveProject, true);
            ImGui::MenuItem("Save as", "Shift+Ctrl+S", nullptr, true);

            ImGui::PopStyleVar();

            ImGui::EndMenu();
        }
        else {
            ImGui::PopStyleVar();
        }

        ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(10, 20));
        if (ImGui::BeginMenu("Edit"))
        {
            ImGui::PopStyleVar();

            ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(9, 9));

            ImGui::MenuItem("Undo", "Ctrl+Z", nullptr, true);
            ImGui::MenuItem("Redo", "Ctrl+Shift+Z", nullptr, true);

            ImGui::PopStyleVar();

            ImGui::EndMenu();
        }
        else {
            ImGui::PopStyleVar();
        }

        ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(10, 20));
        if (ImGui::BeginMenu("Image"))
        {
            ImGui::PopStyleVar();

            ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(9, 9));

            ImGui::PopStyleVar();

            ImGui::EndMenu();
        }
        else {
            ImGui::PopStyleVar();
        }

        ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(10, 20));
        if (ImGui::BeginMenu("Layer"))
        {
            ImGui::PopStyleVar();

            ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(9, 9));


            ImGui::MenuItem("New layer", "Ctrl+L", &CreateNewLayer, true);


            ImGui::PopStyleVar();

            ImGui::EndMenu();
        }
        else {
            ImGui::PopStyleVar();
        }

        ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(10, 20));
        if (ImGui::BeginMenu("Type"))
        {
            ImGui::PopStyleVar();

            ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(9, 9));

            ImGui::PopStyleVar();

            ImGui::EndMenu();
        }
        else {
            ImGui::PopStyleVar();
        }

        ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(10, 20));
        if (ImGui::BeginMenu("Select"))
        {
            ImGui::PopStyleVar();

            ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(9, 9));

            ImGui::PopStyleVar();

            ImGui::EndMenu();
        }
        else {
            ImGui::PopStyleVar();
        }

        ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(10, 20));
        if (ImGui::BeginMenu("Filter"))
        {
            ImGui::PopStyleVar();

            ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(9, 9));

            ImGui::PopStyleVar();

            ImGui::EndMenu();
        }
        else {
            ImGui::PopStyleVar();
        }

        ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(10, 20));
        if (ImGui::BeginMenu("View"))
        {
            ImGui::PopStyleVar();

            ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(9, 9));

            ImGui::MenuItem("Reset view", "Ctrl+Shift+R", &ResetView, true);

            ImGui::PopStyleVar();

            ImGui::EndMenu();
        }
        else {
            ImGui::PopStyleVar();
        }

        ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(10, 20));
        if (ImGui::BeginMenu("Window"))
        {
            ImGui::PopStyleVar();

            ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(9, 9));

            ImGui::PopStyleVar();

            ImGui::EndMenu();
        }
        else {
            ImGui::PopStyleVar();
        }

        ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(10, 20));
        if (ImGui::BeginMenu("Help"))
        {
            ImGui::PopStyleVar();

            ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(9, 9));

            ImGui::PopStyleVar();

            ImGui::EndMenu();
        }
        else {
            ImGui::PopStyleVar();
        }


        ImGui::PopStyleColor(2);
        
        // ImGuiStyleVar_PopupRounding
        ImGui::PopStyleVar();
        // ImGuiStyleVar_FramePadding
        ImGui::PopStyleVar();

        ImGui::EndMenuBar();
    }
    ImGui::End();

    if (CreateNewProject) {
        static int ProjNumber = 1;
        auto Canv = std::make_shared<Canvas>(m_Tools, "New Canvas " + std::to_string(ProjNumber), glm::vec2(1000, 750), m_Canvases.size());

        m_Canvases.push_back(std::move(Canv));

        ProjNumber += 1;
    }

    if (SaveProject) {
        m_Canvases.at(CanvasData::m_ActiveCanvas)->SaveAs();
    }

    if (ResetView) {
        CanvasData::m_CanvasMultiplier = 1.0f;
        CanvasData::m_CanvasScale = Input::GetInitialScale();
        CanvasData::m_CanvasOffset = { 0.0f, 0.0f };
    }

    if (CreateNewLayer) {
        m_Canvases.at(CanvasData::m_ActiveCanvas)->AddLayer();
    }
}

void Application::Cleanup()
{
    ImGui_ImplOpenGL2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    SDL_GL_DeleteContext(m_GLContext);
    SDL_DestroyWindow(m_Window);
    SDL_Quit();
}