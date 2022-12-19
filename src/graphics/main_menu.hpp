/*********************************************************************
*
*   NAME:
*       main_menu.hpp
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
//todo: rename main_menu to game screen
class main_menu : public screen
    {
    protected:
    T p_background;
    Texture2D p_textureBackground;
    
    private:

    public:
    
    main_menu( const std::string name, const T background, int screenH, int screenW );

    main_menu();

    ~main_menu();

    void handleGraphicEvent( graphics_msg event );
    
    void drawBackground( void ); 

    void handleLogic( void );

    };

#include "main_menu.tpp"
#endif