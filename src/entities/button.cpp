/*********************************************************************
*
*   NAME:
*       button.cpp
*
*   DESCRIPTION:
*       button class
*
*   Copyright 2022 Nate Lenze
*
*********************************************************************/
/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "button.hpp"

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
                              CLASSES
--------------------------------------------------------------------*/

button::button( int x, int y, int length, int height, Color color, std::string name, std::string text ) : entity( x, y, std::vector<hitRad>(), true, name )
{

}

button::~button(){}

void button::draw( void ){}

void button::actionKeyboard( KeyboardKey action ){}

void button::actionMouse( GamepadButton action ){}

void button::actionGamepad( MouseButton action ){}

