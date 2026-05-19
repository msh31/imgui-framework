#pragma once

class CFontManager {
    public:
        void load_from_memory(std::string font_name, float font_size, void* data);
        // void load_from_disk(std::string font_name, float font_size, fs::path path);

        ImFont* get(std::string font_name);

    private:
        std::unordered_map<std::string, ImFont*> m_fonts;
};
