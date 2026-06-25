// Level.h
// Base class for a playable level plus the small context object a level needs to reach
// shared game state (the player, score, level switch, ending flag, the sounds it
// triggers, and the asset manager). Levels own all of their own world entities.
//
// A level's per-frame work is split to match the original frame order exactly:
//   update()      -- gameplay/collision logic, runs every frame while alive
//   render()      -- the level's logic-that-draws pass (drawn before the player)
//   drawOverlay() -- anything drawn on top of the player (level 2's traps)

#pragma once

#include "compat/sfml_compat.h"
#include "AssetManager.h"
#include "Player.h"

struct PlayContext {
    Player& player;
    int& score;
    int& level;     // current level id (1/2); a level may set this to hand off
    bool& ending;   // set when the player reaches the final door
    SoundFx& eat;
    SoundFx& telep;
    SoundFx& drink;
    SoundFx& spiderS;
    SoundFx& fireBall;
    SoundFx& ost;
    AssetManager& assets;
};

class Level {
public:
    virtual ~Level() = default;

    virtual void build(AssetManager& assets) = 0;

    virtual void scroll(int x, int y) = 0;      // move the whole world
    virtual bool atLeftEdge() const = 0;        // world can't scroll further right
    virtual bool atRightEdge() const = 0;       // world can't scroll further left

    virtual void update(PlayContext& ctx) = 0;
    virtual void render(PlayContext& ctx, Window& window) = 0;
    virtual void drawOverlay(Window& window) {}
};
