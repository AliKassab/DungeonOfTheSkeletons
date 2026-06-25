// AssetManager.h
// Centralises ownership of textures and fonts. Resources are loaded lazily on first
// request and cached by filename, replacing the ~60 scattered global Tex/Font objects
// of the original. unordered_map gives node-stable addresses, so the Tex* a Sprite
// holds stays valid for the lifetime of the manager.

#pragma once

#include "compat/sfml_compat.h"
#include <string>
#include <unordered_map>

class AssetManager {
    std::unordered_map<std::string, Tex> textures_;
    std::unordered_map<std::string, GameFont> fonts_;

public:
    Tex& texture(const std::string& file) {
        auto it = textures_.find(file);
        if (it != textures_.end()) return it->second;
        Tex& t = textures_[file];
        t.loadFromFile(file);
        return t;
    }

    GameFont& font(const std::string& file) {
        auto it = fonts_.find(file);
        if (it != fonts_.end()) return it->second;
        GameFont& f = fonts_[file];
        f.loadFromFile(file);
        return f;
    }

    // Force-(re)load a texture into an existing key (used for the ending sprite swap).
    Tex& reload(const std::string& key, const std::string& file) {
        Tex& t = textures_[key];
        t.loadFromFile(file);
        return t;
    }
};
