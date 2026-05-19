#pragma once
#include <backend/config/config.hpp>
#include <backend/paths.hpp>

#include <backend/taskrunner/task_runner.hpp>

class CApp {
public:
    // CApp(fs::path config_dir = paths::config_dir());
    // ~CApp();

    void init();
    void render();

private:
    Config config;
    TaskRunner task_runner;
};
