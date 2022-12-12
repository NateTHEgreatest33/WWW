/*********************************************************************
*
*   NAME:
*       event.hpp
*
*   DESCRIPTION:
*       main messaging type for game inputs
*
*   Copyright 2022 Nate Lenze
*
*********************************************************************/
#ifndef EVENT_HPP
#define EVENT_HPP

#include <variant>
#include "../utl/common_types.hpp"

typedef enum {
 in_MOUSE,
 in_GAMEPAD,
 in_KEYBOARD,

 in_NUM_INPUTS

} input_device;


typedef enum{
    action_KEY_PRESSED, //need to trigger a followup event to confirm if key is relased or mouse is released
    action_KEY_RELEASED,
    action_GAMEPAD_PRESSED,
    action_GAMEPAD_RELEASED,
    action_MOUSE_PRESSED,
    action_MOUSE_RELEASED



} input_action;


typedef struct event{
input_device input_type;
std::variant<KeyboardKey, MouseButton, GamepadButton> input_selection;
cords cordinates;
input_action action;
event( input_device device, std::variant<KeyboardKey, MouseButton, GamepadButton> input, cords c, input_action act ) : input_type( device ), input_selection( input ), cordinates(c), action( act ) {}
} event;

#endif