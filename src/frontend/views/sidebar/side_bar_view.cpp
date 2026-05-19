#include "side_bar_view.hpp"
#include <constants.hpp>

CSideBar::CSideBar(std::function<void(CBaseView*)> fun) {}

void CSideBar::add_item(CBaseView::ViewItem item) {
    m_items.push_back(item);
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
}
