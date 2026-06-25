// Game.h
// Owns the shell of the game: window, assets, the player, the two levels, the menu /
// controls / story screens, the HUD and audio, and the state machine that switches
// between them. All level-specific entities and logic live in Level1 / Level2.

#pragma once

#include "compat/sfml_compat.h"
#include "AssetManager.h"
#include "Player.h"
#include "Level.h"
#include "Level1.h"
#include "Level2.h"

class Game {
public:
    int run();

private:
    void setup();

    Window window;
    AssetManager assets;
    Player player;
    Level1 level1;
    Level2 level2;

    // --- menu / HUD / story sprites ---
    Sprite cursor, black, red, heart, frame, bar, lose, win;
    Sprite storyImg[28];

    // --- text ---
    Text mainmenu, start, about, exitText, info;
    Text scoreLabel, scoreValue, highValue, highLabel;

    // --- audio ---
    SoundFx eat, ost, telep, fireBall, drink, spiderS;
    SoundFx voice1, voice2, voice3, back1, back2, back3, mainMenu11, lost;

    // --- state ---
    int level = 1;
    bool ending = false;
    bool die = false;
    int score = 0, highscore = 0;
    int Cntmainmenubg = 0, Cntgame = 0;
    int story = 0, storyStart = 0, sec = 0;
};
