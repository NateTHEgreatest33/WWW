/*********************************************************************
*
*   NAME:
*       graphics_main.cpp
*
*   DESCRIPTION:
*       main thread for graphics processing
*
*   Copyright 2022 Nate Lenze
*
*********************************************************************/
#include "graphics_main.hpp"

//main idea is to use a queue to handle incoming graphic requests and handle them in the order they come in
//accessing the queue will need to be memory safe


void graphics_main( void ){
    
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawRectangle(GetScreenWidth()/2 - 112, GetScreenHeight()/2 - 112, 224, 224, Fade(RAYWHITE, 1));
    DrawText(TextSubtext("raylib", 0, 7), GetScreenWidth()/2 - 44, GetScreenHeight()/2 + 48, 50, Fade(BLACK, alpha));
    EndDrawing();

}