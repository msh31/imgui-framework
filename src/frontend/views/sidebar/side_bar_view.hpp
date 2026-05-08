#pragma once
#include <frontend/views/base_view.hpp>

class SideBar : public BaseView {
    public:
        SideBar(std::function<void()> fun);
        ~SideBar() override; 
        void render(Config& cfg) override;
        void on_enter() override;
        void on_exit() override;
    private:
        std::function<void()> fun;
};
