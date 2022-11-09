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

class main_menu : screen
    {
    private:
    //https://www.educative.io/courses/cpp-standard-library-including-cpp-14-and-cpp-17/gkDqXZlVq4l
    std::unordered_map< std::string, std::function< void(int, int)> > _currentObjects;
    public:

    std::string screen_name;
    
    main_menu();

    ~main_menu();

    void drawBackground( void );

    void handleEvent( graphics_msg event );

    void clearAllObj( void );

    };

#endif