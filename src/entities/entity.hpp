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
#include <utility>
#include <vector>
#include <iostream>
#include "../include/raylib.h"

/*--------------------------------------------------------------------
                          LITERAL CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                                TYPES
--------------------------------------------------------------------*/
typedef struct cords{
    int x;
    int y;
    cords(int xIn, int yIn) : x(xIn), y(yIn){}
    cords() : x(0), y(0){}
}cords;
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

    entity();

    entity( cords cordinates, std::vector<hitRad> hitBox, bool visible, std::string name );

    ~entity();

    bool collision( entity* other );

    std::pair< cords, std::vector<hitRad> > getSpacingInfo( void );

    cords getCords( void );

    void toggleVisible( void );

    void setVisible( bool is_visible );

    bool getVisible( void );

    void setCords( cords cordinates );

    void setHitbox( std::vector<hitRad> hitBox );

    void virtual draw( void ) = 0;
    void virtual actionKeyboard( KeyboardKey action );
    void virtual actionMouse( GamepadButton action );
    void virtual actionGamepad( MouseButton action );

private:

    cords p_cordinates;
    std::vector<hitRad> p_hitPoints;
    std::any p_image;
    bool p_visible;
    std::string p_name;

    bool isHit( hitRad& lhs, hitRad& rhs );

};

#endif