#pragma once
#include "backend/config/config.hpp"
#include <backend/paths.hpp>

class App {
public:
    App(fs::path config_dir = paths::config_dir());
    ~App();

    void init();
    void render();

    GLFWwindow* window = nullptr;
private:
    bool setup_opengl();
    bool setup_imgui();

    void render_ui();

    Config config;
};
