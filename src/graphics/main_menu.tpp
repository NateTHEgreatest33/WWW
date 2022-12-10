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
template <typename T>
main_menu<T>::main_menu()
    {
        std::cout<<"hello world";
        //clean up memory
    }


template <typename T>
main_menu<T>::main_menu( const std::string name, T background, int screenH, int screenW )
    {
        p_screen_name = name;
        p_background = background;

        screenHeight = screenH;
        screenWidth  = screenW;
    }


template <typename T>
main_menu<T>::~main_menu()
    {
        std::cout<<"hello world";
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

template <>
void main_menu<Image>::drawBackground( void )
{
/*----------------------------------------------------------
Local variables
----------------------------------------------------------*/

/*----------------------------------------------------------
Draw background image first
----------------------------------------------------------*/
ClearBackground( BLUE );
ImageResize(&p_background, screenWidth, screenHeight);
Texture2D texture = LoadTextureFromImage(p_background);
DrawTexture(texture, 0, 0, WHITE);

drawObjs();

}

template <typename T>
void main_menu<T>::handleEvent( graphics_msg event )
    {
    switch( event.type )
        {
        case GRAPHIC_SCREEN:
            //p_background = std::any_cast<T>(event.graphic);
            break;            
        case GRAPHIC_ENTITY:
            //p_currentObjects[ event.id ] = std::any_cast<entity*>(event.graphic);
            break;
        case GRAPHIC_OTHER:
        default:
            break;
        }

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
template <typename T>
void main_menu<T>::clearAllObj( void )
{
/*----------------------------------------------------------
remove objects that are not background
----------------------------------------------------------*/
for( auto drawObj : p_currentObjects )
    {
    if( drawObj.first == "background ")
        continue;
    
    p_currentObjects.erase( drawObj.first );
    }   
}



template <typename T>
void main_menu<T>::handleInput( void ){}

template <typename T>
void main_menu<T>::handleLogic( void ){}

template<typename T>
void main_menu<T>::addObj( std::string id, entity obj ){
    gameplay::warning( (p_currentObjects.count( id ) > 0), "replacing ID");
    p_currentObjects[ id ] = obj;
}


template<typename T>
void main_menu<T>::drawObjs( void )
{
/*----------------------------------------------------------
Draw Objects
----------------------------------------------------------*/
for( auto drawObj : p_currentObjects )
    {
    drawObj.second.draw();
    }

}