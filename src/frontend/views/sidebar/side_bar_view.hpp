#pragma once
#include <frontend/views/base_view.hpp>

class App;

class SideBar : public BaseView {
    public:
        struct Item {
            const char* icon;
            const char* label;
            BaseView* view;
        };

        explicit SideBar(App* app);
        ~SideBar() override;
        void render(Config& cfg) override;
        void on_enter() override;
        void on_exit() override;

        void add_item(Item item);

    private:
        App* app;
        std::vector<Item> items;
};
