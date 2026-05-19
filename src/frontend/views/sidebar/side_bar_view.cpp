#include "side_bar_view.hpp"
#include <constants.hpp>

CSideBar::CSideBar(std::function<void(CBaseView*)> fun) {}

void CSideBar::add_item(ViewItem item) {
    m_items.push_back(item);
}

void CSideBar::on_enter() {

}

static bool nav_button(const char* icon, const char* label, bool active, float width) {
    ImGuiStyle& style = ImGui::GetStyle();
    if(active) {
        ImGui::PushStyleColor(ImGuiCol_Button, style.Colors[ImGuiCol_ButtonActive]);
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, style.Colors[ImGuiCol_ButtonActive]);
        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
    }
    ImGui::PushStyleVar(ImGuiStyleVar_ButtonTextAlign, ImVec2(0.0f, 0.5f));

    std::string text = std::format("  {}   {}##nav_{}", icon, label, label);
    bool clicked = ImGui::Button(text.c_str(), ImVec2(width, 0));

    ImGui::PopStyleVar();
    if(active) ImGui::PopStyleColor(3);
    return clicked;
}

void CSideBar::render(Config& cfg) {
    constexpr float SIDEBAR_W = 180.f;
    ImGui::BeginChild("##sidebar", {SIDEBAR_W, 0}, ImGuiChildFlags_Borders);

    ImGui::TextDisabled(APP_NAME);
    ImGui::Separator();
    ImGui::Spacing();

    // CBaseView* active = app->get_active_view();
    float content_w = ImGui::GetContentRegionAvail().x;
    for(auto& item : m_items) {
        // if(nav_button(item.icon, item.label, item.view == active, content_w)) {
        //     // app->set_active_view(item.view);
        // }
    }

    float btn_h = ImGui::GetFrameHeight();
    ImGui::SetCursorPosY(ImGui::GetWindowHeight() - btn_h - ImGui::GetStyle().WindowPadding.y);

    ImGui::PushStyleVar(ImGuiStyleVar_ButtonTextAlign, ImVec2(0.0f, 0.5f));
    if(ImGui::Button("  \xef\x80\x93   Settings", ImVec2(content_w, 0))) {
        // app->open_settings_popup();
    }
    ImGui::PopStyleVar();
    ImGui::EndChild();
}

void CSideBar::on_exit() {

}

CSideBar::~CSideBar() {
    SPDLOG_INFO("goodbye: sidebar");
}
