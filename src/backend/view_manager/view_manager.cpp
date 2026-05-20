#include "view_manager.hpp"
#include "frontend/views/base_view.hpp"

CBaseView *CViewManager::add_view( ViewConfig v_cfg ) {
    if ( m_active_view == nullptr ) set_active_view( v_cfg.view.get( ) );

    CBaseView *raw = v_cfg.view.get( );
    m_registered_views.emplace_back( std::move( v_cfg.view ) );
    return raw;
}
