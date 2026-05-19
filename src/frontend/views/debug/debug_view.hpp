#pragma once
#include <frontend/views/base_view.hpp>
#include <backend/taskrunner/task_runner.hpp>

class DebugView : public CBaseView {
    public:
        ~DebugView() override; 
        void render() override;
        void on_enter() override;
        void on_exit() override;

    private:
        TaskRunner task_runner;
};
