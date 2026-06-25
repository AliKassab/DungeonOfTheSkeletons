# Dungeon of the Skeletons

A 2D dungeon platformer in C++. Run, jump, and crouch your way through skeleton-infested
levels — dodging spikes, archers, wizards and spiders, collecting coins and keys, and
travelling between rooms through portals.

> **Status:** Being ported from SFML (Windows-only) to **raylib**, so it builds natively on
> macOS / Windows / Linux and compiles to **WebAssembly** to play in the browser. See the
> milestone roadmap below.

## Building (native)

Requires a C++ compiler and CMake. raylib is fetched automatically — no system install needed.

```sh
cmake -B build
cmake --build build
./build/dungeon          # run from the repo root so assets/ is found
```

## Project layout

```
assets/   all game media (images, audio, fonts) + Highscore.txt
src/      game source
  compat/ small SFML-compatibility helpers (Sprite/text/audio) used by the port
shell/    HTML shell for the web build
```

## Roadmap

- **M1 — Faithful raylib port** (in progress): same game, builds & runs natively on Mac.
- **M2 — Web build**: WebAssembly via Emscripten; playable from a URL.
- **M3 — OOP refactor**: replace the global state with `Game` / `Player` / `Entity` / `Level`
  classes and per-screen state objects.
- **M4 — Polish**: data-driven levels, screenshots/GIF, "play now" link.

## Credits

Originally built as an SFML game. Art, audio and level design retained from the original.
