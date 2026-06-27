cmake_minimum_required(VERSION 3.16)
project(dungeon CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Some bundled dependencies still declare very old cmake minimums; keep cmake 4.x happy.
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)

include(FetchContent)

# ---- raylib (fetched & built automatically; no system install needed) ----
set(RAYLIB_VERSION 5.5)
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG ${RAYLIB_VERSION}
    GIT_SHALLOW TRUE
)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(raylib)

# ---- game executable ----
file(GLOB_RECURSE GAME_SOURCES CONFIGURE_DEPENDS src/*.cpp)
add_executable(dungeon ${GAME_SOURCES})
target_include_directories(dungeon PRIVATE src)
target_link_libraries(dungeon PRIVATE raylib)

# ---- web (Emscripten) build target ----
# Configure with: emcmake cmake -B build-web && cmake --build build-web
if(EMSCRIPTEN)
    set_target_properties(dungeon PROPERTIES OUTPUT_NAME "index" SUFFIX ".html")
    target_link_options(dungeon PRIVATE
        --preload-file ${CMAKE_SOURCE_DIR}/assets@assets
        -sUSE_GLFW=3
        -sASYNCIFY
        -sTOTAL_MEMORY=268435456
        -sSTACK_SIZE=4MB
        # raylib's GLFW JS shim reads the HEAP views directly; recent Emscripten no
        # longer exports them by default, so request them explicitly.
        -sEXPORTED_RUNTIME_METHODS=ccall,cwrap,HEAPF32,HEAP32,HEAPU8,HEAPU32,HEAPF64
        --shell-file ${CMAKE_SOURCE_DIR}/shell/shell.html
    )
endif()

# macOS / Linux: copy nothing — the game is run from the repo root so "assets/..." resolves.
