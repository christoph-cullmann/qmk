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

// layout helper macro, we just use 34 keys
#define LAYOUT_cullmann(\
K00,   K01,   K02,   K03,   K04,                 K05,   K06,   K07,   K08,   K09,\
K10,   K11,   K12,   K13,   K14,                 K15,   K16,   K17,   K18,   K19,\
K20,   K21,   K22,   K23,   K24,                 K25,   K26,   K27,   K28,   K29,\
                     K30,   K31,                 K32,   K33\
)\
LAYOUT(\
K00,   K01,   K02,   K03,   K04, K05,   K06,   K07,   K08,   K09,\
K10,   K11,   K12,   K13,   K14, K15,   K16,   K17,   K18,   K19,\
K20,   K21,   K22,   K23,   K24, K25,   K26,   K27,   K28,   K29,\
                     K30,   K31, K32,   K33\
)

// our layers, used as index in layers and rgb lights
enum planck_layers {
  L_CANARY,
  L_EXT,
  L_SYM,
  L_NUM,
  L_FUN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[L_CANARY] = LAYOUT_cullmann(
    KC_W,           KC_L,           KC_Y,           KC_P,             KC_B,             KC_Z,            KC_F,              KC_O,            KC_U,           KC_QUOT,
    KC_C,           KC_R,           KC_S,           KC_T,             KC_G,             KC_M,            KC_N,              KC_E,            KC_I,           KC_A,
    KC_Q,           KC_J,           KC_V,           KC_D,             KC_K,             KC_X,            KC_H,              KC_SLSH,         KC_COMM,        KC_DOT,
                                                    MO(L_EXT),        KC_SPC,           KC_RSFT,         MO(L_SYM)
),

[L_EXT] = LAYOUT_cullmann(
    KC_ESC,         LALT(KC_LEFT),  LCTL(KC_F),     LALT(KC_RGHT),    KC_INS,           KC_PGUP,         KC_HOME,           KC_UP,           KC_END,         KC_CAPS,
    OSM(MOD_LALT),  OSM(MOD_LGUI),  OSM(MOD_LSFT),  OSM(MOD_LCTL),    OSM(MOD_RALT),    KC_PGDN,         KC_LEFT,           KC_DOWN,         KC_RGHT,        KC_DEL,
    LCTL(KC_Z),     LCTL(KC_X),     LCTL(KC_C),     KC_LGUI,          LCTL(KC_V),       KC_ENT,          KC_BSPC,           KC_TAB,          KC_APP,         KC_PSCR,
                                                    KC_TRNS,          XXXXXXX,          KC_ENT,          MO(L_FUN)
),

[L_SYM] = LAYOUT_cullmann(
    KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,           KC_PERC,          KC_EQL,          KC_GRV,            KC_COLN,         KC_SCLN,        KC_PLUS,
    OSM(MOD_LALT),  OSM(MOD_LGUI),  OSM(MOD_LSFT),  OSM(MOD_LCTL),    KC_CIRC,          KC_ASTR,         KC_LPRN,           KC_LCBR,         KC_LBRC,        KC_MINS,
    KC_NUBS,        LSFT(KC_NUBS),  KC_NUHS,        LSFT(KC_NUHS),    KC_AMPR,          KC_TILD,         KC_RPRN,           KC_RCBR,         KC_RBRC,        KC_UNDS,
                                                    MO(L_FUN),        MO(L_NUM),        KC_ENT,          KC_TRNS
),

[L_NUM] = LAYOUT_cullmann(
    XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,          KC_NUM,           KC_EQL,          KC_7,              KC_8,            KC_9,           KC_PLUS,
    OSM(MOD_LALT),  OSM(MOD_LGUI),  OSM(MOD_LSFT),  OSM(MOD_LCTL),    OSM(MOD_RALT),    KC_ASTR,         KC_4,              KC_5,            KC_6,           KC_MINS,
    XXXXXXX,        KC_APP,         KC_TAB,         KC_BSPC,          KC_ENT,           KC_0,            KC_1,              KC_2,            KC_3,           KC_SLSH,
                                                    MO(L_FUN),        MO(L_NUM),        KC_ENT,          KC_TRNS
),

[L_FUN] = LAYOUT_cullmann(
    KC_MSTP,        KC_MPRV,        KC_MPLY,        KC_MNXT,          KC_BRIU,          KC_F12,          KC_F7,             KC_F8,           KC_F9,          QK_BOOT,
    OSM(MOD_LALT),  OSM(MOD_LGUI),  OSM(MOD_LSFT),  OSM(MOD_LCTL),    KC_BRID,          KC_F11,          KC_F4,             KC_F5,           KC_F6,          XXXXXXX,
    KC_MUTE,        KC_VOLD,        RCS(KC_C),      KC_VOLU,          RCS(KC_V),        KC_F10,          KC_F1,             KC_F2,           KC_F3,          XXXXXXX,
                                                    KC_TRNS,          XXXXXXX,          KC_ENT,          KC_TRNS
),

};
