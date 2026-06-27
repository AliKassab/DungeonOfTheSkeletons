// Dungeon of the Skeletons -- entry point.
//
// All game state and logic now live in the Game class (see Game.h / Game.cpp). The
// original 2451-line procedural file has been refactored into Game + Player +
// AssetManager + Level1/Level2, with the raylib bridge in compat/sfml_compat.h.
//
// Game is a large object (it owns both levels and all their entities), so it is
// heap-allocated -- placing it on the stack overflows Emscripten's small default
// stack on the web build.

#include "Game.h"
#include <memory>

int main() {
    auto game = std::make_unique<Game>();
    return game->run();
}
