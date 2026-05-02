#pragma once

class App {
public:
    ~App();

    void init();
    void render();

    GLFWwindow* window = nullptr;
private:
    bool setup_opengl();
    bool setup_imgui();

    void render_ui();
};
