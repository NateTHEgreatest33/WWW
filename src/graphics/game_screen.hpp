/*********************************************************************
*
*   NAME:
*       game_screen.hpp
*
*   DESCRIPTION:
*       main menu class for graphics
*
*   Copyright 2022 Nate Lenze
*
*********************************************************************/
#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP

#include "screen.hpp"
#include <unordered_map>
#include <functional>
#include "../entities/entity.hpp"
#include "../include/raylib.h"
#include "../utl/common_types.hpp"
#include "../gameplay/event.hpp"


template <typename T>
//todo: rename game_screen to game screen
class game_screen : public screen
    {
    protected:
    T p_background;
    Texture2D p_textureBackground;
    
    private:

    public:
    
    game_screen( const std::string name, const T background, int screenH, int screenW );

    game_screen();

    ~game_screen();

    void handleGraphicEvent( graphics_msg event );
    
    void drawBackground( void ); 

    void handleLogic( void );

    };

#include "game_screen.tpp"

#endif