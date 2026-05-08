#pragma once
#include <frontend/views/base_view.hpp>

class HomeView : public BaseView {
    public:
        ~HomeView() override; 
        void render(Config& cfg) override;
        void on_enter() override;
        void on_exit() override;
};
