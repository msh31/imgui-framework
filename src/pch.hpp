#pragma once
#define IMGUI_DEFINE_MATH_OPERATORS
#define IMGUI_IMPL_OPENGL_LOADER_CUSTOM // use glad not their own loader

#ifdef __cplusplus
    #include <deque>
    #include <expected>
    #include <filesystem>
    #include <fstream>
    #include <functional>
    #include <future>
    #include <memory>
    #include <print>
    #include <regex>
    #include <stdexcept>
    #include <string>
    #include <unordered_set>
    #include <vector>

    #include "imgui.h"
    #include "imgui_stdlib.h"

    #include <backend/logger.hpp>
    #include <spdlog/sinks/daily_file_sink.h>
    #include <spdlog/spdlog.h>

    #include <types.hpp> //holds custom types defined by the application
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
