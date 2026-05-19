#include "app.hpp"

#include "backend/paths.hpp"
#include <constants.hpp>

#include <frontend/theme/theme.hpp>
#include <frontend/fonts/jbm_reg.h>
#include <frontend/fonts/font_awesome.hpp>

void CApp::init() {
    if(!config.init()) {
        SPDLOG_ERROR("Config is missing and could not be generated!");
    }
    config.save();

    auto file_sink = std::make_shared<spdlog::sinks::daily_file_sink_mt>((paths::config_dir() / "app.log").string(), 0, 0);
    auto app_logger = std::make_shared<spdlog::logger>(APP_NAME, spdlog::sinks_init_list{file_sink});
    spdlog::set_default_logger(app_logger);
    spdlog::set_pattern("[%l] %d-%m-%Y %H:%M:%S - %v (in: %@)");
}

void CApp::render() {
    
}
