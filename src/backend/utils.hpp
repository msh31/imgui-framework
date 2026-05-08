#pragma once

inline std::string get_username() {
#if defined(__linux__) || defined(__APPLE__)
    return std::getenv("USER");
#elif
    return std::getenv("USERNAME");
#endif
}
