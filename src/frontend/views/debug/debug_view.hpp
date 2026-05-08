#pragma once
#include <frontend/views/base_view.hpp>

class DebugView : public BaseView {
    public:
        ~DebugView() override; 
        void render(Config& cfg) override;
        void on_enter() override;
        void on_exit() override;
};
