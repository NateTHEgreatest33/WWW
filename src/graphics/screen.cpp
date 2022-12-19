/*********************************************************************
*
*   NAME:
*       screen.cpp
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
*       drawObjs
*
*   DESCRIPTION:
*       Runs through list of entity objects and calls draw function
*
*********************************************************************/
void screen::drawObjs( void )
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
*       clearAllObj
*
*   DESCRIPTION:
*       clears all objects on the screen except background object
*
*********************************************************************/
void screen::clearAllObj( void )
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
*       handleInputEvent
*
*   DESCRIPTION:
*       handles event objects
*
*********************************************************************/
void screen::handleInputEvent( event action ){
    for( auto ent : p_currentObjects )
        {
        ent.second->isHitAction( action );
        }
}

/*********************************************************************
*
*   PROCEDURE NAME:
*       addObj
*
*   DESCRIPTION:
*       adds new entity object
*
*********************************************************************/
void screen::addObj( std::string id, entity* obj ){
    gameplay::abort( (p_currentObjects.count( id ) > 0), "replacing ID");
    p_currentObjects[ id ] = obj;
}

/*********************************************************************
*
*   PROCEDURE NAME:
*       screen
*
*   DESCRIPTION:
*       Constructor for screen class
*
*********************************************************************/
screen::screen( const std::string name, int screenH, int screenW )
    {
    p_screen_name = name;

    p_screenHeight = screenH;
    p_screenWidth  = screenW;
    }

/*********************************************************************
*
*   PROCEDURE NAME:
*       ~screen
*
*   DESCRIPTION:
*       Deconstructor for screen class
*
*********************************************************************/
screen::~screen()
    {
        
    }
