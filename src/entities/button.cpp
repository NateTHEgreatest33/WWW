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

button::button( int x, int y, int height, int length, Color color, std::string name, std::string text ) : entity( cords( x, y ), std::vector<hitRad>(), true, name )
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

void button::actionKeyboard( KeyboardKey input, input_action action ){
    if( p_keyboardFunction.count( input ) )
        p_keyboardFunction[ input ](action);
}

void button::actionMouse( MouseButton input, input_action action ){
    if( p_mouseFunction.count( input ) )
        p_mouseFunction[ input ](action);
}

void button::actionGamepad( GamepadButton input, input_action action ){
    if( p_gamepadFunction.count( input ) )
        p_gamepadFunction[ input ](action);
}


void button::initKeyboard( std::vector< std::pair< KeyboardKey, std::function<void(input_action)> > > inputList )
{
for( auto i : inputList )
    {
    p_keyboardFunction[ i.first ] = i.second;
    }
}

void button::initMouse( std::vector< std::pair< MouseButton, std::function<void(input_action)> > > inputList )
{
for( auto i : inputList )
    {
    p_mouseFunction[ i.first ] = i.second;
    }
}

void button::initGamepad( std::vector< std::pair< GamepadButton, std::function<void(input_action)> > > inputList )
{
for( auto i : inputList )
    {
    p_gamepadFunction[ i.first ] = i.second;
    }
}