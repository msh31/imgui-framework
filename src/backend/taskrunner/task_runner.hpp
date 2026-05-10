#pragma once

class TaskRunner {
    public:
        void run(std::function<void()> work, std::function<void()> on_complete);
        void update();

    private:
        struct Task {
            std::future<void> future;
            std::function<void()> on_complete;
        };

        std::vector<Task> tasks;
};
