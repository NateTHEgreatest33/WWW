/*********************************************************************
*
*   NAME:
*       graphics_msg.hpp
*
*   DESCRIPTION:
*       main messaging type for game processing
*
*   Copyright 2022 Nate Lenze
*
*********************************************************************/
#ifndef GRAPHIC_MSG_HPP
#define GRAPHIC_MSG_HPP

#include <any>
#include <string>

typedef int graphic_type;
enum{
    GRAPHIC_SCREEN,
    GRAPHIC_ENTITY,
    GRAPHIC_OTHER,

    GRAPHICS_NUM
    };


typedef struct graphics_msg
    {
    graphic_type type;
    std::string id;
    std::any graphic; //TODO: this should be a shared or unique ptr? that way when the graphics item is cleared or done, its cleared. 
    graphics_msg( graphic_type t, std::string i, std::any g ) : type(t), id(i), graphic(g){}

    } graphics_msg;


#endif