// Level2.h -- the second level: wizards, fireballs, hidden tiles, poison and the door.
// Uses the original index ranges (21..59) for its platform/coin arrays so the layout
// is byte-for-byte the original; the lower indices are simply unused.

#pragma once

#include "Level.h"
#include "Enemies.h"

class Level2 : public Level {
public:
    void build(AssetManager& assets) override;
    void scroll(int x, int y) override;
    bool atLeftEdge() const override { return phase5.getPosition().x > 0; }
    bool atRightEdge() const override { return phase6.getPosition().x < 0; }
    void update(PlayContext& ctx) override;
    void render(PlayContext& ctx, Window& window) override;
    void drawOverlay(Window& window) override;   // poison + boxes, drawn over the player

private:
    void coinn(int x, int y, int co, int i);
    void poison(int x, int y, int i);

    Sprite phase5, phase6, phase7, phase8;
    Sprite platform[60], platform1[60], platform2[60], platform3[60];
    Sprite coin[60];
    bool coinbool[60] = {};
    Sprite portalg3, portalp2, portalr1, portalr2;
    Wizard wizard;
    Sprite fireball1, fireball2, finalDoor;
    Sprite fire[5], up2[5], p1[15], hidden[20], box[4];

    int pr = 0, cnterPr = 0;     // portal animation
    int pr1 = 1, cnterPr1 = 0;   // poison animation
    int fp = 1, cntfp = 0;       // fire animation
    float fireY = 70;
    int fireScale = 0;
    bool boxtrap[4] = {};
    int hiddenarr[20] = { 0 };
    int Cnthiddenarr[20] = { 0 };
    int coinPos2 = 0;            // build-time coin spacing
    int diff = 0;               // build-time poison spacing
};
