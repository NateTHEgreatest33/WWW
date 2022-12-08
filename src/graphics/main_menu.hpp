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

template <typename T>
class main_menu : public screen
    {
    private:
    //https://www.educative.io/courses/cpp-standard-library-including-cpp-14-and-cpp-17/gkDqXZlVq4l
    std::unordered_map< std::string, entity > _currentObjects;
    std::string screen_name;
    T p_background;
    int screenHeight;
    int screenWidth;

    void drawObjs( void );

    public:
    
    main_menu( const std::string name, const std::any background, int screenH, int screenW );

    main_menu();

    ~main_menu();

    void drawBackground( void );

    void handleEvent( graphics_msg event );
    
    void addObj( entity obj );

    void clearAllObj( void );

    void handleInput( void );

    void handleLogic( void );

    };

#include "main_menu.tpp"
#endif