/* Copyright 2024 Christoph Cullmann
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

// home row mods and Co.
enum custom_keycodes {
    SMTD_KEYCODES_BEGIN = SAFE_RANGE,
    CKC_S,
    CKC_R,
    CKC_N,
    CKC_T,
    CKC_D,
    CKC_G,
    CKC_C,
    CKC_A,
    CKC_E,
    CKC_I,
    SMTD_KEYCODES_END,
};

// our keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT(
    XXXXXXX,      KC_V,         KC_L,         KC_H,         KC_K,         KC_Q,               KC_J,           KC_F,         KC_O,         KC_U,         KC_COMM,      XXXXXXX,
    XXXXXXX,      CKC_S,        CKC_R,        CKC_N,        CKC_T,        KC_W,               KC_Y,           CKC_C,        CKC_A,        CKC_E,        CKC_I,        XXXXXXX,
    XXXXXXX,      KC_Z,         KC_X,         KC_M,         CKC_D,        KC_B,               KC_P,           CKC_G,        KC_QUOT,      KC_SCLN,      KC_DOT,       XXXXXXX,
                                              MO(_SYM),     KC_SPC,       MO(_NUM),           MO(_NAV),       KC_BSPC,      MO(_FN)
),

[_NUM] = LAYOUT(
    XXXXXXX,      TO(_BASE),    C(KC_X),      C(KC_C),      C(KC_V),      XXXXXXX,   KC_LBRC,        KC_7,         KC_8,         KC_9,         KC_RBRC,       XXXXXXX,
    XXXXXXX,      KC_RALT,      KC_LALT,      KC_LCTL,      KC_LSFT,      XXXXXXX,         KC_EQL,         KC_4,         KC_5,         KC_6,         KC_SLSH, XXXXXXX,
    XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      KC_LGUI,      XXXXXXX,         KC_BSLS,        KC_1,         KC_2,         KC_3,         KC_GRV,  XXXXXXX,
                                              XXXXXXX,      XXXXXXX,   XXXXXXX,  XXXXXXX,           KC_MINS,        KC_0
),

[_NAV] = LAYOUT(
    XXXXXXX,      XXXXXXX,      KC_PGUP,      KC_UP,        KC_PGDN,      XXXXXXX,         QK_BOOT,        XXXXXXX,      XXXXXXX,      XXXXXXX,      TO(_BASE), XXXXXXX,
    XXXXXXX,      KC_HOME,      KC_LEFT,      KC_DOWN,      KC_RGHT,      KC_END,          XXXXXXX,        KC_RSFT,      KC_RCTL,      KC_LALT,      KC_RALT, XXXXXXX,
    XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,         XXXXXXX,        KC_RGUI,      XXXXXXX,      XXXXXXX,      XXXXXXX, XXXXXXX,
                                              KC_TAB,       KC_ENT,     XXXXXXX,  XXXXXXX,          XXXXXXX,        XXXXXXX
),

[_SYM] = LAYOUT(
    XXXXXXX,      TO(_BASE),    C(KC_X),      C(KC_C),      C(KC_V),      XXXXXXX,          KC_LCBR,        KC_AMPR,      KC_ASTR,      KC_LPRN,      KC_RCBR, XXXXXXX,
    XXXXXXX,      KC_RALT,      KC_LALT,      KC_LCTL,      KC_LSFT,      XXXXXXX,          KC_PLUS,        KC_DLR,       KC_PERC,      KC_CIRC,      KC_QUES, XXXXXXX,
    XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      KC_LGUI,      XXXXXXX,          KC_PIPE,        KC_EXLM,      KC_AT,        KC_HASH,      KC_TILD, XXXXXXX,
                                              XXXXXXX,      XXXXXXX,       XXXXXXX,  XXXXXXX,       KC_UNDS,        KC_RPRN
),

[_FN] = LAYOUT(
    XXXXXXX,      KC_F12,       KC_F7,        KC_F8,        KC_F9,        KC_PSCR,           QK_BOOT,        XXXXXXX,      XXXXXXX,      XXXXXXX,      TO(_BASE), XXXXXXX,
    XXXXXXX,      KC_F11,       KC_F4,        KC_F5,        KC_F6,        KC_DEL,            XXXXXXX,        KC_RSFT,      KC_RCTL,      KC_LALT,      KC_RALT, XXXXXXX,
    XXXXXXX,      KC_F10,       KC_F1,        KC_F2,        KC_F3,        KC_INS,            XXXXXXX,        KC_RGUI,      XXXXXXX,      XXXXXXX,      XXXXXXX, XXXXXXX,
                                              KC_BSPC,      KC_ESC,          XXXXXXX,  XXXXXXX,     XXXXXXX,        XXXXXXX
)

};

// home row mods and Co.
// include needs above custom_keycodes declared
#include "sm_td.h"

void on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
    switch (keycode) {
        SMTD_MT(CKC_S, KC_S, KC_RIGHT_ALT)
        SMTD_MT(CKC_R, KC_R, KC_LEFT_ALT)
        SMTD_MT(CKC_N, KC_N, KC_LEFT_CTRL)
        SMTD_MT(CKC_T, KC_T, KC_LSFT)
        SMTD_MT(CKC_D, KC_D, KC_LEFT_GUI)
        SMTD_MT(CKC_G, KC_G, KC_RIGHT_GUI)
        SMTD_MT(CKC_C, KC_C, KC_RSFT)
        SMTD_MT(CKC_A, KC_A, KC_RIGHT_CTRL)
        SMTD_MT(CKC_E, KC_E, KC_LEFT_ALT)
        SMTD_MT(CKC_I, KC_I, KC_RIGHT_ALT)
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_smtd(keycode, record)) {
        return false;
    }
    return true;
}
