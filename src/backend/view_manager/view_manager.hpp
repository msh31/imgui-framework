#pragma once
#include <frontend/views/base_view.hpp>
#include <frontend/views/sidebar/side_bar_view.hpp>

class CViewManager {
    public:
        CViewManager() : m_sidebar([this](CBaseView* v) { set_active_view(v); }) {};
        ~CViewManager();

        struct ViewConfig {
            std::unique_ptr<CBaseView> view;
            const char* icon;
            const char* label;
        };

        void render();
        CBaseView* add_view(ViewConfig v_cfg);

        CBaseView* get_active_view() const { return m_active_view; }
        void set_active_view(CBaseView* view) {
            m_active_view = view;
        }
    private:
        CBaseView* m_active_view = nullptr;
        std::vector<std::unique_ptr<CBaseView>> m_registered_views;

//UI components
    CSideBar m_sidebar;
};
