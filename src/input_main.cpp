/*********************************************************************
*
*   NAME:
*       input_main.cpp
*
*   DESCRIPTION:
*       main thread for input processing
*
*   Copyright 2022 Nate Lenze
*
*********************************************************************/
/*--------------------------------------------------------------------
                             INCLUDES
--------------------------------------------------------------------*/
#include "input_main.hpp"

#include <set>

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
static screen*current_screen = nullptr;

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/

void input_init
    (
    screen *init_s
    )
{
current_screen = init_s;

}

void input_main
    (
    std::queue<event>& events 
    )
{
    static std::set<KeyboardKey> activeKeys;
    static std::set<MouseButton> activeMouseButtons;
    /*-------------------------------------
    Handle new key presses
    -------------------------------------*/
    KeyboardKey keyPressed = (KeyboardKey)GetKeyPressed();

    while( keyPressed != KEY_NULL ) {
        activeKeys.insert( keyPressed );
        keyPressed = (KeyboardKey)GetKeyPressed();
        event newKeyPress( in_KEYBOARD, keyPressed, cords(0,0), action_KEY_PRESSED );
        events.push( newKeyPress );
    }

    /*-------------------------------------
    Handle old key presses
    -------------------------------------*/
    for( auto key = activeKeys.begin(); key != activeKeys.end();  )
        {
        if( IsKeyUp( *key ) )
            {
            event newKeyReleased( in_KEYBOARD, *key, cords(0,0), action_KEY_RELEASED );
            events.push( newKeyReleased );
            key = activeKeys.erase( key );
            }
        else
            {
            key++;
            }
        }

    /*-------------------------------------
    Handle Active Mouse clicks
    -------------------------------------*/
    for( int mButton = MOUSE_BUTTON_LEFT; mButton <= MOUSE_BUTTON_BACK; mButton++ )
        {
        if( IsMouseButtonPressed( (MouseButton)mButton ) )
            {
            events.push( event( in_MOUSE, (MouseButton)mButton, cords( GetMouseX(), GetMouseY() ), action_MOUSE_PRESSED )  );
            activeMouseButtons.insert( (MouseButton)mButton );
            }
        }

    /*-------------------------------------
    Handle old Mouse Clicks
    -------------------------------------*/
    for( auto click = activeMouseButtons.begin(); click != activeMouseButtons.end(); )
        {
        if( IsMouseButtonUp( *click ) )
            {
            events.push( event( in_MOUSE, *click, cords( GetMouseX(), GetMouseY() ), action_MOUSE_RELEASED )  );
            click = activeMouseButtons.erase( click );
            }
        else{
            click++;
            }
        }

        
    /*-------------------------------------
    Have Screen Handle Inputs
    -------------------------------------*/
    while( !events.empty() )
        {
        current_screen->handleInputEvent( events.front() );
        events.pop();
        }



    //TODO: add gamepad support
}
