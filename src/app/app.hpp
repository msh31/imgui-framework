#pragma once
#include <backend/config/config.hpp>
#include <backend/paths.hpp>

#include <backend/view_manager/view_manager.hpp>
#include <backend/taskrunner/task_runner.hpp>

class CApp {
public:
    // CApp() {
    //
    // }
    // ~CApp();

    void init();
    void render();

    struct AppContext {
        Config* config;
    };

private:
    void setup_logger();

    Config config;
    AppContext ctx{&config};
    CViewManager view_manager;

    TaskRunner task_runner;
};
