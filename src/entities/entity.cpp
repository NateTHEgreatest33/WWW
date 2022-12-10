/*********************************************************************
*
*   NAME:
*       entity.cpp
*
*   DESCRIPTION:
*       entity class
*
*   Copyright 2022 Nate Lenze
*
*********************************************************************/
/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "entity.hpp"
#include <algorithm>
#include <cmath>

/*--------------------------------------------------------------------
                          LITERAL CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                                TYPES
--------------------------------------------------------------------*/

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
                              PROCEDURES
--------------------------------------------------------------------*/

/*********************************************************************
*
*   PROCEDURE NAME:
*       entity (constructor)
*
*   DESCRIPTION:
*       entity class constructor
*
*********************************************************************/
entity::entity( cords cordinates, std::vector<hitRad> hitBox, bool visible, std::string name )
{
p_cordinates = cordinates;
p_hitPoints = hitBox;
p_visible   = visible;
p_name      = name;
} /* entity() */

entity::entity()
{
p_cordinates = cords(0,0);
p_visible = false;
p_name = "placeholder";

}

/*********************************************************************
*
*   PROCEDURE NAME:
*       entity (deconstructor)
*
*   DESCRIPTION:
*       entity class deconstructor
*
*********************************************************************/
entity::~entity()
{

} /* ~entity() */

/*********************************************************************
*
*   PROCEDURE NAME:
*       collision
*
*   DESCRIPTION:
*       determines if entity passed in has hit 
*
*********************************************************************/
bool entity::collision( entity other )
{
std::pair<cords, std::vector<hitRad>> info = other.getSpacingInfo();

for( hitRad hitBox : p_hitPoints )
    {
    if( std::all_of( info.second.begin(), info.second.end(), [this, &hitBox]( hitRad& current ){return this->isHit( hitBox, current); } ) )
        {
        return true;
        }
    }

return false;

} /* collision() */

/*********************************************************************
*
*   PROCEDURE NAME:
*       getSpacingInfo
*
*   DESCRIPTION:
*       returns XY cords 
*
*********************************************************************/
std::pair<cords, std::vector<hitRad>> entity::getSpacingInfo( void )
{
return std::make_pair( p_cordinates, p_hitPoints );

} /* getSpacingInfo() */

/*********************************************************************
*
*   PROCEDURE NAME:
*       x
*
*   DESCRIPTION:
*       x
*
*********************************************************************/
cords entity::getCords( void )
{
    return p_cordinates;
     
} /* getCords() */


void entity::toggleVisible()
{
p_visible = !p_visible;
}

void entity::setVisible( bool is_visible )
{
p_visible = is_visible;
}

bool entity::getVisible( void )
{
return p_visible;
}

void entity::setCords( cords cordinates ){
    p_cordinates = cordinates;
}

bool entity::isHit( hitRad& lhs, hitRad& rhs )
{
double distance = sqrt(  
                  pow(( lhs.cordinates.x - rhs.cordinates.x ), 2) +
                  pow(( lhs.cordinates.y - rhs.cordinates.y ), 2) );

if( distance < ( lhs.rad + rhs.rad ) )
    return true;

return false;
}



//remove once defined
void entity::draw( void ){}
void entity::actionKeyboard( KeyboardKey action ){}
void entity::actionMouse( GamepadButton action ){}
void entity::actionGamepad( MouseButton action ){}