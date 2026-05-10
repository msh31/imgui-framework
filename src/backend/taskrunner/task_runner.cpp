#include "task_runner.hpp"

void TaskRunner::run(std::function<void()> work, std::function<void()> on_complete) {
    tasks.emplace_back(Task{std::async(std::launch::async, work), on_complete});
}

void TaskRunner::update() {
    std::erase_if(tasks, [](Task& t) {
        if(t.future.valid() && t.future.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            t.on_complete();
            return true;
        }
        return false;
    });
}
