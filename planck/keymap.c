/* Copyright 2022 Christoph Cullmann
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

// layout helper macro, we just use 42 keys
#undef LAYOUT
#define LAYOUT(\
K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K10,   K11,\
K12,   K13,   K14,   K15,   K16,   K17,   K18,   K19,   K20,   K21,   K22,   K23,\
K24,   K25,   K26,   K27,   K28,   K29,   K30,   K31,   K32,   K33,   K34,   K35,\
                     K36,   K37,   K38,   K39,   K40,   K41\
)\
LAYOUT_ortho_4x12(\
K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K10,   K11,\
K12,   K13,   K14,   K15,   K16,   K17,   K18,   K19,   K20,   K21,   K22,   K23,\
K24,   K25,   K26,   K27,   K28,   K29,   K30,   K31,   K32,   K33,   K34,   K35,\
KC_NO, KC_NO, KC_NO, K36,   K37,   K38,   K39,   K40,   K41,   KC_NO, KC_NO, KC_NO\
)

// our shared 42 keys keymap
#include "../common/keymap.h"

void keyboard_post_init_user(void) {
    // always use the same effect
    rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
    rgblight_set_speed_noeeprom(2);

    // trigger init of layer state
    layer_state_set_user(layer_state);
}

// handle layer changes for backlight
layer_state_t layer_state_set_user(layer_state_t state) {
    const uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case _BASE:
            rgblight_sethsv_noeeprom(HSV_WHITE);
            break;

        case _SYM:
            rgblight_sethsv_noeeprom(HSV_RED);
            break;

        case _NUM:
            rgblight_sethsv_noeeprom(HSV_GREEN);
            break;

        case _FN:
            rgblight_sethsv_noeeprom(HSV_BLUE);
            break;

        case _NAV:
            rgblight_sethsv_noeeprom(HSV_GOLD);
            break;

        default:
            break;
    }

    return state;
}
