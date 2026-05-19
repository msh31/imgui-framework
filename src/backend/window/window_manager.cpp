#include "window_manager.hpp"
#include <constants.hpp>

// #include <frontend/theme/theme.hpp>
#include <frontend/fonts/jbm_reg.h>
#include <frontend/fonts/font_awesome.hpp>

void CWindowManager::run(std::function<void()> fun) {
    do{
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGuiViewport* viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(viewport->Pos);
        ImGui::SetNextWindowSize(viewport->Size);
        //ImGui::SetNextWindowViewport(viewport->ID);

        ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoTitleBar |
            ImGuiWindowFlags_NoResize |
            ImGuiWindowFlags_NoMove |
            ImGuiWindowFlags_NoCollapse |
            ImGuiWindowFlags_NoBringToFrontOnFocus |
            ImGuiWindowFlags_NoNavFocus;

        ImGui::Begin("Main Window", nullptr, window_flags);
        fun();
        ImGui::End();
        ImGui::Render();

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(m_window);
        glfwWaitEventsTimeout(1.0/60.0);
    } while(
        glfwGetKey(m_window, GLFW_KEY_Q) != GLFW_PRESS &&
        glfwWindowShouldClose(m_window) == 0
     );
}

void CWindowManager::setup_opengl() {
    if(!glfwInit()) {
        SPDLOG_CRITICAL("Failed to initialize GLFW.");
        throw std::runtime_error("Failed to initialize GLFW");
    }

    glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing (MSAA)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // no old OpenGL

    m_window = glfwCreateWindow(DEF_RES_W, DEF_RES_H, APP_NAME, nullptr, nullptr);
    if(m_window == nullptr) {
        SPDLOG_CRITICAL("Failed to create GLFW window. OpenGL 3.3 support is required!");
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window, OpenGL 3.3 support is required");
    }

    glfwSetWindowSizeLimits(m_window, MIN_RES_W, MIN_RES_H, MAX_RES_W, MAX_RES_H); 
    glfwMakeContextCurrent(m_window);
    glfwSwapInterval(1);
    if (!gladLoadGL(glfwGetProcAddress)) {
        SPDLOG_CRITICAL("Failed to initialize GLAD");
        throw std::runtime_error("Failed to initialize GLAD");
    }
}

void CWindowManager::setup_imgui() {
    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.IniFilename = nullptr; //no imgui.ini
    io.LogFilename = nullptr; //no imgui log pls

    ImFontConfig font_cfg;
    font_cfg.FontDataOwnedByAtlas = false;

    ImFont* jbm = io.Fonts->AddFontFromMemoryTTF((void*)jbm_reg, jbm_reg_len, 16.0f, &font_cfg);
    font_cfg.MergeMode = true;
    font_cfg.GlyphMinAdvanceX = 16.0f;
    static const ImWchar icon_ranges[] = {0xf000, 0xf2e0, 0};
    io.Fonts->AddFontFromMemoryTTF((void*)font_awesome, font_awesome_len, 16.0f, &font_cfg, icon_ranges);
    io.FontDefault = jbm;

    if(!ImGui_ImplGlfw_InitForOpenGL(m_window, true)) {
        SPDLOG_CRITICAL("Failed to initialize ImGui for OpenGL");
        throw std::runtime_error("Failed to initialize ImGui for OpenGL");
    }
    if(!ImGui_ImplOpenGL3_Init()) {
        SPDLOG_CRITICAL("Failed to initialize ImGui");
        throw std::runtime_error("Failed to initialize ImGui");
    }
}
