#pragma once
#include <backend/paths.hpp>

class Config {
public:
    Config(fs::path config_dir = paths::config_dir());
    ~Config();
    void save();

    struct AppConfig {
        bool dark_mode = true;
    };

    AppConfig settings;
private:
    fs::path config_file = paths::config_dir() / "config.json";

    void load();
};
