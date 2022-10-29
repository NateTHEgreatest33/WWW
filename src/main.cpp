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
/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "include/raylib.h"

#include <iostream>
#include <queue>

#include "graphics_main.hpp"
// #include "input_main.hpp"
// #include "game_main.hpp"
//#include "graphics/graphics_msg.hpp"



std::queue<graphics_msg> graphicsEvents;

/*********************************************************************
*
*   PROCEDURE NAME:
*       main
*
*   DESCRIPTION:
*       Main loop
*
*********************************************************************/
int main(void)
{

    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "RayLib Example");
    SetTargetFPS(60);


    

    while ( !WindowShouldClose() )    // Detect window close button or ESC key
        {
        //std::cout << "here";
        graphics_main( graphicsEvents );
       
        }

    CloseWindow();

    return 0;
} /* main() */