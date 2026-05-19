#include "home_view.hpp"
#include <backend/utils.hpp>
#include <frontend/notification/notification.hpp>

void HomeView::on_enter() {
    Notify::show_notification("Introduction", std::format("Hello: {}", get_username().c_str()), 1500);
}

void HomeView::render() {
    ImGui::Text("This is a the home view, you can add new views yourself by exploring the code. It's quite simple.");

    if (ImGui::TreeNode("Inputs")) {
        ImGui::PushItemWidth(150.0f);
        ImGui::InputText("InputText", &input_str);
        ImGui::InputDouble("InputDouble", &input_double);
        ImGui::InputFloat("InputFloat", &input_float);
        ImGui::SameLine();
        ImGui::Dummy({20.0f, 5.0f});
        ImGui::SameLine();
        ImGui::SliderFloat("SliderFloat", &slider_step_f, slider_min_f, slider_max_f);
        ImGui::InputInt("InputInt", &input_int);
        ImGui::SameLine();
        ImGui::Dummy({20.0f, 5.0f});
        ImGui::SameLine();
        ImGui::SliderInt("SliderInt", &slider_step_i, slider_min_i, slider_max_i);
        ImGui::PopItemWidth();
        ImGui::TreePop();
    }

    if (ImGui::TreeNode("Selection")) {
        ImGui::Checkbox("Checkbox", &checkbox_toggle);

        ImGui::SetNextItemWidth(200.0f);
        if (ImGui::BeginCombo("Combo", selected_fruit.c_str())) {
            for (const auto& fruit : fruits) {
                if (ImGui::Selectable(fruit.c_str(), fruit == selected_fruit)) {
                    selected_fruit = fruit;
                }
            }
            ImGui::EndCombo();
        }

        ImGui::SetNextItemWidth(200.0f);
        if(ImGui::BeginListBox("Listbox")) {
            for (const auto& meat : meats) {
                if (ImGui::Selectable(meat.c_str(), meat == selected_meat)) {
                    selected_meat = meat;
                }
            }
            ImGui::EndListBox();
        }
        ImGui::SameLine();
        ImGui::Text("| Selected: %s", selected_meat.c_str());

        if(ImGui::RadioButton("RadioButton", radio_toggle)) {
            radio_toggle = !radio_toggle;
        }
        ImGui::SameLine();
        ImGui::Text("| Status: %b", radio_toggle);
        ImGui::TreePop();
    }

    if (ImGui::TreeNode("Color && Progress")) {
        ImGui::ColorEdit4("Color Picker", color);

        ImGui::ProgressBar(fmod(ImGui::GetTime() * 0.3f, 1.0f), {300.f, 0.f});
        ImGui::TreePop();
    }
}

void HomeView::on_exit() {

}

HomeView::~HomeView() {
    SPDLOG_INFO("goodbye: homeview");
}
