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
#include <unordered_map>
#include <functional>

#include "../include/raylib.h"

#include "../utl/common_types.hpp"
#include "../gameplay/event.hpp"


/*--------------------------------------------------------------------
                          LITERAL CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                                TYPES
--------------------------------------------------------------------*/

typedef enum {
 hit_CIRCLE,
 hit_SQUARE,
 hit_NUM
} hit_type;



typedef struct hitRad{
    hit_type hitbox_type;
    cords cordinates;
    int rad;
    int length;
    int height;
    hitRad( cords cord, int rad ) : cordinates( cord ), rad( rad ), length(0), height(0), hitbox_type( hit_CIRCLE ) {}
    hitRad( cords cord, int len, int height ) : cordinates( cord ), rad( 0 ), length(len), height(height), hitbox_type( hit_SQUARE ) {}
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

    void isHitAction( event action );

    void setHitbox( std::vector<hitRad> hitBox );

    void actionKeyboard( KeyboardKey input, input_action action );

    void actionMouse( MouseButton input, input_action action );

    void actionGamepad( GamepadButton input, input_action action );

    void initKeyboard( std::vector< std::pair< KeyboardKey, std::function<void(input_action)> > > inputList );

    void initMouse( std::vector< std::pair< MouseButton, std::function<void(input_action)> > > inputList );

    void initGamepad( std::vector< std::pair< GamepadButton, std::function<void(input_action)> > > inputList );

    void virtual draw( void ) = 0;


private:

    cords p_cordinates;
    std::vector<hitRad> p_hitPoints;
    std::any p_image;
    bool p_visible;
    std::string p_name;

    std::unordered_map< KeyboardKey, std::function<void(input_action)> > p_keyboardFunction;
    std::unordered_map< MouseButton, std::function<void(input_action)> > p_mouseFunction;
    std::unordered_map< GamepadButton, std::function<void(input_action)> > p_gamepadFunction;


    bool hitboxCollision( hitRad& lhs, hitRad& rhs );
    bool isHit( cords cordinates );
    bool isHitCircle( hitRad hitCircle, cords cord );
    bool isHitSquare( hitRad hitBox, cords cord );

};

#endif