#include "Application.h"

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

Application::Application()
    : m_Running(true)
{

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
        }
    }
}

float BackgroundWidth = 1000, BackgroundHeight = 750;

void Application::Init()
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

    // Setup window
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
    SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
    m_Window = SDL_CreateWindow("Photo Studio", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, window_flags);
    if (m_Window == nullptr)
    {
        printf("Error: SDL_CreateWindow(): %s\n", SDL_GetError());
        return;
    }

    m_GLContext = SDL_GL_CreateContext(m_Window);
    SDL_GL_MakeCurrent(m_Window, m_GLContext);
    gladLoadGLLoader(SDL_GL_GetProcAddress);
    printf("OpenGL loaded\n");
    printf("Vendor:   %s\n", glGetString(GL_VENDOR));
    printf("Renderer: %s\n", glGetString(GL_RENDERER));
    printf("Version:  %s\n", glGetString(GL_VERSION));

    SDL_GL_SetSwapInterval(1); // Enable vsync

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

    // Setup Platform/Renderer backends
    ImGui_ImplSDL2_InitForOpenGL(m_Window, m_GLContext);
    ImGui_ImplOpenGL2_Init();

    glDisable(GL_CULL_FACE);

    ImFont* roboto = io.Fonts->AddFontFromFileTTF("Fonts/Roboto-Regular.ttf", 16.0f);
    //ImGui::PushFont(roboto);

    m_CanvasObject = std::make_unique<CanvasObject>(indices, vertices);
    CanvasShader = std::make_unique<Shader>(ShaderType::CANVAS_VS, ShaderType::CANVAS_FS);
    BrushShader = std::make_unique<Shader>(ShaderType::BRUSH_VS, ShaderType::BRUSH_FS);
    Viewport = std::make_unique<Framebuffer>(100, 100);
    Background = std::make_unique<Framebuffer>(BackgroundWidth, BackgroundHeight);

    Background->Bind();

    Background->Rescale(BackgroundWidth, BackgroundHeight);
    glViewport(0, 0, BackgroundWidth, BackgroundHeight);
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    Background->Unbind();
}
void Application::Run()
{
	Init();
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

    //ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());



    bool show_demo_window = true;
    bool show_another_window = false;
    ImVec4 clear_color = ImVec4(0.0f, 0.0f, 0.0f, 1.00f);

    bool open = true;

    ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_NoUndocking;


    ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;

    const ImGuiViewport* viewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(viewport->WorkPos);
    ImGui::SetNextWindowSize(viewport->WorkSize);
    ImGui::SetNextWindowViewport(viewport->ID);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));


    ImGui::Begin("DockSpace Demo", &open, window_flags);

    ImGui::PopStyleVar(3);

    ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
    ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);

    ImGuiWindowClass window_class;
    window_class.DockNodeFlagsOverrideSet = ImGuiDockNodeFlags_NoTabBar | ImGuiDockNodeFlags_NoResize;
    ImGui::SetNextWindowClass(&window_class);

    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0, 10));
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
    ImGui::Begin("Title Bar", nullptr, ImGuiWindowFlags_MenuBar);
    
    if (ImGui::BeginMenuBar()) {
        ImGui::PopStyleVar();

        if (ImGui::BeginMenu("Photo Studio"))
        {
            ImGui::MenuItem("About", "", nullptr, true);
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("File"))
        {
            ImGui::MenuItem("New project", "", nullptr, true);
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Edit"))
        {
            ImGui::MenuItem("Undo\tCtrl+Z", "", nullptr, true);
            ImGui::MenuItem("Redo\tCtrl+Shift+Z", "", nullptr, true);
            ImGui::EndMenu();
        }

        ImGui::PopStyleVar();

        ImGui::EndMenuBar();
    }
    ImGui::End();


    {
        ImGui::Begin("Toolbar");
        ImGui::Text("This is the toolbar");
        ImGui::End();
    }


    {
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
        ImGui::Begin("Viewport");
        ImGui::PopStyleVar();

        const float window_width = ImGui::GetContentRegionAvail().x;
        const float window_height = ImGui::GetContentRegionAvail().y;

        ImVec2 pos = ImGui::GetCursorScreenPos();

        ImGui::GetWindowDrawList()->AddImage(
            (void*)Viewport->GetTexture(),
            ImVec2(pos.x, pos.y),
            ImVec2(pos.x + window_width, pos.y + window_height),
            ImVec2(0, 1),
            ImVec2(1, 0)
        );



        Viewport->Bind();

        Viewport->Rescale(window_width, window_height);
        glViewport(0, 0, window_width, window_height);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


        BrushShader->UseProgram();
        BrushShader->Uniform<glm::mat4>("model", glm::scale(glm::translate(glm::mat4(1.0f), glm::vec3(window_width / 2.0f, window_height / 2.0f, 0)), glm::vec3(BackgroundWidth, BackgroundHeight, 0)));
        BrushShader->Uniform<glm::mat4>("view", glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0)));
        CanvasShader->Uniform<glm::mat4>("projection", glm::ortho(0.0f, (float)window_width, 0.0f, (float)window_height));
        BrushShader->Uniform<glm::vec4>("Color", { 1.0f,1.0f,1.0f,1.0f });

        m_CanvasObject->Draw();


        CanvasShader->UseProgram();
        CanvasShader->Uniform<glm::mat4>("model", glm::scale(glm::translate(glm::mat4(1.0f), glm::vec3(window_width / 2.0f, window_height / 2.0f, 0)), glm::vec3(BackgroundWidth, -BackgroundHeight, 0)));
        CanvasShader->Uniform<glm::mat4>("view", glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0)));
        CanvasShader->Uniform<glm::mat4>("projection", glm::ortho(0.0f, (float)window_width, 0.0f, (float)window_height));
        
        glBindTexture(GL_TEXTURE_2D, Background->GetTexture());
        m_CanvasObject->Draw();

        Viewport->Unbind();

        Background->Bind();

        glViewport(0, 0, BackgroundWidth, BackgroundHeight);

        ImVec2 mousePos = io.MousePos;

        BrushShader->UseProgram();
        BrushShader->Uniform<glm::mat4>("model", glm::scale(glm::translate(glm::mat4(1.0f), glm::vec3(mousePos.x, mousePos.y, 0)), glm::vec3(20, 20, 0)));
        BrushShader->Uniform<glm::mat4>("view", glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0)));
        BrushShader->Uniform<glm::mat4>("projection", glm::ortho(0.0f, (float)BackgroundWidth, 0.0f, (float)BackgroundHeight));
        BrushShader->Uniform<glm::vec4>("Color", { 1.0f,0.0f,0.0f,1.0f });

        m_CanvasObject->Draw();

        Background->Unbind();

        glUseProgram(0);

        ImGui::End();
    }

    {
        ImGui::Begin("Properties");
        ImGui::Text("These are the properties");
        ImGui::End();
    }

    ImGui::End();



    // Rendering
    ImGui::Render();

    //Canvas->Draw();
    /*glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
    glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
    glClear(GL_COLOR_BUFFER_BIT);*/
    //glUseProgram(0); // You may want this if using this code in an OpenGL 3+ context where shaders may be bound

    ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());

    // Update and Render additional Platform Windows
    // (Platform functions may change the current OpenGL context, so we save/restore it to make it easier to paste this code elsewhere.
    //  For this specific demo app we could also call SDL_GL_MakeCurrent(window, gl_context) directly)
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

void Application::Cleanup()
{
    ImGui_ImplOpenGL2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    SDL_GL_DeleteContext(m_GLContext);
    SDL_DestroyWindow(m_Window);
    SDL_Quit();
}