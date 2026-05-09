#include "home_view.hpp"
#include <backend/utils.hpp>

void HomeView::on_enter() {
    Notify::show_notification("Introduction", std::format("Hello: {}", get_username().c_str()), 1500);
}

void HomeView::render(Config& cfg) {
    ImGui::Text("This is a the home view, you can add new views yourself by exploring the code. It's quite simple.");

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

    ImGui::ColorEdit4("Color Picker", color); //can be used in if statement

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
}

void HomeView::on_exit() {

}

HomeView::~HomeView() {
    SPDLOG_INFO("goodbye: homeview");
}
