// sfml_compat.h
// A tiny SFML-flavoured compatibility layer over raylib.
//
// The original game was written against SFML 2.x. To keep the port faithful and
// mechanical, this header provides small classes that mirror the slice of the SFML
// API the game actually used (Sprite / Text / Font / Sound / Texture + Keyboard /
// Mouse), implemented on top of raylib.
//
// Names differ from SFML only where raylib already owns the identifier:
//   sf::Texture -> Tex,  sf::Font -> GameFont,  sf::Sound -> SoundFx
// (sf::Sprite/sf::Text keep their names; raylib has no such types.)
//
// The Sprite transform replicates SFML semantics exactly (origin defaults to the
// top-left corner; rotation pivots around the origin; getGlobalBounds() returns the
// axis-aligned bounding box of the transformed sprite), so collisions and the
// rotation-based arrow line up with the original game.

#pragma once

#include "raylib.h"
#include <string>
#include <vector>
#include <cmath>

// ---- assets live under assets/ relative to the working directory --------------
inline std::string assetPath(const std::string& name) {
    return std::string("assets/") + name;
}

// ---- SFML-style rectangle passed to setTextureRect ----------------------------
struct IntRect {
    float x, y, w, h;
    IntRect(float a = 0, float b = 0, float c = 0, float d = 0) : x(a), y(b), w(c), h(d) {}
};

// ---- result of getGlobalBounds(): supports .intersects() like sf::FloatRect ----
struct Bounds {
    Rectangle r;
    bool intersects(const Bounds& o) const { return CheckCollisionRecs(r, o.r); }
};

// ---- texture handle (lazy load; reloadable, like sf::Texture) ------------------
struct Tex {
    Texture2D t{};
    bool loaded = false;
    void loadFromFile(const std::string& name) {
        if (loaded) { UnloadTexture(t); loaded = false; }
        t = LoadTexture(assetPath(name).c_str());
        loaded = true;
    }
};

// ---- sprite: position / scale / rotation / textureRect / tint ------------------
class Sprite {
public:
    Tex* tex = nullptr;
    float rx = 0, ry = 0, rw = 0, rh = 0;   // source rectangle (textureRect)
    float px = 0, py = 0;                    // position
    float sx = 1, sy = 1;                    // scale (negative = flip)
    float rot = 0;                           // rotation (degrees, clockwise)
    float ox = 0, oy = 0;                    // origin (SFML default: top-left)
    Color tint = WHITE;

    Sprite() {}
    Sprite(Tex& t) { setTexture(t); }

    void setTexture(Tex& t) {
        tex = &t;
        if (t.loaded) { rw = (float)t.t.width; rh = (float)t.t.height; }
    }
    void setTextureRect(const IntRect& r) { rx = r.x; ry = r.y; rw = r.w; rh = r.h; }
    void setPosition(float x, float y) { px = x; py = y; }
    void move(float x, float y) { px += x; py += y; }
    void setScale(float a, float b) { sx = a; sy = b; }
    void rotate(float d) { rot += d; }
    void setColor(Color c) { tint = c; }
    void setOrigin(float x, float y) { ox = x; oy = y; }

    Vector2 getPosition() const { return { px, py }; }

    // SFML transform: G = position + Rot(rot) * (scale .* (local - origin))
    Vector2 transformPoint(float lx, float ly) const {
        float dx = (lx - ox) * sx;
        float dy = (ly - oy) * sy;
        float rad = rot * DEG2RAD;
        float c = cosf(rad), s = sinf(rad);
        return { px + dx * c - dy * s, py + dx * s + dy * c };
    }

    Bounds getGlobalBounds() const {
        Vector2 p0 = transformPoint(0, 0);
        Vector2 p1 = transformPoint(rw, 0);
        Vector2 p2 = transformPoint(0, rh);
        Vector2 p3 = transformPoint(rw, rh);
        float minx = fminf(fminf(p0.x, p1.x), fminf(p2.x, p3.x));
        float miny = fminf(fminf(p0.y, p1.y), fminf(p2.y, p3.y));
        float maxx = fmaxf(fmaxf(p0.x, p1.x), fmaxf(p2.x, p3.x));
        float maxy = fmaxf(fmaxf(p0.y, p1.y), fmaxf(p2.y, p3.y));
        return { { minx, miny, maxx - minx, maxy - miny } };
    }

