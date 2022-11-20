/*********************************************************************
*
*   NAME:
*       main_menu.tpp
*
*   DESCRIPTION:
*       main menu class for graphics
*
*   Copyright 2022 Nate Lenze
*
*********************************************************************/
/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "main_menu.hpp"

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
template <typename T>
main_menu<T>::main_menu()
    {
        std::cout<<"hello world";
        //clean up memory
    }


template <>
main_menu<Image>::main_menu( const std::string name, std::any background )
    {
        screen_name = name;
        assert( background.type() != typeid(std::string) );
        p_background = LoadImage( std::any_cast< const char* >(background) );

    }

template <>
main_menu<Color>::main_menu( const std::string name, const std::any background )
    {
        assert( background.type() != typeid(Color) );
        screen_name = name;
        p_background = std::any_cast<Color>(background);
    }

template <typename T>
main_menu<T>::~main_menu()
    {
        std::cout<<"hello world";
        //clean up memory
    }

/*********************************************************************
*
*   PROCEDURE NAME:
*       drawBackground
*
*   DESCRIPTION:
*       runs through list of objects + backgrounds and draws
*
*********************************************************************/
template <typename T>
void main_menu<T>::drawBackground( void ){}

template <>
void main_menu<Image>::drawBackground( void )
{
/*----------------------------------------------------------
Local variables
----------------------------------------------------------*/

/*----------------------------------------------------------
Draw background image first
----------------------------------------------------------*/
ClearBackground( BLUE );
// ImageCrop(&background, (Rectangle){ 100, 10, 300, 300 });      // Crop an image piece
ImageResize(&p_background, 100, 100);
Texture2D texture = LoadTextureFromImage(p_background);
// ImageDraw( &background, 
//             background, 
//             (Rectangle){ 0, 0, (float)background.width, (float)background.height }, 
//             (Rectangle){ 30, 40, background.width*1.5f, background.height*1.5f }, 
//             BLANK );
//ImageDrawRectangle(&background, 10, 10, 100, 100, RAYWHITE );

DrawCircle( 50, 50, 50.0, RAYWHITE );

DrawTexture(texture, 200, 200, WHITE);

drawObjs();

}

template <typename T>
void main_menu<T>::handleEvent( graphics_msg event )
    {

    }

/*********************************************************************
*
*   PROCEDURE NAME:
*       clearAllObj
*
*   DESCRIPTION:
*       clears all objects on the screen except background object
*
*********************************************************************/
template <typename T>
void main_menu<T>::clearAllObj( void )
{
/*----------------------------------------------------------
remove objects that are not background
----------------------------------------------------------*/
for( auto drawObj : _currentObjects )
    {
    if( drawObj.first == "background ")
        continue;
    
    _currentObjects.erase( drawObj.first );
    }   
}



template <typename T>
void main_menu<T>::handleInput( void ){}

template <typename T>
void main_menu<T>::handleLogic( void ){}


template<typename T>
void main_menu<T>::drawObjs( void )
{
/*----------------------------------------------------------
Draw Objects
----------------------------------------------------------*/
for( auto drawObj : _currentObjects )
    {
    drawObj.second.draw();
    }

}