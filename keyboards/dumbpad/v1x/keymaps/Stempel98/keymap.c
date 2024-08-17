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
    */
    [0] = LAYOUT(
                    TT(5),     TT(6),     TT(7),     TT(1),
                    KC_COPY,   KC_PSTE,   KC_CUT,    TT(2),
                    SCREEN_S,  CMD_SPC,   OPT_SPC,   TT(3),
        KC_MUTE,    KC_MPRV,   KC_MPLY,   KC_MNXT,   TT(4)
    ),

    [1] = LAYOUT(
                    _______,     _______,     _______,      TT(0),
                    _______,     _______,     _______,      KC_KP_PLUS,
                    _______,     _______,     _______,      KC_KP_MINUS,
        QK_LOCK,    _______,     _______,     _______,      KC_EQL
    ),

    [2] = LAYOUT(
                    _______,     _______,     _______,      TT(0),
                    _______,     _______,     _______,      KC_KP_PLUS,
                    _______,     _______,     _______,      KC_KP_MINUS,
        QK_LOCK,    _______,     _______,     _______,      KC_EQL
    ),

    [3] = LAYOUT(
                    _______,     _______,     _______,      TT(0),
                    _______,     _______,     _______,      KC_KP_PLUS,
                    _______,     _______,     _______,      KC_KP_MINUS,
        QK_LOCK,    _______,     _______,     _______,      KC_EQL
    ),

    [4] = LAYOUT(
                    _______,     _______,     _______,      TT(0),
                    _______,     _______,     _______,      KC_KP_PLUS,
                    _______,     _______,     _______,      KC_KP_MINUS,
        QK_LOCK,    _______,     _______,     _______,      KC_EQL
    ),

    [5] = LAYOUT(
                    _______,     _______,     _______,      TT(0),
                    _______,     _______,     _______,      KC_KP_PLUS,
                    _______,     _______,     _______,      KC_KP_MINUS,
        QK_LOCK,    _______,     _______,     _______,      KC_EQL
    ),

    [6] = LAYOUT(
                    _______,     _______,     _______,      TT(0),
                    _______,     _______,     _______,      KC_KP_PLUS,
                    _______,     _______,     _______,      KC_KP_MINUS,
        QK_LOCK,    _______,     _______,     _______,      KC_EQL
    ),

    [7] = LAYOUT(
                    _______,     _______,     _______,      TT(0),
                    _______,     _______,     _______,      KC_KP_PLUS,
                    _______,     _______,     _______,      KC_KP_MINUS,
        QK_LOCK,    _______,     _______,     _______,      KC_EQL
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case OPT_SPC:
            if (record->event.pressed) {
                // Naciśnij Option + Spacja
                register_code(KC_LALT);  // Option (Left Alt)
                tap_code(KC_SPC);        // Spacja
                unregister_code(KC_LALT);
            }
            break;
        case SCREEN_S:
            if (record->event.pressed) {
                register_code(KC_LGUI);   // Command (Left GUI)
                register_code(KC_LCTL);   // Control
                register_code(KC_LSFT);   // Shift
                tap_code(KC_4);           // 4
                unregister_code(KC_LGUI);
                unregister_code(KC_LCTL);
                unregister_code(KC_LSFT);
            }
            break;
        case CMD_SPC:
            if (record->event.pressed) {
                // Naciśnij Option + Spacja
                register_code(KC_LGUI);  // Option (Left Alt)
                tap_code(KC_SPC);        // Spacja
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
        switch (get_highest_layer(layer_state)) {
            case 0:
                // main layer - move mouse right (CW) and left (CCW)
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;

            case 1:
                // main layer - move mouse right (CW) and left (CCW)
                if (clockwise) {
                    tap_code(KC_BRIU);
                } else {
                    tap_code(KC_BRID);
                }
                break;

            case 2:
                // main layer - move mouse right (CW) and left (CCW)
                if (clockwise) {
                    tap_code(KC_MS_R);
                } else {
                    tap_code(KC_MS_L);
                }
                break;

            case 3:
                // main layer - move mouse right (CW) and left (CCW)
                if (clockwise) {
                    tap_code(KC_MS_R);
                } else {
                    tap_code(KC_MS_L);
                }
                break;

            case 4:
                // main layer - move mouse right (CW) and left (CCW)
                if (clockwise) {
                    tap_code(KC_MS_R);
                } else {
                    tap_code(KC_MS_L);
                }
                break;

            default:
                // other layers - =/+ (quals/plus) (CW) and -/_ (minus/underscore) (CCW)
                if (clockwise) {
                    tap_code(KC_EQL);
                } else {
                    tap_code(KC_MINS);
                }
                break;
        }
    }
    return true;
}
