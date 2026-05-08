#pragma once
#include <backend/config/config.hpp>
#include <backend/paths.hpp>

#include <frontend/views/home/home_view.hpp>
#include <frontend/views/settings/settings_view.hpp>
#include <frontend/views/sidebar/side_bar_view.hpp>

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
    bool open_settings = false;

    BaseView* active_view = nullptr;

    HomeView home_view;
    SettingsView settings_view;
    SideBar sidebar;
};
