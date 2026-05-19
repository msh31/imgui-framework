#pragma once
#include <frontend/views/base_view.hpp>

class SettingsView : public CBaseView {
    public:
        ~SettingsView() override; 
        void render() override;
        void on_enter() override;
        void on_exit() override;
};
