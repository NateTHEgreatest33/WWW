/*********************************************************************
*
*   NAME:
*       main.cpp
*
*   DESCRIPTION:
*       main processing loop for game
*
*   Copyright 2022 Nate Lenze
*
*********************************************************************/

#include "include/raylib.h"
#include "graphics_main.hpp"
//#include "game_includes/example.hpp"

#include "vector"
#include <unordered_map>

std::vector<int> TestVec;

int main(void)
{

    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "RayLib Example");
    SetTargetFPS(60);

    while ( !WindowShouldClose() )    // Detect window close button or ESC key
        {
        graphics_main();
       
        }

    CloseWindow();

    return 0;
}