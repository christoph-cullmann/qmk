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

// our layers
enum my_layers {
  _BASE,
  _SYM,
  _NUM,
  _FN,
  _NAV,
  _MAGIC
};

// our keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT(
    KC_W,           KC_L,         KC_Y,         KC_P,             KC_B,             KC_Z,            KC_F,              OSL(_MAGIC),            KC_U,           KC_QUOT,
     RALT_T(KC_C) ,  LALT_T(KC_R), LCTL_T(KC_S) ,  LSFT_T(KC_T) ,   LGUI_T(KC_G),             RGUI_T(KC_M),              RSFT_T(KC_N),      RCTL_T(KC_O),    LALT_T(KC_I) ,     RALT_T(KC_A),
   KC_Q ,   KC_J,          KC_V , KC_D ,     KC_K,             KC_X,             KC_H ,      KC_SLSH , KC_COMM,         KC_DOT ,
                                                LT(_SYM, KC_SCLN), LT(_NUM, KC_SPC),         LT(_NAV, KC_E),    LT(_FN, KC_MINS)
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
),

[_MAGIC] = LAYOUT(
    XXXXXXX,        XXXXXXX,      XXXXXXX,      XXXXXXX,          XXXXXXX,          XXXXXXX,         XXXXXXX,           KC_CAPS,         XXXXXXX,        XXXXXXX,
    XXXXXXX,        XXXXXXX,      XXXXXXX,      XXXXXXX,          XXXXXXX,          XXXXXXX,         XXXXXXX,           XXXXXXX,         XXXXXXX,        XXXXXXX,
    XXXXXXX,        XXXXXXX,      XXXXXXX,      XXXXXXX,          XXXXXXX,          XXXXXXX,         XXXXXXX,           XXXXXXX,         XXXXXXX,        XXXXXXX,
                                                XXXXXXX,          XXXXXXX,          XXXXXXX,         XXXXXXX
)

};

#include "achordion.h"

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_achordion(keycode, record)) { return false; }
  return true;
}

void matrix_scan_user(void) {
  achordion_task();
}

// Returns true if `pos` on the left hand of the keyboard, false if right.
static bool on_left_hand(keypos_t pos) {
  // works not really on planck for bottom row, but we handle that differently
  return pos.row < MATRIX_ROWS / 2;
}

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
  // Also allow same-hand holds when the other key is in the rows below the
  // alphas. I need the `% (MATRIX_ROWS / 2)` because my keyboard is split.
  if (other_record->event.key.row % (MATRIX_ROWS / 2) >= 3) { return true; }

  // Otherwise, follow the opposite hands rule.
  return on_left_hand(tap_hold_record->event.key) !=
         on_left_hand(other_record->event.key);
}
