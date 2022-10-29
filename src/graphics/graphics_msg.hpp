/*********************************************************************
*
*   NAME:
*       graphics_msg.hpp
*
*   DESCRIPTION:
*       main thread for game processing
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
    GRAPHIC_ITEM,
    GRAPHIC_OTHER,

    GRAPHICS_NUM
    };


typedef struct
    {
    graphic_type type;
    std::string id;
    std::any *graphic;
    } graphics_msg;


#endif