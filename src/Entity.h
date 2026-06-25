// Entity.h
// Base class for every in-world game object. Wraps a Sprite and forwards the slice of
// the Sprite interface the game uses, so derived types (Player, Spider, Archer, ...) get
// position / bounds / movement / drawing for free and only add their own behaviour.

#pragma once

#include "compat/sfml_compat.h"

class Entity {
public:
    Sprite sprite;

    virtual ~Entity() = default;

    void setTexture(Tex& t) { sprite.setTexture(t); }
    void setTextureRect(const IntRect& r) { sprite.setTextureRect(r); }
    void setPosition(float x, float y) { sprite.setPosition(x, y); }
    void move(float x, float y) { sprite.move(x, y); }
    void setScale(float a, float b) { sprite.setScale(a, b); }
    void rotate(float d) { sprite.rotate(d); }
    void setColor(Color c) { sprite.setColor(c); }

    Vector2 getPosition() const { return sprite.getPosition(); }
    Bounds getGlobalBounds() const { return sprite.getGlobalBounds(); }

    void draw(Window& window) const { window.draw(sprite); }
};
