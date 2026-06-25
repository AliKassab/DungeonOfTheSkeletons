// Enemies.h
// The enemy actors, each owning its own sprite, animation counters, and behaviour that
// used to be scattered through the main loop as loose globals.

#pragma once

#include "Entity.h"
#include "AssetManager.h"

// Spider patrols left/right on a fixed cycle while cycling its walk frames (level 1).
class Spider : public Entity {
public:
    int frameX = 0, frameY = 0, timer = 0;

    void init(AssetManager& assets) {
        setTexture(assets.texture("spider.png"));
        setTextureRect(IntRect(0, 0, 98.66666666666667, 87));
        setPosition(62, 1330);
        setScale(1, 1);
    }

    void update() {
        timer++;
        if (timer <= 170) { move(5, 0); frameX++; frameY = 1; }
        else { move(-5, 0); frameX++; frameY = 0; }
        if (timer > 340) { timer = 0; }
        frameX %= 3;
        setTextureRect(IntRect(frameX * 98.66666666666667, frameY * 87, 98.66666666666667, 87));
    }
};

// Archer stands and cycles its bow-draw frames; the game spawns an arrow on frame 6.
class Archer : public Entity {
public:
    int timer = 1, frame = 0;

    void init(AssetManager& assets) {
        setTexture(assets.texture("archer.png"));
        setTextureRect(IntRect(0, 0, 72, 76));
        setScale(-1, 1);
        setPosition(1200, 1000);
    }

    void animate() {
        timer++;
        if (timer % 7 == 0) {
            frame++;
            frame %= 9;
            setTextureRect(IntRect(frame * 72, 0, 72, 76));
        }
    }

    int getFrame() const { return frame; }
};

// Wizard is a pair of casters that animate together; the game reads the frame to time
// fireball spawns (level 2).
class Wizard {
public:
    Entity parts[2];
    int timer = 1, frame = 0;

    void init(AssetManager& assets) {
        Tex& tex = assets.texture("wiz.png");
        for (int i = 0; i < 2; i++) {
            parts[i].setTexture(tex);
            parts[i].setTextureRect(IntRect(0, 0, 32, 64));
            parts[i].setScale(3, 3);
        }
        parts[0].setPosition(1240, 150);
        parts[1].setPosition(50, 320);
        parts[0].setScale(-3, 3);
    }

    void animate() {
        timer++;
        if (timer % 5 == 0) {
            frame++;
            frame %= 9;
            for (int i = 0; i < 2; i++) {
                parts[i].setTextureRect(IntRect(frame * 32, 0, 32, 64));
            }
        }
    }

    int getFrame() const { return frame; }
    void move(float x, float y) { for (auto& p : parts) p.move(x, y); }
    void draw(Window& window) const { for (auto& p : parts) p.draw(window); }
};
