#include "app.hpp"
#include <constants.hpp>

#include <frontend/theme/theme.hpp>

App::App(fs::path config_dir) : config(config_dir) {}

void App::init() {
    if(!setup_opengl()) return;
    if(!setup_imgui()) return;

    if(!config.init()) {
        std::println("Config is missing and could not be generated!");
    }
    config.save();
}

void App::render_ui() {
    ImGui::Text(APP_NAME);
    ImGui::Separator();

    if(ImGui::Button("Click Me")) {
        std::print("Button 'Click Me' has heen clicked!");
    }
    ImGui::SameLine();
    ImGui::Checkbox("Dark Mode", &config.settings.dark_mode);
}

bool App::setup_opengl() {
    if(!glfwInit()) {
        std::print("Failed to initialize GLFW.");
        return false;
    }

    glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing (MSAA)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // no old OpenGL

    window = glfwCreateWindow(DEF_RES_W, DEF_RES_H, APP_NAME, nullptr, nullptr);
    if(window == nullptr) {
        std::print("Failed to create GLFW window. OpenGL 3.3 support is required!");
        glfwTerminate();
        return false;
    }

    glfwSetWindowSizeLimits(window, MIN_RES_W, MIN_RES_H, MAX_RES_W, MAX_RES_H); 
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::println("Failed to initialize GLAD");
        return false;
    }

    return true;
}

//could be improved
bool App::setup_imgui() {
    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init();

    return true;
}

void App::render() {
    glClear(GL_COLOR_BUFFER_BIT);
    ThemeManager::apply_theme(config.settings.dark_mode ? ThemeType::Dark : ThemeType::Light);

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
    App::render_ui();
    ImGui::End();
    ImGui::Render();

    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    glfwSwapBuffers(window);
    glfwPollEvents();
}

App::~App() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();
}
