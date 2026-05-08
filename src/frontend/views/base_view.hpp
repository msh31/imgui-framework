#pragma once
#include <backend/config/config.hpp>

class BaseView {
    public:
        virtual ~BaseView();
        virtual void render(Config& cfg) = 0;
        virtual void on_enter();
        virtual void on_exit();
};
