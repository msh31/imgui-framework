#pragma once
#include <frontend/views/base_view.hpp>
#include <backend/taskrunner/task_runner.hpp>

class CDebugView : public CBaseView {
    public:
        ~CDebugView() override; 
        void render() override;
        void on_enter() override;
        void on_exit() override;

    private:
        CTaskRunner m_task_runner;
};
