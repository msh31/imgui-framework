#pragma once
#define IMGUI_DEFINE_MATH_OPERATORS
#define IMGUI_IMPL_OPENGL_LOADER_CUSTOM // use glad not their own loader

// Generic, stable C++/library headers belong here so you don't have to
// re-include common stdlib facilities in every file. Project headers that
// you edit often (backend/logger.hpp, types.hpp) do NOT belong here: any
// change to them would invalidate this precompiled header for every
// translation unit in the project, turning a one-file edit into a full
// rebuild. Include those directly in the .cpp/.hpp that needs them instead.
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

    #include "imgui.h"
    #include "imgui_stdlib.h"

namespace fs = std::filesystem;
#endif

// clang-format off
#include <glad/gl.h>
#include <KHR/khrplatform.h>
#include <GLFW/glfw3.h>
// clang-format on

#ifdef __linux__
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <unistd.h>
#endif
