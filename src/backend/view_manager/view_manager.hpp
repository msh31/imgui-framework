#pragma once
#include <frontend/views/base_view.hpp>

class CViewManager {
    public:
        struct ViewConfig {
            std::unique_ptr<CBaseView> view;
            const char* icon;
            const char* label;
        };

        CBaseView* add_view(ViewConfig v_cfg);

        CBaseView* get_active_view() const { return m_active_view; }
        void set_active_view(CBaseView* view) {
            m_active_view = view;
        }
    private:
        CBaseView* m_active_view = nullptr;
        std::vector<std::unique_ptr<CBaseView>> m_registered_views;
};
