// Dungeon of the Skeletons -- entry point.
//
// All game state and logic now live in the Game class (see Game.h / Game.cpp). The
// original 2451-line procedural file has been refactored into Game + Player +
// AssetManager, with the raylib bridge in compat/sfml_compat.h.

#include "Game.h"

int main() {
    Game game;
    return game.run();
}
