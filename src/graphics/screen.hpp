/*********************************************************************
*
*   NAME:
*       screen.hpp
*
*   DESCRIPTION:
*       background graphics class
*
*   Copyright 2022 Nate Lenze
*
*********************************************************************/
#ifndef SCREEN_HPP
#define SCREEN_HPP
/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include <iostream>

#include "graphics_msg.hpp"
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
                              VARIABLES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              CLASSES
--------------------------------------------------------------------*/

class screen 
    {
    private:
   
    public:

    void virtual drawBackground( void ) = 0;

    void virtual handleEvent( graphics_msg event ) = 0;

    void virtual clearAllObj( void ) = 0;

    void virtual handleInput( void ) = 0;

    void virtual handleLogic( void ) = 0;

    };

#endif