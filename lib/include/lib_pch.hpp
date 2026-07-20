#pragma once

// Generic, stable C++ stdlib headers only - no imgui/GLFW/glad here. This is
// what keeps template_lib (and anything linking it, e.g. tests) usable
// without pulling in the GUI stack. src/pch.hpp includes this and layers the
// GUI-specific headers on top for template_app.
#ifdef __cplusplus
    #include <algorithm>
    #include <atomic>
    #include <chrono>
    #include <deque>
    #include <expected>
    #include <filesystem>
    #include <fstream>
    #include <functional>
    #include <future>
    #include <memory>
    #include <mutex>
    #include <print>
    #include <regex>
    #include <stdexcept>
    #include <string>
    #include <thread>
    #include <unordered_set>
    #include <vector>

namespace fs = std::filesystem;
#endif

#ifdef __linux__
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <unistd.h>
#endif
