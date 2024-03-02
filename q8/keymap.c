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

// Returns true if `pos` on the left hand of the keyboard, false if right.
static bool on_left_hand(keypos_t pos) {
  return pos.col < 7;
}

// layout helper macro, we just use 34 keys
#undef LAYOUT
#define LAYOUT(\
K00,   K01,   K02,   K03,   K04,                 K05,   K06,   K07,   K08,   K09,\
K10,   K11,   K12,   K13,   K14,                 K15,   K16,   K17,   K18,   K19,\
K20,   K21,   K22,   K23,   K24,                 K25,   K26,   K27,   K28,   K29,\
                     K30,   K31,                 K32,   K33\
)\
LAYOUT_iso_70(\
        KC_ESC,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,     KC_7,     KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_MUTE,\
        KC_TAB,  K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,     KC_LBRC,  KC_RBRC,                    KC_DEL,\
        KC_CAPS, K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17,   K18,   K19,  KC_QUOT,  KC_NUHS,  KC_ENT,           KC_HOME,\
        KC_LSFT, K20,   K21,   K22,   K23,   K24,   KC_NO, KC_NO, K25,   K26,   K27,   K28,   K29,  KC_RSFT, KC_UP,\
        KC_LCTL, KC_LOPT,  K30,           K31,           K30, K33,          K32,            K33,            KC_LEFT, KC_DOWN, KC_RGHT\
)

// our shared 34 keys keymap
#include "../common/keymap.h"
