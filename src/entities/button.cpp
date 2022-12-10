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
    gameplay::warning( true, "GOT HERE" );
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


void button::initKeyboard( std::vector< std::pair< KeyboardKey, std::function<void()> > > inputList )
{
for( auto i : inputList )
    {
    p_keyboardFunction[ i.first ] = i.second;
    }
}

void button::initMouse( std::vector< std::pair< MouseButton, std::function<void()> > > inputList )
{
for( auto i : inputList )
    {
    p_mouseFunction[ i.first ] = i.second;
    }
}

void button::initGamepad( std::vector< std::pair< GamepadButton, std::function<void()> > > inputList )
{
for( auto i : inputList )
    {
    p_gamepadFunction[ i.first ] = i.second;
    }
}