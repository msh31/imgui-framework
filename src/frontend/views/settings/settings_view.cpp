#include "settings_view.hpp"

void SettingsView::on_enter() {

}

void SettingsView::render(Config& cfg) {
    ImVec2 center = ImGui::GetMainViewport()->GetCenter();
    ImGui::SetNextWindowPos(center, ImGuiCond_Always, {0.5f, 0.5f});
    ImGui::SetNextWindowSize({400, 200});
    bool open_popup = true;

    if(ImGui::BeginPopupModal("Settings", &open_popup, ImGuiWindowFlags_NoResize)) {
        ImGui::Checkbox("Dark Mode", &cfg.settings.dark_mode);
        ImGui::EndPopup();
    }
}

void SettingsView::on_exit() {

}

SettingsView::~SettingsView() {
    std::println("goodbye: settingsview");
}
