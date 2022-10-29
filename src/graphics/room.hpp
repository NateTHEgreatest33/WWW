/*********************************************************************
*
*   NAME:
*       room.hpp
*
*   DESCRIPTION:
*       room class for graphics
*
*   Copyright 2022 Nate Lenze
*
*********************************************************************/
#include "screen.hpp"

template< typename T, int M>
class room : screen<T, M> 
    {
    private:

    public:

    void drawBackground( void ) = 0;

    void drawItem( T item ) = 0;
    };