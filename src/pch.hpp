#pragma once
#define IMGUI_DEFINE_MATH_OPERATORS
#define IMGUI_IMPL_OPENGL_LOADER_CUSTOM //use glad not their own loader

#ifdef __cplusplus
#include <print>
#include <filesystem>
#include <string>
#include <functional>
#include <vector>

#include "imgui.h"
#include "imgui_stdlib.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

namespace fs = std::filesystem;
#endif

#include <glad/glad.h>
#include <GLFW/glfw3.h>
