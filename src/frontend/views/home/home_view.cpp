#include "home_view.hpp"
#include <backend/utils.hpp>

void HomeView::on_enter() {

}

void HomeView::render(Config& cfg) {
    ImGui::Text("Welcome, %s!", get_username().c_str());
}

void HomeView::on_exit() {

}

HomeView::~HomeView() {
    std::println("goodbye: homeview");
}
