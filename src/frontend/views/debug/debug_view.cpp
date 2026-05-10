#include "debug_view.hpp"
#include <frontend/notification/notification.hpp>

void DebugView::on_enter() {

}

void DebugView::render(Config& cfg) {
    if(ImGui::Button("Click Me")) {
        Notify::show_notification("", "Click Me button has been clicked!", 2000);
    }
    ImGui::Separator();
    if(ImGui::Button("  \xef\x80\x81  Test Icon")) {
        Notify::show_notification("", "Icon button has been clicked!", 2000);
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
