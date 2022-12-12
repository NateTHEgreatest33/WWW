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
#include "../utl/common_types.hpp"


/*--------------------------------------------------------------------
                          LITERAL CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                                TYPES
--------------------------------------------------------------------*/

typedef struct hitRad{
    cords cordinates;
    int rad;
    hitRad( cords cord, int rad ) : cordinates( cord ), rad( rad ) {}
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

    void isHitAction( cords cordinates );

    void setHitbox( std::vector<hitRad> hitBox );

    void virtual draw( void ) = 0;
    void virtual actionKeyboard( KeyboardKey action );
    void virtual actionMouse( MouseButton action );
    void virtual actionGamepad( GamepadButton action );
    void virtual initKeyboard( std::vector< std::pair< KeyboardKey, std::function<void()> > > inputList ) =0;
    void virtual initMouse( std::vector< std::pair< MouseButton, std::function<void()> > > inputList ) =0;
    void virtual initGamepad( std::vector< std::pair< GamepadButton, std::function<void()> > > inputList ) =0;

private:

    cords p_cordinates;
    std::vector<hitRad> p_hitPoints;
    std::any p_image;
    bool p_visible;
    std::string p_name;

    bool hitboxCollision( hitRad& lhs, hitRad& rhs );

};

#endif