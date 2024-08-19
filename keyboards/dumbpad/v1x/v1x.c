/* Copyright 2020 imchipwood
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "quantum.h"

void keyboard_pre_init_kb(void) {
    // Set LED IO as outputs
    gpio_set_pin_output(LED_00);
    gpio_set_pin_output(LED_01);
    gpio_set_pin_output(LED_02);
    keyboard_pre_init_user();
}

bool shutdown_kb(bool jump_to_bootloader) {
    if (!shutdown_user(jump_to_bootloader)) {
        return false;
    }
    // Shutdown LEDs
    gpio_write_pin_low(LED_00);
    gpio_write_pin_low(LED_01);
    gpio_write_pin_low(LED_02);
    return true;
}

layer_state_t layer_state_set_kb(layer_state_t state) {
    uint8_t layer = get_highest_layer(state);
    gpio_write_pin(LED_00, layer & 0b001);  // Right LED
    gpio_write_pin(LED_01, (layer >> 1) & 0b001);  // Center LED
    gpio_write_pin(LED_02, (layer >> 2) & 0b001);  // Left LED

    return layer_state_set_user(state);
}

void matrix_init_kb(void) {
    // put your keyboard start-up code here
    // runs once when the firmware starts up
    uint8_t led_delay_ms = 80;
    for (int i = 0; i < 1; i++) {
        gpio_write_pin_high(LED_00);
        wait_ms(led_delay_ms);
        gpio_write_pin_high(LED_01);
        wait_ms(led_delay_ms);
        gpio_write_pin_high(LED_02);
        wait_ms(led_delay_ms);
        gpio_write_pin_high(LED_00);
        gpio_write_pin_high(LED_01);
        gpio_write_pin_high(LED_02);
        wait_ms(led_delay_ms);
        gpio_write_pin_low(LED_00);
        gpio_write_pin_low(LED_01);
        gpio_write_pin_low(LED_02);
        wait_ms(led_delay_ms);
        gpio_write_pin_high(LED_00);
        gpio_write_pin_high(LED_01);
        gpio_write_pin_high(LED_02);
        wait_ms(led_delay_ms);
        gpio_write_pin_low(LED_00);
        gpio_write_pin_low(LED_01);
        gpio_write_pin_low(LED_02);
        if (i < 1) {
            wait_ms(led_delay_ms);
        }
    }

    matrix_init_user();
}

bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) { return false; }

    if (index == 0) {
        switch (get_highest_layer(layer_state)) {
            case 0:
                break;

            default:
                break;
        }
    }
    return true;
}
