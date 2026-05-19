#include "view_manager.hpp"
#include "frontend/views/base_view.hpp"

void CViewManager::render() {

}

CBaseView* CViewManager::add_view(ViewConfig v_cfg) {
    CBaseView* raw = v_cfg.view.get();
    m_registered_views.emplace_back(std::move(v_cfg.view));
    m_sidebar.add_item({v_cfg.icon, v_cfg.label, raw});
    return raw;
}
