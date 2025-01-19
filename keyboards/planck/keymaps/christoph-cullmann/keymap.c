/**
 * SPDX-FileCopyrightText: 2024 Christoph Cullmann <christoph@cullmann.io>
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include QMK_KEYBOARD_H

// layout helper macro, we just use 34 keys
#undef LAYOUT
#define LAYOUT(\
K00,   K01,   K02,   K03,   K04,                 K05,   K06,   K07,   K08,   K09,\
K10,   K11,   K12,   K13,   K14,                 K15,   K16,   K17,   K18,   K19,\
K20,   K21,   K22,   K23,   K24,                 K25,   K26,   K27,   K28,   K29,\
                     K30,   K31,                 K32,   K33\
)\
LAYOUT_ortho_4x12(\
K00,   K01,   K02,   K03,   K04,   KC_NO, KC_NO, K05,   K06,   K07,   K08,   K09,\
K10,   K11,   K12,   K13,   K14,   KC_NO, KC_NO, K15,   K16,   K17,   K18,   K19,\
K20,   K21,   K22,   K23,   K24,   KC_NO, KC_NO, K25,   K26,   K27,   K28,   K29,\
KC_NO, KC_NO, KC_NO, K30,   K31,   KC_NO, KC_NO, K32,   K33,   KC_NO, KC_NO, KC_NO\
)

// define handness manually, just to be sure
char chordal_hold_handedness(keypos_t key)
{
    return ((key.row < 3) || (key.row == 3 && key.col < 3) || (key.row == 7 && key.col > 2)) ? 'L' : 'R';
}

// our shared 42 keys keymap
#include "common/keymap.h"
