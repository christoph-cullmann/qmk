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

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ D E F I N I T I O N S                                                                                                  │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

// ┌─────────────────────────────────────────────────┐
// │ d e f i n e   l a y e r s                       │
// └─────────────────────────────────────────────────┘

enum my_layers {
  _QWERTY,
  _SYM,
  _NUM,
  _FN,
  _NAV
};

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ K E Y M A P S                                                                                                          │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT(
    KC_W,           KC_L,         KC_Y,         KC_P,             KC_B,             KC_Z,            KC_F,              KC_SCLN,            KC_U,           KC_QUOT,
     RALT_T(KC_C) ,  LALT_T(KC_R), LCTL_T(KC_S) ,  LSFT_T(KC_T) ,   LGUI_T(KC_G),             RGUI_T(KC_M),              RSFT_T(KC_N),      RCTL_T(KC_O),    LALT_T(KC_I) ,     RALT_T(KC_A),
   KC_Q ,   KC_J,          KC_V , KC_D ,     KC_K,             KC_X,             KC_H ,      KC_SLSH , KC_COMM,         KC_DOT ,
                                                MO(_SYM), LT(_NUM, KC_SPC),         LT(_NAV, KC_E),    MO(_FN)
),

[_SYM] = LAYOUT(
    XXXXXXX,        C(KC_X),      C(KC_C),      C(KC_V),          XXXXXXX,          KC_LCBR,         KC_AMPR,           KC_ASTR,         KC_LPRN,        KC_RCBR,
   KC_RALT,  KC_LALT,  KC_LCTL,  KC_LSFT,    KC_LGUI,        KC_PLUS,         KC_DLR,            KC_PERC,         KC_CIRC,        KC_COLN,
   XXXXXXX,        XXXXXXX,      XXXXXXX,      XXXXXXX,          XXXXXXX,          KC_PIPE,         KC_EXLM,           KC_AT,           KC_HASH,        KC_TILD,
                                      _______,           _______,           KC_UNDS,         KC_RPRN
),

[_NUM] = LAYOUT(
    XXXXXXX,        C(KC_X),      C(KC_C),      C(KC_V),          XXXXXXX,          KC_LBRC,         KC_7,              KC_8,            KC_9,           KC_RBRC,
    KC_RALT,  KC_LALT,  KC_LCTL,  KC_LSFT,    KC_LGUI,        KC_EQL,          KC_4,              KC_5,            KC_6,           KC_SCLN,
    XXXXXXX,        XXXXXXX,      XXXXXXX,      XXXXXXX,          XXXXXXX,          KC_BSLS,         KC_1,              KC_2,            KC_3,           KC_GRV,
                                              _______,           _______,           KC_MINS,         KC_0
),

[_FN] = LAYOUT(
    KC_F12,         KC_F7,        KC_F8,        KC_F9,            KC_PSCR,          QK_BOOT,         XXXXXXX,           XXXXXXX,         XXXXXXX,        XXXXXXX,
    KC_F11,         KC_F4,        KC_F5,        KC_F6,            KC_DEL,           KC_RGUI,         KC_RSFT,           KC_RCTL,         KC_LALT,        KC_RALT,
   KC_F10,         KC_F1,        KC_F2,        KC_F3,            KC_INS,           XXXXXXX,         XXXXXXX,           XXXXXXX,         XXXXXXX,        XXXXXXX,
                                            KC_BSPC,           KC_ESC,           _______,          _______
),

[_NAV] = LAYOUT(
    XXXXXXX,        KC_PGUP,      KC_UP,        KC_PGDN,          XXXXXXX,          QK_BOOT,         XXXXXXX,           XXXXXXX,         XXXXXXX,        XXXXXXX,
    KC_HOME,        KC_LEFT,      KC_DOWN,      KC_RGHT,          KC_END,            KC_RGUI,         KC_RSFT,           KC_RCTL,         KC_LALT,        KC_RALT,
  XXXXXXX,        XXXXXXX,      XXXXXXX,      XXXXXXX,          XXXXXXX,          XXXXXXX,         XXXXXXX,           XXXXXXX,         XXXXXXX,        XXXXXXX,
                                      KC_TAB,           KC_ENT,             _______,          _______
)

};

// try to be more permissive with holds for layer switch keys
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(_NUM, KC_SPC):
        case LT(_NAV, KC_E):
            // Immediately select the hold action when another key is tapped.
            return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}
