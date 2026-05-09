#include "debug_view.hpp"
#include <frontend/notification/notification.hpp>

void DebugView::on_enter() {

}

void DebugView::render(Config& cfg) {
    if(ImGui::Button("Click Me")) {
        std::println("Button 'Click Me' has heen clicked!");
    }
    ImGui::Separator();
    if(ImGui::Button("  \xef\x80\x81  Test Icon")) {
        std::println("Icon button clicked!");
    }
    ImGui::SameLine();
    ImGui::Text("\xef\x80\x88 \xef\x80\xad \xef\x83\xa9");

    if(ImGui::Button("Test Notification")) {
        Notify::show_notification("I am a title", "I am the body", 2000);
    }
}

void DebugView::on_exit() {

}

DebugView::~DebugView() {
    SPDLOG_INFO("goodbye: debugview");
}
