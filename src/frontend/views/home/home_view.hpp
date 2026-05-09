#pragma once
#include <frontend/views/base_view.hpp>

class HomeView : public BaseView {
    public:
        ~HomeView() override; 
        void render(Config& cfg) override;
        void on_enter() override;
        void on_exit() override;

    private:
        std::string input_str = {};
        double input_double = 0.0;
        float input_float = 0.0f;
        int input_int = 0;
        bool checkbox_toggle = false;

        std::vector<std::string> fruits = { "apple", "orange", "strawberry", "banana", "lemon" };
        std::string selected_fruit = fruits[0];

        float slider_step_f = 10.0f;
        float slider_min_f = 1.0f;
        float slider_max_f = 100.0f;

        int slider_step_i= 1;
        int slider_min_i = 1;
        int slider_max_i = 100;

        float color[4] = {1.f, 1.f, 1.f, 1.f};

        std::vector<std::string> meats = { "beef", "pork", "chicken", "fish" };
        std::string selected_meat = meats[0];

        bool radio_toggle = true;
};
