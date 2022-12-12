#ifndef COMMON_TYPES_HPP
#define COMMON_TYPES_HPP

typedef struct cords{
    int x;
    int y;
    cords(int xIn, int yIn) : x(xIn), y(yIn){}
    cords() : x(0), y(0){}
}cords;



#endif