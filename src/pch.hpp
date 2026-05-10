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

#include "imgui.h"
#include "imgui_stdlib.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include <spdlog/spdlog.h>
#include <backend/logger.hpp>  
#include <spdlog/sinks/daily_file_sink.h>

//since all views need it and im lazy
#include <frontend/notification/notification.hpp>
#include <frontend/confirmdialog/confirm_dialog.hpp>

namespace fs = std::filesystem;
#endif

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#ifdef __linux__
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#endif
