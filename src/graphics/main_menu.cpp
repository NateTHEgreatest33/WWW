/*********************************************************************
*
*   NAME:
*       main_menu.cpp
*
*   DESCRIPTION:
*       main menu class for graphics
*
*   Copyright 2022 Nate Lenze
*
*********************************************************************/
/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "main_menu.hpp"

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

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/
main_menu::main_menu( const std::string name, const std::string backgroundPth )
    {
        screen_name = name;
        background = LoadImage( backgroundPth.c_str() );//backgroundPth );
    }

main_menu::~main_menu()
    {
        //clean up memory
    }

/*********************************************************************
*
*   PROCEDURE NAME:
*       drawBackground
*
*   DESCRIPTION:
*       runs through list of objects + backgrounds and draws
*
*********************************************************************/
void main_menu::drawBackground( void )
{
/*----------------------------------------------------------
Local variables
----------------------------------------------------------*/

/*----------------------------------------------------------
Draw background image first
----------------------------------------------------------*/
ClearBackground( BLUE );
// ImageCrop(&background, (Rectangle){ 100, 10, 300, 300 });      // Crop an image piece
ImageResize(&background, 100, 100);
Texture2D texture = LoadTextureFromImage(background);
// ImageDraw( &background, 
//             background, 
//             (Rectangle){ 0, 0, (float)background.width, (float)background.height }, 
//             (Rectangle){ 30, 40, background.width*1.5f, background.height*1.5f }, 
//             BLANK );
//ImageDrawRectangle(&background, 10, 10, 100, 100, RAYWHITE );

DrawCircle( 50, 50, 50.0, RAYWHITE );

DrawTexture(texture, 200, 200, WHITE);



/*----------------------------------------------------------
Draw Objects
----------------------------------------------------------*/
for( auto drawObj : _currentObjects )
    {
    drawObj.second.draw();
    }

}

void main_menu::handleEvent( graphics_msg event )
    {

    }

/*********************************************************************
*
*   PROCEDURE NAME:
*       clearAllObj
*
*   DESCRIPTION:
*       clears all objects on the screen except background object
*
*********************************************************************/
void main_menu::clearAllObj( void )
{
/*----------------------------------------------------------
remove objects that are not background
----------------------------------------------------------*/
for( auto drawObj : _currentObjects )
    {
    if( drawObj.first == "background ")
        continue;
    
    _currentObjects.erase( drawObj.first );
    }   
}




void main_menu::handleInput( void ){}

void main_menu::handleLogic( void ){}
