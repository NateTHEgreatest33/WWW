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
entity::entity(int x, int y, std::vector<hitRad> hitBox, bool visible )
{
p_xPos      = x;
p_yPos      = y;
p_hitPoints = hitBox;
p_visible   = visible;
} /* entity() */

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
bool result{0};
for( hitRad hitBox : p_hitPoints )
    {
    result = std::all_of( info.second.begin(), info.second.end(), [this, &hitBox]( hitRad& current ){return this->isHit( hitBox, current); } );

    if( result )
        return true;

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

} /* getCords() */


void entity::toggleVisible(){}

void entity::setVisible( bool is_visible ){}

void entity::getVisible( bool is_visible ){}

void entity::setCords( cords cordinates ){}

bool entity::isHit( hitRad& lhs, hitRad& rhs )
{
double distance = sqrt(  
                  pow(( lhs.cordinates.x - rhs.cordinates.x ), 2) +
                  pow(( lhs.cordinates.y - rhs.cordinates.y ), 2) );

if( distance < ( lhs.rad + rhs.rad ) )
    return true;

return false;
}