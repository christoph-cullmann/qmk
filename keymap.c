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

// map miryoku to our 4x12 grid
// we setup some extra keys in the holes
#define LAYOUT_miryoku(\
K00,   K01,   K02,   K03,   K04,                 K05,   K06,   K07,   K08,   K09,\
K10,   K11,   K12,   K13,   K14,                 K15,   K16,   K17,   K18,   K19,\
K20,   K21,   K22,   K23,   K24,                 K25,   K26,   K27,   K28,   K29,\
N30,   N31,   K32,   K33,   K34,                 K35,   K36,   K37,   N38,   N39\
)\
LAYOUT_ortho_4x12(\
K00,   K01,   K02,   K03,   K04,   KC_NO, KC_NO, K05,   K06,   K07,   K08,   K09,\
K10,   K11,   K12,   K13,   K14,   KC_NO, KC_NO, K15,   K16,   K17,   K18,   K19,\
K20,   K21,   K22,   K23,   K24,   KC_NO, KC_NO, K25,   K26,   K27,   K28,   K29,\
KC_NO, KC_NO, K32,   K33,   K34,   KC_NO, KC_NO, K35,   K36,   K37,   KC_NO, KC_NO\
)

// include miryoku defaults
#include <users/manna-harbour_miryoku/manna-harbour_miryoku.c>

//
// improve home row modifiers via achordion
//

#include "achordion.h"

bool process_record_user(uint16_t keycode, keyrecord_t* record)
{
    if (!process_achordion(keycode, record)) {
        return false;
    }

    return true;
}

void matrix_scan_user(void)
{
    achordion_task();
}

static bool planck_bottom_row(keypos_t pos)
{
    return pos.row % (MATRIX_ROWS / 2) == 3;
}

// works only for rows 0-2 or 4-6
static bool planck_on_left_hand(keypos_t pos)
{
    // planck is like a split keyboard, beside for the last row
    return pos.row < MATRIX_ROWS / 2;
}

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record)
{
    // last row is special for the planck, just allow there everything
    if (planck_bottom_row(tap_hold_record->event.key)) {
        return true;
    }
    if (planck_bottom_row(other_record->event.key)) {
        return true;
    }

    // now both keys are in rows 0-2 or 4-6, there we can check the left hand with the simple helper
    return planck_on_left_hand(tap_hold_record->event.key) != planck_on_left_hand(other_record->event.key);
}

//
// underglow configuration
//

/* plwnck rev6 RGB layout:
 * ----------------------------------
 * |   6       5       4        3   |
 * |               0                |
 * |   7       8       1        2   |
 * ----------------------------------
 */

const rgblight_segment_t PROGMEM white_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 8, HSV_WHITE}
);

const rgblight_segment_t PROGMEM blue_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 8, HSV_BLUE}
);

const rgblight_segment_t PROGMEM green_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 8, HSV_GREEN}
);

const rgblight_segment_t PROGMEM red_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 8, HSV_RED}
);

const rgblight_segment_t PROGMEM yellow_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 8, HSV_YELLOW}
);

const rgblight_segment_t * const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
  white_layer,
  blue_layer,
  green_layer,
  red_layer,
  yellow_layer
);

void keyboard_post_init_user(void)
{
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state)
{
    rgblight_set_layer_state(0, layer_state_cmp(state, NAV));
    rgblight_set_layer_state(1, layer_state_cmp(state, NUM));
    rgblight_set_layer_state(2, layer_state_cmp(state, SYM));
    rgblight_set_layer_state(3, layer_state_cmp(state, FUN));
    rgblight_set_layer_state(4, layer_state_cmp(state, MEDIA));
    rgblight_set_layer_state(4, layer_state_cmp(state, MOUSE));
    rgblight_set_layer_state(4, layer_state_cmp(state, BUTTON));
    return state;
}
