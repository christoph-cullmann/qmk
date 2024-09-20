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
  _NUM,
  _NAV,
  _SYM,
  _FN
};

// our keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT(
    XXXXXXX,      KC_V,         KC_L,         KC_H,         KC_K,         KC_Q,            KC_J,           KC_F,         KC_O,         KC_U,         KC_COMM,      XXXXXXX,
    XXXXXXX,      RALT_T(KC_S), LALT_T(KC_R), LCTL_T(KC_N), LSFT_T(KC_T), KC_W,            KC_Y,           RSFT_T(KC_C), RCTL_T(KC_A), LALT_T(KC_E), RALT_T(KC_I), XXXXXXX,
    XXXXXXX,      KC_Z,         KC_X,         KC_M,         LGUI_T(KC_D), KC_B,            KC_P,           RGUI_T(KC_G), KC_QUOT,      KC_SCLN,      KC_DOT,       XXXXXXX,
                                              MO(_SYM),     KC_SPC,       MO(_NUM),        MO(_NAV),       KC_BSPC,      MO(_FN)
),

[_NUM] = LAYOUT(
    XXXXXXX,      TO(_BASE),    C(KC_X),      C(KC_C),      C(KC_V),      XXXXXXX,         KC_LBRC,        KC_7,         KC_8,         KC_9,         KC_RBRC,       XXXXXXX,
    XXXXXXX,      KC_RALT,      KC_LALT,      KC_LCTL,      KC_LSFT,      XXXXXXX,         KC_EQL,         KC_4,         KC_5,         KC_6,         KC_SLSH, XXXXXXX,
    XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      KC_LGUI,      XXXXXXX,         KC_BSLS,        KC_1,         KC_2,         KC_3,         KC_GRV,  XXXXXXX,
                                              XXXXXXX,      XXXXXXX,      XXXXXXX,         KC_MINS,        KC_0,         KC_DOT
),

[_NAV] = LAYOUT(
    XXXXXXX,      XXXXXXX,      KC_PGUP,      KC_UP,        KC_PGDN,      XXXXXXX,         QK_BOOT,        XXXXXXX,      XXXXXXX,      XXXXXXX,      TO(_BASE), XXXXXXX,
    XXXXXXX,      KC_HOME,      KC_LEFT,      KC_DOWN,      KC_RGHT,      KC_END,          XXXXXXX,        KC_RSFT,      KC_RCTL,      KC_LALT,      KC_RALT, XXXXXXX,
    XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,         XXXXXXX,        KC_RGUI,      XXXXXXX,      XXXXXXX,      XXXXXXX, XXXXXXX,
                                              KC_TAB,       KC_ENT,       XXXXXXX,         XXXXXXX,        XXXXXXX,      XXXXXXX
),

[_SYM] = LAYOUT(
    XXXXXXX,      TO(_BASE),    C(KC_X),      C(KC_C),      C(KC_V),      XXXXXXX,         KC_LCBR,        KC_AMPR,      KC_ASTR,      KC_LPRN,      KC_RCBR, XXXXXXX,
    XXXXXXX,      KC_RALT,      KC_LALT,      KC_LCTL,      KC_LSFT,      XXXXXXX,         KC_PLUS,        KC_DLR,       KC_PERC,      KC_CIRC,      KC_QUES, XXXXXXX,
    XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      KC_LGUI,      XXXXXXX,         KC_PIPE,        KC_EXLM,      KC_AT,        KC_HASH,      KC_TILD, XXXXXXX,
                                              XXXXXXX,      XXXXXXX,      XXXXXXX,         KC_UNDS,        KC_LPRN,      KC_RPRN
),

[_FN] = LAYOUT(
    XXXXXXX,      KC_F12,       KC_F7,        KC_F8,        KC_F9,        KC_PSCR,         QK_BOOT,        XXXXXXX,      XXXXXXX,      XXXXXXX,      TO(_BASE), XXXXXXX,
    XXXXXXX,      KC_F11,       KC_F4,        KC_F5,        KC_F6,        KC_DEL,          XXXXXXX,        KC_RSFT,      KC_RCTL,      KC_LALT,      KC_RALT, XXXXXXX,
    XXXXXXX,      KC_F10,       KC_F1,        KC_F2,        KC_F3,        KC_INS,          XXXXXXX,        KC_RGUI,      XXXXXXX,      XXXXXXX,      XXXXXXX, XXXXXXX,
                                              KC_BSPC,      KC_ESC,       XXXXXXX,         XXXXXXX,        XXXXXXX,      XXXXXXX
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

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
  // follow the opposite hands rule.
  return on_left_hand(tap_hold_record->event.key) !=
         on_left_hand(other_record->event.key);
}

