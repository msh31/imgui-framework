#pragma once
#include <frontend/views/base_view.hpp>

class SettingsView : public CBaseView {
    public:
        SettingsView(Config& cfg);
        ~SettingsView() override; 
        void render() override;
        void on_enter() override;
        void on_exit() override;

    private:
        Config& m_config;
};
