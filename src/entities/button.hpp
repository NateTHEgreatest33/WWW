/*********************************************************************
*
*   NAME:
*       button .hpp
*
*   DESCRIPTION:
*       button class
*
*   Copyright 2022 Nate Lenze
*
*********************************************************************/
#ifndef BUTTON_HPP
#define BUTTON_HPP
/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "entity.hpp"

#include <unordered_map>
#include <functional>
#include <any>
#include <iostream>

#include "../include/raylib.h"

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
class button : public entity 
{
public:
    button( int x, int y, int length, int height, Color color, std::string name, std::string text );
    ~button();
    void draw( void );
    void actionKeyboard( KeyboardKey action );
    void actionMouse( MouseButton action );
    void actionGamepad( GamepadButton action );

    void initKeyboard( std::vector< std::pair< KeyboardKey, std::function<void()> > > inputList );
    void initMouse( std::vector< std::pair< MouseButton, std::function<void()> > > inputList );
    void initGamepad( std::vector< std::pair< GamepadButton, std::function<void()> > > inputList );

private:
    int p_length;
    int p_height;
    Color p_color;

    std::unordered_map< KeyboardKey, std::function<void()> > p_keyboardFunction;
    std::unordered_map< MouseButton, std::function<void()> > p_mouseFunction;
    std::unordered_map< GamepadButton, std::function<void()> > p_gamepadFunction;

};

#endif