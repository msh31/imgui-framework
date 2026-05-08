#include "side_bar_view.hpp"

SideBar::SideBar(std::function<void()> fun) : fun(fun) {};

void SideBar::on_enter() {

}

void SideBar::render(Config& cfg) {
    ImGui::BeginChild("##sidebar", {100, 0});

    ImGui::Text("FUCK");
    float button_height = ImGui::GetFrameHeight();
    ImGui::SetCursorPosY(ImGui::GetWindowHeight() - button_height - ImGui::GetStyle().WindowPadding.y);

    if(ImGui::Button("\xef\x80\x93")) {
        fun();
    }

    ImGui::EndChild();
}

void SideBar::on_exit() {

}

SideBar::~SideBar() {
    std::println("goodbye: sidebar");
}
