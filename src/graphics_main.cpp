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
    //draw standard info
    //mouse pointer?
    //time playing the game
    
    //process any events in mailbox to draw?
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawRectangle(GetScreenWidth()/2 - 112, GetScreenHeight()/2 - 112, 224, 224, Fade(RAYWHITE, 1));
    DrawText(TextSubtext("raylib", 0, 7), GetScreenWidth()/2 - 44, GetScreenHeight()/2 + 48, 50, Fade(BLACK, 1.0f ));
    EndDrawing();

    WaitTime( 1000 );

    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawRectangle(20, 20, 224, 224, Fade(GREEN, 1));
    EndDrawing();

    WaitTime( 1000 );

}