// Player.h
// The skeleton the player controls: an Entity plus the platformer state (animation
// frames, jump timer, health, i-frame flag). Movement that scrolls the world stays in
// Game (it touches every level entity); the sprite, bounds and animation live here.

#pragma once

#include "Entity.h"
#include "AssetManager.h"

class Player : public Entity {
public:
    int cnterX = 0, cnterY = 0;   // sprite-sheet column / row (animation state)
    int jump = 50;                // jump timer; >=50 means grounded/idle
    bool jumping = false;
    int hp = 100;
    int damage = 0;               // 1 = currently in an invulnerability window

    void init(AssetManager& assets) {
        setTexture(assets.texture("skeleton.png"));
        setTextureRect(IntRect(0, 0, 16, 27));
        setScale(2.5, 2.5);
        setPosition(100, 200);
    }

    // Apply the current frame counters to the sprite (standing vs. crouching rects).
    void animate() {
        cnterX %= 4;
        setTextureRect(IntRect(cnterX * 16, cnterY * 27, 16, 27));
        if (cnterY == 2) {
            setTextureRect(IntRect(cnterX * 16, cnterY * 30, 16, 21));
        }
    }
};
