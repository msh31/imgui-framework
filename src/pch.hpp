#pragma once
#define IMGUI_DEFINE_MATH_OPERATORS
#define IMGUI_IMPL_OPENGL_LOADER_CUSTOM //use glad not their own loader

#ifdef __cplusplus
#include <print>
#include <filesystem>
#include <string>
#include <functional>
#include <vector>
#include <deque>
#include <future>
#include <stdexcept>
#include <memory>
#include <unordered_set>

#include "imgui.h"
#include "imgui_stdlib.h"

#include <spdlog/spdlog.h>
#include <backend/logger.hpp>  
#include <spdlog/sinks/daily_file_sink.h>

namespace fs = std::filesystem;
#endif

#include <KHR/khrplatform.h>
#include <glad/gl.h>
#include <GLFW/glfw3.h>

#ifdef __linux__
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#endif
