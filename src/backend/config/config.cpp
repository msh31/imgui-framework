/*
 *  COPIED FROM SAVEMANAGER -> https://git.marco007.dev/marco/SaveManager/src/branch/main/src/backend/config
 *  AND MODIFIED FOR THIS APP
 */

#include "config.hpp"
#include <nlohmann/json.hpp>
#include <fstream>

using json = nlohmann::json;

Config::Config(fs::path config_dir) : config_file(config_dir / "config.json") {
    try {
        if(!fs::exists(config_dir)) {
            if(!fs::create_directories(config_dir)) {
                SPDLOG_CRITICAL("Failed to create config directory");
            }
        }

        if(!fs::exists(paths::cache_dir())) {
            if(!fs::create_directories(paths::cache_dir())) {
                SPDLOG_WARN("Failed to create cache directory");
            }
        }

        load();
    } catch (const std::exception& err) {
        SPDLOG_CRITICAL("config constructor: {}", err.what());
    }
}

Config::~Config() {
    try {
        save();
    } catch (const std::exception& err) {
        SPDLOG_CRITICAL("config destructor: {}", err.what());
    }
}

bool Config::init() {
    //placeholder
    return true;
}

void Config::save() {
    json data;
    data["dark_mode"] = settings.dark_mode;

    std::ofstream file(config_file);
    file << data.dump(4);
}

void Config::load() {
    json data;

    if(!fs::exists(config_file)) {
        save();
    }

    std::ifstream file(config_file.c_str());
    if(!file.is_open()) {
        SPDLOG_ERROR("Failed to open config!");
        return;
    }

    try {
        data = json::parse(file);
        settings.dark_mode = data.value("dark_mode", true);
    } catch(json::exception& ex) { SPDLOG_CRITICAL("config parsing error: {}", ex.what()); }
}
