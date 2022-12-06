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

button::button( int x, int y, int height, int length, Color color, std::string name, std::string text ) : entity( x, y, std::vector<hitRad>(), true, name )
{
    p_height = height;
    p_length = length;
    p_color  = color;
}

button::~button(){}

void button::draw( void ){
    auto cord = getCords();
    DrawRectangle(  cord.x, cord.y, p_length, p_height, p_color );
}

void button::actionKeyboard( KeyboardKey action ){
    if( p_keyboardFunction.count( action ) )
        p_keyboardFunction[ action ];
}

void button::actionMouse( MouseButton action ){
    if( p_mouseFunction.count( action ) )
        p_mouseFunction[ action ];
}

void button::actionGamepad( GamepadButton action ){
    if( p_gamepadFunction.count( action ) )
        p_gamepadFunction[ action ];
}


