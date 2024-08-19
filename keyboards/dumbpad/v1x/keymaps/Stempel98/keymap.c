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
    S_SHOOT,
    CTRL_CMD_Q,
    CMD_SPC,
    CMD_Z,
    CMD_A,
    CMD_S,
    COPY,
    PASTE,
    CUT,
    APP_1pass,
    APP_BW,
    CP_PASS_1pass,
    CP_OTP_PASS_1pass,
    QA_1pass,
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

    [0] = LAYOUT( // BASIC
                    TO(5),     TO(6),     TO(7),     TO(1),
                    COPY,      PASTE,     CUT,       TO(2),
                    S_SHOOT,   CMD_SPC,   OPT_SPC,   TO(3),
        KC_MUTE,    KC_MPRV,   KC_MPLY,   KC_MNXT,   TO(4)
    ),

    [1] = LAYOUT( // SHORTCUTS
                    CMD_A,         CMD_Z,                 CMD_S,        TO(0),
                    CP_PASS_1pass, CP_OTP_PASS_1pass,     QA_1pass,     _______,
                    COPY,          PASTE,                 CUT,          _______,
        CTRL_CMD_Q, KC_ESC,        _______,               _______,      _______
    ),

    [2] = LAYOUT( // APPS
                    APP_1pass,   APP_BW,      _______,      TO(0),
                    _______,     _______,     _______,      _______,
                    _______,     _______,     _______,      _______,
        QK_LOCK,    _______,     _______,     _______,      _______
    ),

    [3] = LAYOUT( // Layer_Name
                    _______,     _______,     _______,      TO(0),
                    _______,     _______,     _______,      _______,
                    _______,     _______,     _______,      _______,
        QK_LOCK,    _______,     _______,     _______,      _______
    ),

    [4] = LAYOUT( // Layer_Name
                    _______,     _______,     _______,      TO(0),
                    _______,     _______,     _______,      _______,
                    _______,     _______,     _______,      _______,
        QK_LOCK,    _______,     _______,     _______,      _______
    ),

    [5] = LAYOUT( // SSH
                    _______,     _______,     _______,      TO(0),
                    _______,     _______,     _______,      _______,
                    _______,     _______,     _______,      _______,
        QK_LOCK,    _______,     _______,     _______,      _______
    ),

    [6] = LAYOUT( // Layer_Name
                    _______,     _______,     _______,      TO(0),
                    _______,     _______,     _______,      _______,
                    _______,     _______,     _______,      _______,
        QK_LOCK,    _______,     _______,     _______,      _______
    ),

    [7] = LAYOUT( // Layer_Name
                    _______,     _______,     _______,      TO(0),
                    _______,     _______,     _______,      _______,
                    _______,     _______,     _______,      _______,
        QK_LOCK,    _______,     _______,     _______,      _______
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

        case S_SHOOT:
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

        case CTRL_CMD_Q:
            if (record->event.pressed) {
                // Control + Command + Q

                register_code(KC_LCTL);
                register_code(KC_LGUI);
                tap_code(KC_Q);
                unregister_code(KC_LCTL);
                unregister_code(KC_LGUI);
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

        case CMD_A:
            if (record->event.pressed) {
                // Command + V
                register_code(KC_LGUI);
                tap_code(KC_A);
                unregister_code(KC_LGUI);
            }
            break;

        case CMD_Z:
            if (record->event.pressed) {
                // Command + V
                register_code(KC_LGUI);
                tap_code(KC_Z);
                unregister_code(KC_LGUI);
            }
            break;

        case CMD_S:
            if (record->event.pressed) {
                // Command + V
                register_code(KC_LGUI);
                tap_code(KC_S);
                unregister_code(KC_LGUI);
            }
            break;

        case APP_1pass:
            if (record->event.pressed) {
                // Open 1Password
                register_code(KC_LGUI);
                tap_code(KC_SPC);
                unregister_code(KC_LGUI);
                 wait_ms(500);
                send_string("1Password");
                tap_code(KC_ENTER);
            }
                break;

        case CP_PASS_1pass:
            if (record->event.pressed) {
                //Copy Password from 1Password
                register_code(KC_LSFT);
                register_code(KC_LGUI);
                tap_code(KC_C);
                unregister_code(KC_LSFT);
                unregister_code(KC_LGUI);
            }
                break;

        case CP_OTP_PASS_1pass:
            if (record->event.pressed) {
                //Copy OTP_Password from 1Password
                register_code(KC_LOPT);
                register_code(KC_LGUI);
                tap_code(KC_C);
                unregister_code(KC_LOPT);
                unregister_code(KC_LGUI);
            }
                break;

        case QA_1pass:
            if (record->event.pressed) {
                //Copy Password from 1Password
                register_code(KC_LGUI);
                register_code(KC_LSFT);
                tap_code(KC_SPC);
                unregister_code(KC_LGUI);
                unregister_code(KC_LSFT);
            }
                break;

        case APP_BW:
            if (record->event.pressed) {
                // Open BitWarden
                register_code(KC_LGUI);
                tap_code(KC_SPC);
                unregister_code(KC_LGUI);
                 wait_ms(500);
                send_string("Bitwarden");
                tap_code(KC_ENTER);
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
                // Brightness Up and Down
                if (clockwise) {
                    tap_code(KC_BRIU);
                } else {
                    tap_code(KC_BRID);
                }
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            default:
                return true;
        }
    }
    return true;
}


