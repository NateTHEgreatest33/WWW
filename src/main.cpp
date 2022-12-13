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
#include <vector>
#include <tuple>
#include <functional>

#include "graphics_main.hpp"
#include "input_main.hpp"
#include "game_main.hpp"
#include "graphics/graphics_msg.hpp"
#include "gameplay/event.hpp"

#include"graphics/main_menu.hpp"
#include"graphics/screen.hpp"
#include "entities/button.hpp"
#include "entities/entity.hpp"
#include "gameplay/event.hpp"


#include "utl/utl.hpp"
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
std::queue<event> inputEvents;
screen* currentScreen;


/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/
void printHello(input_action y){
    std::cout<<"mouse button worked"<<std::endl;
}
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

gameplay::warning( true, "hello world");
screen *backgroundImage = new main_menu<Image>("main menu", LoadImage("/Users/natelenze/GitHub/WWW/src/resources/test.png"), screenHeight, screenWidth );

currentScreen = backgroundImage;
graphics_init( currentScreen );
input_init( currentScreen );

entity *newButton = new button( 10, 10, 100, 100, GREEN, "newButton", "hello world" );
std::vector< std::pair< MouseButton, std::function<void(input_action)> > > Mactions;
Mactions.push_back( std::make_pair( MOUSE_BUTTON_LEFT, printHello ));
newButton->initMouse( Mactions );
graphics_msg test( GRAPHIC_ENTITY, std::string("button1"), newButton );
graphicsEvents.push( test );



/*----------------------------------------------------------
Main processing Loop
----------------------------------------------------------*/
while ( !WindowShouldClose() )    // Detect window close button or ESC key
    {
    
    graphics_main( graphicsEvents );
    
    input_main( inputEvents );
    }

CloseWindow();

return 0;
} /* main() */