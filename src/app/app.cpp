#include "app.hpp"

#include "backend/paths.hpp"
#include <constants.hpp>

#include <frontend/theme/theme.hpp>
#include <frontend/fonts/jbm_reg.h>
#include <frontend/fonts/font_awesome.hpp>

// CApp::CApp(fs::path config_dir) : config(config_dir), sidebar(this) {
//     sidebar.add_item({"\xef\x80\x95", "Home", &home_view});
//     sidebar.add_item({"\xef\x86\x88", "Debug", &debug_view});
// }
//
// void CApp::set_active_view(BaseView* view) {
//     if(!view || view == active_view) return;
//     if(active_view) active_view->on_exit();
//     active_view = view;
//     active_view->on_enter();
// }

void CApp::init() {
    if(!config.init()) {
        SPDLOG_ERROR("Config is missing and could not be generated!");
    }
    config.save();

    auto file_sink = std::make_shared<spdlog::sinks::daily_file_sink_mt>((paths::config_dir() / "app.log").string(), 0, 0);
    auto app_logger = std::make_shared<spdlog::logger>(APP_NAME, spdlog::sinks_init_list{file_sink});
    spdlog::set_default_logger(app_logger);
    spdlog::set_pattern("[%l] %d-%m-%Y %H:%M:%S - %v (in: %@)");

    // active_view = &home_view;
    // active_view->on_enter();
}

void CApp::render() {
    
}

// void CApp::render_ui() {
//     sidebar.render(config);
//     ImGui::SameLine();
//
//     ImGui::BeginChild("##maincontent", ImVec2(0, 0), ImGuiChildFlags_Borders);
//     active_view->render(config);
//     ImGui::EndChild();
//
//     if(open_settings) {
//         ImGui::OpenPopup("Settings");
//         open_settings = false;
//     }
//     settings_view.render(config);
// }
