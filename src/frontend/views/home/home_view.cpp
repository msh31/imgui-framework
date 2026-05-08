#include "home_view.hpp"
#include <constants.hpp>

void HomeView::on_enter() {

}

void HomeView::render(Config& cfg) {
    ImGui::Text(APP_NAME);
    ImGui::Separator();

    if(ImGui::Button("Click Me")) {
        std::println("Button 'Click Me' has heen clicked!");
    }
    ImGui::SameLine();
    ImGui::Checkbox("Dark Mode", &cfg.settings.dark_mode);

    ImGui::Separator();
    if(ImGui::Button("  \xef\x80\x81  Test Icon")) {
        std::println("Icon button clicked!");
    }
    ImGui::SameLine();
    ImGui::Text("\xef\x80\x88 \xef\x80\xad \xef\x83\xa9");

}

void HomeView::on_exit() {

}

HomeView::~HomeView() {
    std::println("goodbye: homeview");
}
