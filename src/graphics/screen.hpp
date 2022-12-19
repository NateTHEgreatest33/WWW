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
#include "screen.hpp"
#include <unordered_map>
#include <functional>
#include <iostream>

#include "../entities/entity.hpp"
#include "../include/raylib.h"
#include "../utl/common_types.hpp"
#include "../gameplay/event.hpp"

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

template <typename T>
class screen 
    {
    protected:
    std::unordered_map< std::string, entity* > p_currentObjects;
    
    std::string p_screen_name;

    T p_background;
    Texture2D p_textureBackground;

    int p_screenHeight;
    int p_screenWidth;

    private:
   
    public:

    screen( const std::string name, T background, int screenH, int screenW);

    ~screen();

    void drawObjs( void );

    void drawBackground( void );

    void handleGraphicEvent( graphics_msg event );

    void clearAllObj( void );

    void addObj( std::string id, entity* obj );

    void handleInputEvent( event action );

    void virtual handleLogic( void ) = 0;

    };


#include "screen.tpp"

#endif