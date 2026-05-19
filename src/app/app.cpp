#include "app.hpp"

#include "backend/paths.hpp"
#include <constants.hpp>

#include <frontend/theme/theme.hpp>
#include <frontend/fonts/jbm_reg.h>
#include <frontend/fonts/font_awesome.hpp>

#include <frontend/views/home/home_view.hpp>
#include <frontend/views/debug/debug_view.hpp>

void CApp::init() {
    if(!m_config.init()) {
        SPDLOG_ERROR("Config is missing and could not be generated!");
    }
    m_config.save();

    setup_logger();

    m_view_manager.add_view({std::make_unique<HomeView>(), "", "Home"});
    m_view_manager.add_view({std::make_unique<DebugView>(), "", "Debug"});
}

void CApp::render() {
    // sidebar.render(config);
    ImGui::SameLine();

    auto active_view = m_view_manager.get_active_view();
    if(active_view == nullptr) {
        throw std::runtime_error("Failed to get active view!");
    }
    active_view->render();
}

void CApp::setup_logger() {
    auto file_sink = std::make_shared<spdlog::sinks::daily_file_sink_mt>((paths::config_dir() / "app.log").string(), 0, 0);
    auto app_logger = std::make_shared<spdlog::logger>(APP_NAME, spdlog::sinks_init_list{file_sink});
    spdlog::set_default_logger(app_logger);
    spdlog::set_pattern("[%l] %d-%m-%Y %H:%M:%S - %v (in: %@)");
}
