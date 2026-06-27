# Dungeon of the Skeletons

A 2D dungeon platformer written in **C++**. Run, jump, and crouch your way through
skeleton-infested levels, dodging spikes, archers, wizards and spiders, collecting coins
and keys, and travelling between rooms through portals.

### ▶ [Play it in your browser](https://alikassab.dev/DungeonOfTheSkeletons/)

---

## What this project demonstrates

Originally a single **2451-line procedural `Main Game.cpp`** built on **SFML 2.x**, tied to
Visual Studio and Windows-only headers. This repo is the port and rewrite:

- **Cross-platform C++ / CMake.** Builds natively on macOS, Windows and Linux. Dependencies
  (raylib) are fetched and built by CMake — there is nothing to install by hand.
- **WebAssembly target.** The same source compiles to the browser via Emscripten, so the game
  is playable from a link with no runtime to install.
- **Engine migration.** SFML was replaced with [raylib](https://www.raylib.com/) behind a thin
  compatibility layer (`src/compat/sfml_compat.h`) that reproduces SFML's `Sprite` / `Text` /
  sound semantics — including its transform model (origin, rotation pivot, AABB bounds) — so the
  ported gameplay stays pixel-accurate.
- **OOP refactor.** The 152 global variables and one giant `main()` became a small class
  hierarchy (see below); the game logic now lives in the objects that own it.

## Architecture

```
main.cpp             entry point . constructs and runs Game
Game.{h,cpp}         window, asset ownership, state machine (menu → story → play → win/lose)
AssetManager.h       loads & caches textures / fonts / sounds by filename (dedupes)
Entity.h             base actor: wraps a Sprite, forwards position / bounds / move / draw
Player.h             : Entity   — skeleton sprite, animation state, jump/crouch
Enemies.h            Spider / Archer : Entity (patrol + animate); Wizard is a composite
Level.h              abstract Level + PlayContext (refs passed to per-level logic)
Level1.{h,cpp}       owns its phases / platforms / coins / portals / enemies
Level2.{h,cpp}       "
compat/sfml_compat.h raylib bridge implementing the SFML-flavoured API the game calls
```

`Game` drives a fixed 30 Hz timestep. Natively it runs a `while` loop; on the web the browser
owns the frame loop, so it uses `emscripten_set_main_loop` (requestAnimationFrame) and throttles
game logic to 30 Hz internally so the feel is identical on both platforms.

## Building (native)

Requires a C++17 compiler and CMake 3.16+. raylib is fetched automatically.

```sh
cmake -B build
cmake --build build
./build/dungeon          # run from the repo root so assets/ resolves
```

## Building (web)

Requires the [Emscripten SDK](https://emscripten.org/) (`emcc`) on your PATH.

```sh
emcmake cmake -B build-web -DPLATFORM=Web
cmake --build build-web
# serve the output and open it
cd build-web && python3 -m http.server 8099   # → http://localhost:8099
```

This produces `index.{html,js,wasm,data}`. The live build is deployed from the
[`gh-pages`](https://github.com/AliKassab/DungeonOfTheSkeletons/tree/gh-pages) branch via GitHub Pages.

> Note: the high score persists between runs natively; on the web it resets per session.

## Project layout

```
assets/   all game media (images, audio, fonts) + Highscore.txt
src/      game source (+ src/compat/ for the raylib bridge)
shell/    HTML shell used by the web build
```
