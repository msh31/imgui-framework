#pragma once
#include <backend/config/config.hpp>
#include <backend/paths.hpp>

#include <backend/view_manager/view_manager.hpp>
#include <backend/taskrunner/task_runner.hpp>

#include <frontend/components/sidebar/sidebar.hpp>

class CApp {
public:
    void init();
    void render();

    struct AppContext {
        CConfig* config;
    };

private:
    void setup_logger();

    CConfig m_config;
    AppContext m_ctx{&m_config};
    CViewManager m_view_manager;

    CTaskRunner m_task_runner;

    CSideBar m_sidebar;
};
