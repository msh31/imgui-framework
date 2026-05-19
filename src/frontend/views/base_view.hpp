#pragma once
#include <backend/config/config.hpp>

class CBaseView {
    public:
        virtual ~CBaseView();
        virtual void render(Config& cfg) = 0;
        virtual void on_enter();
        virtual void on_exit();

        struct ViewItem {
            const char* icon;
            const char* label;
            CBaseView* view;
        };
};
