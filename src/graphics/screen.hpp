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
#include <iostream>
#include <vector>

template <typename T, int M> //forgot how to use this
class screen 
    {
    private:
    std::vector<T> _drawnItems;
    public:
    std::string screen_name;

    void virtual drawBackground( void ) = 0;

    void virtual drawItem( T item ) = 0;

    };