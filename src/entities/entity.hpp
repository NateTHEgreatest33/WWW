/*********************************************************************
*
*   NAME:
*       entity.hpp
*
*   DESCRIPTION:
*       entity class
*
*   Copyright 2022 Nate Lenze
*
*********************************************************************/
#ifndef ENTITY_HPP
#define ENTITY_HPP
/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include <any>
#include <tuple>
#include <vector>
#include "../include/raylib.h"

/*--------------------------------------------------------------------
                          LITERAL CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                                TYPES
--------------------------------------------------------------------*/
typedef struct cords;
struct cords{
    int x;
    int y;
    cords(int xIn, int yIn) : x(xIn), y(yIn){}
};

typedef struct {
    cords cordinates;
    int rad;
}hitRad;
/*--------------------------------------------------------------------
                           MEMORY CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                          GLOBAL VARIABLES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              CLASSES
--------------------------------------------------------------------*/
class entity
{
public:

    entity(int x, int y, std::vector<hitRad> hitBox, bool visible );

    ~entity();

    bool collision( entity other );

    std::pair< cords, std::vector<hitRad>> getSpacingInfo( void );

    cords getCords( void );

    void toggleVisible();

    void setVisible( bool is_visible );

    bool getVisible( void );

    void setCords( cords cordinates );

    void virtual draw( void );

private:

    int p_xPos;
    int p_yPos;
    std::vector<hitRad> p_hitPoints;
    std::any p_image;
    bool p_visible;

    bool isHit( hitRad& lhs, hitRad& rhs );

};

#endif