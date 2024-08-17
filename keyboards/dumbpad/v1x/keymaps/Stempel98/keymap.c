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
#include QMK_KEYBOARD_H

enum custom_keycodes {
    OPT_SPC = SAFE_RANGE,
    SCREEN_S,
    CMD_SPC,
    COPY,
    PASTE,
    CUT,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
            LAYER TEMPLATE
    /-----------------------------------------------------`
    |             |    X    |    X    |    X    |    X    |
    |             |---------|---------|---------|---------|
    |             |    X    |    X    |    X    |    X    |
    |             |---------|---------|---------|---------|
    |             |    X    |    X    |    X    |    X    |
    |-------------|---------|---------|---------|---------|
    |   Encoder   |    X    |    X    |    X    |    X    |
    \-----------------------------------------------------'

    Layer   LEDs
      0    0 0 0
      1    0 0 1
      2    0 1 0
      3    0 1 1
      4    1 0 0
      5    1 0 1
      6    1 1 0
      7    1 1 1

    */

    [0] = LAYOUT(
                    TO(5),     TO(6),     TO(7),     TO(1),
                    COPY,      PASTE,     CUT,       TO(2),
                    SCREEN_S,  CMD_SPC,   OPT_SPC,   TO(3),
        KC_MUTE,    KC_MPRV,   KC_MPLY,   KC_MNXT,   TO(4)
    ),

    [1] = LAYOUT(
                    _______,     _______,     _______,      KC_4,
                    _______,     _______,     _______,      KC_KP_MINUS,
                    _______,     _______,     _______,      TO(0),
        QK_LOCK,    _______,     _______,     _______,      KC_EQL
    ),

    [2] = LAYOUT(
                    _______,     _______,     _______,      KC_4,
                    _______,     _______,     _______,      KC_KP_MINUS,
                    _______,     _______,     _______,      TO(0),
        QK_LOCK,    _______,     _______,     _______,      KC_EQL
    ),

    [3] = LAYOUT(
                    _______,     _______,     _______,      KC_4,
                    _______,     _______,     _______,      KC_KP_MINUS,
                    _______,     _______,     _______,      TO(0),
        QK_LOCK,    _______,     _______,     _______,      KC_EQL
    ),

    [4] = LAYOUT(
                    _______,     _______,     _______,      KC_4,
                    _______,     _______,     _______,      KC_KP_MINUS,
                    _______,     _______,     _______,      TO(0),
        QK_LOCK,    _______,     _______,     _______,      KC_EQL
    ),

    [5] = LAYOUT(
                    KC_4,        _______,     _______,      KC_4,
                    _______,     _______,     _______,      KC_KP_MINUS,
                    _______,     _______,     _______,      TO(0),
        QK_LOCK,    _______,     _______,     _______,      KC_EQL
    ),

    [6] = LAYOUT(
                    _______,     _______,     _______,      KC_4,
                    _______,     _______,     _______,      KC_KP_MINUS,
                    _______,     _______,     _______,      TO(0),
        QK_LOCK,    _______,     _______,     _______,      KC_EQL
    ),

    [7] = LAYOUT(
                    _______,     _______,     _______,      KC_4,
                    _______,     _______,     _______,      KC_KP_MINUS,
                    _______,     _______,     _______,      TO(0),
        QK_LOCK,    _______,     _______,     _______,      KC_EQL
    ),
};

//MACROS
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case OPT_SPC:
            if (record->event.pressed) {
                // Option + Space
                register_code(KC_LALT);
                tap_code(KC_SPC);
                unregister_code(KC_LALT);
            }
            break;

        case SCREEN_S:
            if (record->event.pressed) {
                // Command + Control + Shift + 4
                register_code(KC_LGUI);
                register_code(KC_LCTL);
                register_code(KC_LSFT);
                tap_code(KC_4);
                unregister_code(KC_LGUI);
                unregister_code(KC_LCTL);
                unregister_code(KC_LSFT);
            }
            break;

        case CMD_SPC:
            if (record->event.pressed) {
                // Command + Space
                register_code(KC_LGUI);
                tap_code(KC_SPC);
                unregister_code(KC_LGUI);
            }
            break;

        case COPY:
            if (record->event.pressed) {
                // Command + C
                register_code(KC_LGUI);
                tap_code(KC_C);
                unregister_code(KC_LGUI);
            }
            break;

        case PASTE:
            if (record->event.pressed) {
                // Command + V
                register_code(KC_LGUI);
                tap_code(KC_V);
                unregister_code(KC_LGUI);
            }
            break;

        case CUT:
            if (record->event.pressed) {
                // Command + X
                register_code(KC_LGUI);
                tap_code(KC_X);
                unregister_code(KC_LGUI);
            }
            break;
    }
    return true;
}


void keyboard_post_init_user(void) {
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        uint8_t layer = get_highest_layer(layer_state);
        switch (layer) {
            case 0:
                // Volume Up and Down
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
            case 1:
                // Obsługuje inne działanie dla warstwy 1, jeśli jest to konieczne
                break;
            case 2:
                // Obsługuje inne działanie dla warstwy 2, jeśli jest to konieczne
                break;
            case 3:
                // Obsługuje inne działanie dla warstwy 3, jeśli jest to konieczne
                break;
            case 4:
                // Obsługuje inne działanie dla warstwy 4, jeśli jest to konieczne
                break;
            case 5:
                // Obsługuje inne działanie dla warstwy 5, jeśli jest to konieczne
                break;
            case 6:
                // Brightness Up and Down
                if (clockwise) {
                    tap_code(KC_BRIU);
                } else {
                    tap_code(KC_BRID);
                }
                break;
            case 7:
                // Obsługuje inne działanie dla warstwy 7, jeśli jest to konieczne
                break;
            default:
                // Upewnij się, że nie ma innych przypadków
                return true;
        }
    }
    return true;
}


