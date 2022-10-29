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

#include <iostream>

#include "graphics_msg.hpp"

class screen 
    {
    private:

    public:
    std::string screen_name;

    void virtual drawBackground( void ) = 0;

    void virtual drawObj( graphics_msg event ) = 0;

    void virtual removeObj( graphics_msg event ) = 0;

    void virtual clearAllObj( void ) = 0;

    };

#endif