    void draw() const {
        if (!tex || !tex->loaded) return;
        float asx = fabsf(sx), asy = fabsf(sy);
        Rectangle source = { rx, ry, (sx < 0 ? -rw : rw), (sy < 0 ? -rh : rh) };
        Rectangle dest = { px, py, rw * asx, rh * asy };
        // Place the SFML origin at `position` and pivot rotation there. For a flipped
        // axis, mirror the origin so the sprite lands on the same side SFML draws it.
        Vector2 origin = {
            (sx < 0) ? (rw - ox) * asx : ox * asx,
            (sy < 0) ? (rh - oy) * asy : oy * asy
        };
        DrawTexturePro(tex->t, source, dest, origin, rot, tint);
    }
};

// ---- font (sf::Font) -----------------------------------------------------------
struct GameFont {
    Font f{};
    bool loaded = false;
    void loadFromFile(const std::string& name) {
        f = LoadFontEx(assetPath(name).c_str(), 64, nullptr, 0);
        loaded = true;
    }
};

// ---- text (sf::Text) -----------------------------------------------------------
class Text {
public:
    GameFont* font = nullptr;
    Color col = WHITE;
    std::string str;
    float px = 0, py = 0, sx = 1, sy = 1;
    int charSize = 30;  // SFML default character size

    void setFont(GameFont& fnt) { font = &fnt; }
    void setFillColor(Color c) { col = c; }
    void setString(const std::string& s) { str = s; }
    void setPosition(float x, float y) { px = x; py = y; }
    void setScale(float a, float b) { sx = a; sy = b; }
    void setCharacterSize(int s) { charSize = s; }
    void setStyle(int) {}  // bold/italic/regular: not significant here

    void draw() const {
        if (!font || !font->loaded) return;
        float fs = charSize * sy;
        DrawTextEx(font->f, str.c_str(), { px, py }, fs, fs / 15.0f, col);
    }
};

// ---- audio (sf::Sound + looped tracks via a per-frame restart) -----------------
class SoundFx;
inline std::vector<SoundFx*>& soundRegistry() { static std::vector<SoundFx*> v; return v; }

class SoundFx {
public:
    Sound s{};
    bool loaded = false;
    bool loop = false;
    float vol = 1.0f;

    void loadFromFile(const std::string& name) {
        s = LoadSound(assetPath(name).c_str());
        loaded = true;
        SetSoundVolume(s, vol);
        soundRegistry().push_back(this);
    }
    void setVolume(float v) { vol = v / 100.0f; if (loaded) SetSoundVolume(s, vol); } // SFML 0..100
    void setLoop(bool b) { loop = b; }
    void play() { if (loaded) PlaySound(s); }
    void stop() { if (loaded) { StopSound(s); loop = false; } }
};

// Call once per frame: keep looping sounds going.
inline void updateAudio() {
    for (SoundFx* s : soundRegistry())
        if (s->loop && s->loaded && !IsSoundPlaying(s->s)) PlaySound(s->s);
}

// ---- window (sf::RenderWindow) -------------------------------------------------
class Window {
public:
    bool open = true;
    void create(int w, int h, const char* title) {
        InitWindow(w, h, title);
        InitAudioDevice();
    }
    bool isOpen() { return open && !WindowShouldClose(); }
    void close() { open = false; }
    void setFramerateLimit(int f) { SetTargetFPS(f); }
    void setMouseCursorVisible(bool v) { if (v) ShowCursor(); else HideCursor(); }
    void clear() { BeginDrawing(); ClearBackground(BLACK); }
    void draw(const Sprite& s) { s.draw(); }
    void draw(const Text& t) { t.draw(); }
    void display() { updateAudio(); EndDrawing(); }
};

// ---- input (sf::Keyboard / sf::Mouse) ------------------------------------------
namespace Keyboard {
    enum Key { Left, Right, Up, Down, L, Space };
    inline int toRay(Key k) {
        switch (k) {
            case Left:  return KEY_LEFT;
            case Right: return KEY_RIGHT;
            case Up:    return KEY_UP;
            case Down:  return KEY_DOWN;
            case L:     return KEY_L;
            case Space: return KEY_SPACE;
        }
        return 0;
    }
    inline bool isKeyPressed(Key k) { return IsKeyDown(toRay(k)); }
}

namespace Mouse {
    enum Button { Left };
    struct Vec { int x, y; };
    inline bool isButtonPressed(Button) { return IsMouseButtonDown(MOUSE_BUTTON_LEFT); }
    inline Vec getPosition() { Vector2 m = GetMousePosition(); return { (int)m.x, (int)m.y }; }
}
