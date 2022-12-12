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

template <typename T>
class main_menu : public screen
    {
    private:
    //https://www.educative.io/courses/cpp-standard-library-including-cpp-14-and-cpp-17/gkDqXZlVq4l
    std::unordered_map< std::string, entity* > p_currentObjects;
    std::string p_screen_name;
    T p_background;
    Texture2D p_textureBackground;
    int screenHeight;
    int screenWidth;

    void drawObjs( void );

    public:
    
    main_menu( const std::string name, const T background, int screenH, int screenW );

    main_menu();

    ~main_menu();

    void drawBackground( void );

    void handleEvent( graphics_msg event );
    
    void addObj( std::string id, entity* obj );

    void clearAllObj( void );

    void handleInput( cords cordinates );

    void handleLogic( void );

    };

#include "main_menu.tpp"
#endif