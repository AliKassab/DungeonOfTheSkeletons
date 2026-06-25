// Level1.h -- the first level: the skeleton dungeon with the archer, spider and key.

#pragma once

#include "Level.h"
#include "Enemies.h"

class Level1 : public Level {
public:
    void build(AssetManager& assets) override;
    void scroll(int x, int y) override;
    bool atLeftEdge() const override { return phase1.getPosition().x > 0; }
    bool atRightEdge() const override { return phase2.getPosition().x < 0; }
    void update(PlayContext& ctx) override;
    void render(PlayContext& ctx, Window& window) override;

private:
    void coinn(int x, int y, int co, int i);

    Sprite phase1, phase2, phase3, phase4;
    Sprite platform[20], platform1[20], platform2[20], platform3[20];
    Sprite coin[41];
    bool coinbool[41] = {};
    Sprite spike[28];
    Sprite portalg1, portalg2, portalp1;
    Spider spider;
    Archer archer;
    Sprite arrow;
    Sprite key, keyi;
    Sprite brick[3];
    Sprite potion[2];
    bool potionbool[2] = {};

    bool keyopen = false, keyis = false;
    int bricks = 0, brickUp = 0;
    int pr = 0, cnterPr = 0;   // portal animation
    int coinPos = 0;           // build-time coin spacing
};
