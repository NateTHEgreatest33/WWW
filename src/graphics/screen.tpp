/*********************************************************************
*
*   NAME:
*       screen.tpp
*
*   DESCRIPTION:
*       template file for screen functionality
*
*   Copyright 2022 Nate Lenze
*
*********************************************************************/
/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "screen.hpp"
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
void screen<Color>::drawBackground( void )
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
void screen<Image>::drawBackground( void )
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
*       drawObjs<T>
*
*   DESCRIPTION:
*       Runs through list of entity objects and calls draw function
*
*********************************************************************/
template <typename T>
void screen<T>::drawObjs( void )
{
/*----------------------------------------------------------
Draw Objects
----------------------------------------------------------*/
for( auto drawObj : p_currentObjects )
    {
    drawObj.second->draw();
    }

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
void screen<T>::handleGraphicEvent( graphics_msg event )
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


/*********************************************************************
*
*   PROCEDURE NAME:
*       clearAllObj<T>
*
*   DESCRIPTION:
*       clears all objects on the screen except background object
*
*********************************************************************/
template <typename T>
void screen<T>::clearAllObj( void )
{
/*----------------------------------------------------------
remove objects that are not background
----------------------------------------------------------*/
for( auto drawObj : p_currentObjects )
    {
    if( drawObj.first == "background")
        continue;
    
    p_currentObjects.erase( drawObj.first );
    }   
}

/*********************************************************************
*
*   PROCEDURE NAME:
*       handleInputEvent<T>
*
*   DESCRIPTION:
*       handles event objects
*
*********************************************************************/
template <typename T>
void screen<T>::handleInputEvent( event action ){
    for( auto ent : p_currentObjects )
        {
        ent.second->isHitAction( action );
        }
    
}


/*********************************************************************
*
*   PROCEDURE NAME:
*       addObj<T>
*
*   DESCRIPTION:
*       adds new entity object
*
*********************************************************************/
template<typename T>
void screen<T>::addObj( std::string id, entity* obj ){
    gameplay::abort( (p_currentObjects.count( id ) > 0), "replacing ID");
    p_currentObjects[ id ] = obj;
}

/*********************************************************************
*
*   PROCEDURE NAME:
*       screen<Color>
*
*   DESCRIPTION:
*       Constructor for Color template parameter
*
*********************************************************************/
template <>
screen<Color>::screen( const std::string name, Color background, int screenH, int screenW )
    {
    p_screen_name = name;
    p_background = background;

    p_screenHeight = screenH;
    p_screenWidth  = screenW;
    }

/*********************************************************************
*
*   PROCEDURE NAME:
*       screen<Image>
*
*   DESCRIPTION:
*       Constructor for Image template parameter
*
*********************************************************************/
template <>
screen<Image>::screen( const std::string name, Image background, int screenH, int screenW )
    {
    p_screen_name = name;
    p_background = background;

    p_screenHeight = screenH;
    p_screenWidth  = screenW;

    ImageResize(&p_background, p_screenWidth, p_screenHeight);
    p_textureBackground = LoadTextureFromImage(p_background);
    }

/*********************************************************************
*
*   PROCEDURE NAME:
*       ~screen<T>
*
*   DESCRIPTION:
*       Deconstructor for screen class
*
*********************************************************************/
template <typename T>
screen<T>::~screen()
    {
        UnloadTexture( p_textureBackground );
        
    }
