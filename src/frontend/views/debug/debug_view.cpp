#include "debug_view.hpp"
#include <frontend/notification/notification.hpp>
#include <frontend/components/confirmdialog/confirm_dialog.hpp>

void DebugView::on_enter() {

}

void DebugView::render() {
    task_runner.update(); //needs a refactor but fine for now

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

    if(ImGui::Button("Test confirm dialog")) {
        ConfirmDialog::show("Are you sure?", [this]{ Notify::show_notification("Test", "This is a test", 1000); });
    }

    if(ImGui::Button("Test async task")) {
        task_runner.run(
                []{ std::this_thread::sleep_for(std::chrono::seconds(2)); },
                []{ Notify::show_notification("Async", "Task complete!", 2000); }
                );
    }
}

void DebugView::on_exit() {

}

DebugView::~DebugView() {
    SPDLOG_INFO("goodbye: debugview");
}
