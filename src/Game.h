// Game.h
// Owns the whole game: window, assets, the player, every level entity, the HUD, audio,
// and the menu/story/playing state machine. This replaces the original file's global
// state -- there are no globals any more; everything is a member with clear ownership.
//
// For this milestone the per-level update/draw logic still lives in run() (faithful to
// the original two-level structure). Splitting Level into its own class and making the
// levels data-driven is the next milestone.

#pragma once

#include "compat/sfml_compat.h"
#include "AssetManager.h"
#include "Player.h"
#include "Enemies.h"

class Game {
public:
    int run();

private:
    void setup();
    void level1Phase();
    void level2Phase();
    void buildPlatforms();
    void buildCoins();
    void coinn(int x, int y, int co, int i);
    void poison(int x, int y, int i);
    void move(int x, int y);    // scroll level 1's world
    void move2(int x, int y);   // scroll level 2's world

    Window window;
    AssetManager assets;
    Player player;
    Spider spider;
    Archer archer;
    Wizard wizard;

    // --- sprites: projectiles / world ---
    Sprite arrow;
    Sprite phase1, phase2, phase3, phase4, phase5, phase6, phase7, phase8;
    Sprite key, keyi, fireball1, fireball2, finalDoor;
    Sprite portalg1, portalg2, portalg3, portalg4, portalp1, portalp2, portalr1, portalr2;

    Sprite coin[60];
    Sprite platform[60], platform1[60], platform2[60], platform3[60];
    Sprite spike[28];
    Sprite brick[3], potion[2], fire[5], up2[5], p1[15], hidden[20], box[4];
    Sprite storyImg[28];

    // --- HUD / menu sprites ---
    Sprite cursor, black, red, heart, frame, bar, lose, win;

    // --- text ---
    Text mainmenu, start, about, exitText, info;
    Text scoreLabel, scoreValue, highValue, highLabel;

    // --- audio ---
    SoundFx eat, ost, telep, fireBall, drink, spiderS;
    SoundFx voice1, voice2, voice3, back1, back2, back3, mainMenu11, lost;

    // --- state ---
    bool coinbool[60] = {};
    int coinPos = 0, coinPos2 = 0;
    int diff = 0;
    bool potionbool[2] = {};
    int pr = 0, cnterPr = 0;
    int pr1 = 1, cnterPr1 = 0;
    int bricks = 0, brickUp = 0;
    int level = 1;
    bool ending = false;

    int hiddenarr[20] = { 0 };
    int Cnthiddenarr[20] = { 0 };
    int fp = 1, cntfp = 0;          // fire animation
    float fireY = 70;
    int fireScale = 0;
    bool keyopen = false, keyis = false;
    int score = 0, highscore = 0;
    int Cntmainmenubg = 0, Cntgame = 0;
    bool boxtrap[4] = {};
    int story = 0, storyStart = 0, sec = 0;
    bool die = false;
};
