#include "sidebar.hpp"
#include <backend/font_manager/font_manager.hpp>
#include <constants.hpp>
#include <frontend/icons.hpp>

CBaseView* CSideBar::render( CBaseView* active ) {
    float width = collapsed ? 50.0f : 340.f;

    ImGui::BeginChild( "##sidebar", { width, 0 }, ImGuiChildFlags_Borders );
    float      content_w = ImGui::GetContentRegionAvail( ).x;
    float      btn_h     = ImGui::GetFrameHeight( );
    CBaseView* r_item    = nullptr;

    if ( !collapsed ) {
        ImGui::PushFont( CFontManager::get( ).get_font( "jbm_reg_xl" ).value_or( nullptr ) );
        ImGui::TextDisabled( "%s", APP_NAME.c_str( ) );
        ImGui::PopFont( );
        ImGui::SameLine( );
        ImGui::SetCursorPosX( 29.0f * 10.f );
        ImGui::PushID( "uncollapsed_button" );
        if ( ImGui::Button( ICON_MENU ) ) {
            collapsed = !collapsed;
        }
        ImGui::PopID( );
        ImGui::Separator( );
        ImGui::Spacing( );
    }

    if ( collapsed ) {
        ImGui::PushID( "collapsed_button" );
        if ( ImGui::Button( ICON_MENU ) ) {
            collapsed = !collapsed;
        }
        ImGui::PopID( );
    }

    for ( const auto& item : m_items ) {
        r_item = item.view;
        break;
    }

    ImGui::EndChild( );
    return r_item;
}

void CSideBar::add_item( CBaseView::ViewItem item ) { m_items.push_back( item ); }

void CSideBar::set_settings_view( CBaseView* view ) { m_settings = view; }

bool CSideBar::nav_button( const char* icon, const char* label, bool active, float width ) {
    ImGuiStyle& style = ImGui::GetStyle( );

    if ( active ) {
        ImGui::PushStyleColor( ImGuiCol_Button, style.Colors[ImGuiCol_ButtonActive] );
        ImGui::PushStyleColor( ImGuiCol_ButtonHovered, style.Colors[ImGuiCol_ButtonActive] );
        ImGui::PushStyleColor( ImGuiCol_Text, ImVec4( 1.0f, 1.0f, 1.0f, 1.0f ) );
    }
    ImGui::PushStyleVar( ImGuiStyleVar_ButtonTextAlign, ImVec2( 0.0f, 0.5f ) );

    std::string text    = std::format( "  {}   {}##nav_{}", icon, label, label );
    bool        clicked = ImGui::Button( text.c_str( ), ImVec2( width, 0 ) );

    ImGui::PopStyleVar( );
    if ( active ) ImGui::PopStyleColor( 3 );
    return clicked;
}
