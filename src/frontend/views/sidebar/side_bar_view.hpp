#pragma once
#include <frontend/views/base_view.hpp>

//widget - to be moved
class CSideBar {
    public:
        explicit CSideBar(std::function<void(CBaseView*)> fun);
        void render(Config& cfg);

        void add_item(CBaseView::ViewItem item);

    private:
        std::vector<CBaseView::ViewItem> m_items;
};
