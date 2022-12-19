/*********************************************************************
*
*   NAME:
*       main_menu.tpp
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
#include "../utl/utl.hpp"

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


template <>
main_menu<Image>::main_menu( const std::string name, Image background, int screenH, int screenW ) : screen( name, screenH, screenW )
    {
    p_screen_name = name;
    p_background = background;

    p_screenHeight = screenH;
    p_screenWidth  = screenW;

    ImageResize(&p_background, p_screenWidth, p_screenHeight);
    p_textureBackground = LoadTextureFromImage(p_background);
    }

template <>
main_menu<Color>::main_menu( const std::string name, Color background, int screenH, int screenW ) : screen( name, screenH, screenW )
    {
    p_screen_name = name;
    p_background = background;

    p_screenHeight = screenH;
    p_screenWidth  = screenW;

    }


template <typename T>
main_menu<T>::~main_menu()
    {
    UnloadTexture( p_textureBackground );
    }





template <typename T>
void main_menu<T>::handleLogic( void ){}


/*********************************************************************
*
*   PROCEDURE NAME:
*       drawBackground<Colo>
*
*   DESCRIPTION:
*       runs through list of objects + backgrounds and draws
*
*********************************************************************/
template <>
void main_menu<Color>::drawBackground( void )
{
/*----------------------------------------------------------
Local variables
----------------------------------------------------------*/

/*----------------------------------------------------------
Draw background image first
----------------------------------------------------------*/
ClearBackground( p_background );
drawObjs();

}

/*********************************************************************
*
*   PROCEDURE NAME:
*       drawBackground<Image>
*
*   DESCRIPTION:
*       runs through list of objects + backgrounds and draws
*
*********************************************************************/
template <>
void main_menu<Image>::drawBackground( void )
{
/*----------------------------------------------------------
Local variables
----------------------------------------------------------*/

/*----------------------------------------------------------
Draw background image first
----------------------------------------------------------*/
ClearBackground( WHITE );
DrawTexture(p_textureBackground, 0, 0, WHITE);

drawObjs();

}

/*********************************************************************
*
*   PROCEDURE NAME:
*       handleGraphicEvent<T>
*
*   DESCRIPTION:
*       Responds to graphics_msg
*
*********************************************************************/
template <typename T>
void main_menu<T>::handleGraphicEvent( graphics_msg event )
    {
    switch( event.type )
        {
        case GRAPHIC_SCREEN:
            p_background = std::any_cast<T>(event.graphic);
            break;            
        case GRAPHIC_ENTITY:
            p_currentObjects[ event.id ] = std::any_cast<entity*>(event.graphic);
            break;
        case GRAPHIC_OTHER:
        default:
            gameplay::warning( true, "unimplemented functionality hit" );
            break;
        }

    }