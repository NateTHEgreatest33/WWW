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
#include "input_main.hpp"
#include "game_main.hpp"
#include "graphics/graphics_msg.hpp"


#include"graphics/main_menu.hpp"
#include"graphics/screen.hpp"
/*--------------------------------------------------------------------
                          LITERAL CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                                TYPES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                           MEMORY CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                          GLOBAL VARIABLES
--------------------------------------------------------------------*/
std::queue<graphics_msg> graphicsEvents;

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/
/*********************************************************************
*
*   PROCEDURE NAME:
*       main
*
*   DESCRIPTION:
*       Main loop
*
*********************************************************************/
int main
    (
    void
    )
{
/*----------------------------------------------------------
Local variables
----------------------------------------------------------*/
const int screenWidth = 800;
const int screenHeight = 450;

/*----------------------------------------------------------
Setup inits
----------------------------------------------------------*/
InitWindow(screenWidth, screenHeight, "Balloon Tower Offense");
SetTargetFPS(60);

main_menu<Image> backgroundImage( "main menu", 
                                  "/Users/natelenze/GitHub/WWW/src/resources/test.png",
                                  screenHeight,
                                  screenWidth );//"../../src/resources/test.png" );
graphics_init( &backgroundImage );

/*----------------------------------------------------------
Main processing Loop
----------------------------------------------------------*/
while ( !WindowShouldClose() )    // Detect window close button or ESC key
    {
    
    graphics_main( graphicsEvents );
    
    }

CloseWindow();

return 0;
} /* main() */