#pragma once
#include <frontend/components/component.hpp>
#include <frontend/views/base_view.hpp>

class CSideBar : public CComponent {
    public:
        CBaseView* render(CBaseView* active);
        void add_item(CBaseView::ViewItem item);

    private:
        bool nav_button(const char* icon, const char* label, bool active, float width);

        std::vector<CBaseView::ViewItem> m_items;
};
