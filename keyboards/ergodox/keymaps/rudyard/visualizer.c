/*
Copyright 2017 Fred Sundvik

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "simple_visualizer.h"

static uint8_t layer(uint8_t n) {
    return 1 << n;
}

static uint8_t is_layer(visualizer_state_t* state, uint8_t n) {
    return state->status.layer & layer(n);
}

// This function should be implemented by the keymap visualizer
// Don't change anything else than state->target_lcd_color and state->layer_text as that's the only thing
// that the simple_visualizer assumes that you are updating
// Also make sure that the buffer passed to state->layer_text remains valid until the previous animation is
// stopped. This can be done by either double buffering it or by using constant strings
static void get_visualizer_layer_and_color(visualizer_state_t* state) {
    uint8_t saturation = 0xFF;
    uint8_t intensity = 0xFF;
    uint8_t red = 0x00;
    // uint8_t cyan = 0x80;
    uint8_t blue = 0xAA;
    uint8_t magenta = 0xD5;
    uint8_t green = 0x55;
    // godspeed colors
    // uint32_t gs_blue = LCD_COLOR(200, 128, 140);
    // uint32_t gs_yellow = LCD_COLOR(55, 0xFF, 115);
    // uint32_t gs_red = LCD_COLOR(0, 0xFF, 115);

    if (state->status.leds & (1u << USB_LED_CAPS_LOCK)) {
        saturation = 255;
    }
    if (is_layer(state, 4)) {
        state->target_lcd_color = LCD_COLOR(magenta, saturation, intensity);
        state->layer_text = "4";
    }
    else if (is_layer(state, 3)) {
        state->target_lcd_color = LCD_COLOR(green, 0xCC, intensity);
        state->layer_text = "3";
    }
    else if (is_layer(state, 2)) {
        state->target_lcd_color = LCD_COLOR(red, 0xCC, intensity);
        state->layer_text = "2";
    }
    else if (is_layer(state, 1)) {
        state->target_lcd_color = LCD_COLOR(blue, 0xCC, intensity);
        state->layer_text = "1";
    }
    else {
        state->target_lcd_color = LCD_COLOR(0x00, 0x00, intensity);
        state->layer_text = "0";
    }
}
