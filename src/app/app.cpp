#include "app.hpp"

#include "backend/paths.hpp"
#include <constants.hpp>

#include <frontend/theme/theme.hpp>
#include <frontend/fonts/jbm_reg.h>
#include <frontend/fonts/font_awesome.hpp>

#include <frontend/views/home/home_view.hpp>
#include <frontend/views/pipeline/pipeline_demo.hpp> //demo!
#include <frontend/views/debug/debug_view.hpp>
#include <frontend/views/settings/settings_view.hpp>

#include <frontend/notification/notification.hpp>
#include <frontend/dialogs/confirm/confirm_dialog.hpp>

void CApp::init() {
    setup_logger();
    ThemeManager::apply_style();

    auto* home = m_view_manager.add_view({std::make_unique<CHomeView>(), "", "Home"});
    auto* demo = m_view_manager.add_view({std::make_unique<CPipelineView>(), "", "Pipeline Demo"});
    auto* debug = m_view_manager.add_view({std::make_unique<CDebugView>(), "", "Debug"});
    auto* settings = m_view_manager.add_view({std::make_unique<CSettingsView>(m_config), "", "Settings"});

    m_sidebar.add_item({"\xef\x80\x95", "Home", home});
    m_sidebar.add_item({"\xef\x83\xa8", "Pipeline Demo", demo});
    m_sidebar.add_item({"\xef\x86\x88", "Debug", debug});
    m_sidebar.set_settings_view(settings);
}

void CApp::render() {
    ThemeManager::apply_colors(m_config.settings.dark_mode ? ThemeType::Dark : ThemeType::Light);

    auto active_view = m_view_manager.get_active_view();
    if(active_view == nullptr) {
        throw std::runtime_error("Failed to get active view!");
    }

    auto sidebar_result = m_sidebar.render(active_view);
    if(sidebar_result != nullptr) m_view_manager.set_active_view(sidebar_result);
    ImGui::SameLine();
    ImGui::BeginChild("##maincontent", ImVec2(0, 0), ImGuiChildFlags_Borders);
    active_view->render();
    ImGui::EndChild();

    Notify::render_notifications();
    ConfirmDialog::render();
}

void CApp::setup_logger() {
    auto file_sink = std::make_shared<spdlog::sinks::daily_file_sink_mt>((paths::config_dir() / "app.log").string(), 0, 0);
    auto app_logger = std::make_shared<spdlog::logger>(APP_NAME, spdlog::sinks_init_list{file_sink});
    spdlog::set_default_logger(app_logger);
    spdlog::set_pattern("[%l] %d-%m-%Y %H:%M:%S - %v (in: %@)");
}
