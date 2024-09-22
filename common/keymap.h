/**
 * SPDX-FileCopyrightText: 2024 Christoph Cullmann <christoph@cullmann.io>
 * SPDX-License-Identifier: GPL-2.0-or-later
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
    C(KC_X),      KC_V,         KC_L,         KC_H,         KC_K,         KC_Q,            KC_J,           KC_F,         KC_O,         KC_U,         KC_COMM,      KC_PSCR,
    C(KC_C),      RALT_T(KC_S), LALT_T(KC_R), LCTL_T(KC_N), LSFT_T(KC_T), KC_W,            KC_Y,           RSFT_T(KC_C), RCTL_T(KC_A), LALT_T(KC_E), RALT_T(KC_I), XXXXXXX,
    C(KC_V),      KC_Z,         KC_X,         KC_M,         LGUI_T(KC_D), KC_B,            KC_P,           RGUI_T(KC_G), KC_QUOT,      KC_SCLN,      KC_DOT,       XXXXXXX,
                                              MO(_SYM),     KC_SPC,       MO(_NUM),        MO(_NAV),       KC_BSPC,      MO(_FN)
),

[_NUM] = LAYOUT(
    _______,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      QK_RBT,          KC_LBRC,        KC_7,         KC_8,         KC_9,         KC_RBRC,      _______,
    _______,      KC_RALT,      KC_LALT,      KC_LCTL,      KC_LSFT,      XXXXXXX,         KC_EQL,         KC_4,         KC_5,         KC_6,         KC_SLSH,      _______,
    _______,      XXXXXXX,      XXXXXXX,      XXXXXXX,      KC_LGUI,      XXXXXXX,         KC_BSLS,        KC_1,         KC_2,         KC_3,         KC_GRV,       _______,
                                              XXXXXXX,      XXXXXXX,      XXXXXXX,         KC_MINS,        KC_0,         KC_DOT
),

[_NAV] = LAYOUT(
    _______,      XXXXXXX,      KC_PGUP,      KC_UP,        KC_PGDN,      XXXXXXX,         QK_RBT,         XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      _______,
    _______,      KC_HOME,      KC_LEFT,      KC_DOWN,      KC_RGHT,      KC_END,          XXXXXXX,        KC_RSFT,      KC_RCTL,      KC_LALT,      KC_RALT,      _______,
    _______,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,         XXXXXXX,        KC_RGUI,      XXXXXXX,      XXXXXXX,      XXXXXXX,      _______,
                                              KC_TAB,       KC_ENT,       XXXXXXX,         XXXXXXX,        XXXXXXX,      XXXXXXX
),

[_SYM] = LAYOUT(
    _______,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      QK_BOOT,         KC_LCBR,        KC_AMPR,      KC_ASTR,      KC_LPRN,      KC_RCBR,      _______,
    _______,      KC_RALT,      KC_LALT,      KC_LCTL,      KC_LSFT,      XXXXXXX,         KC_PLUS,        KC_DLR,       KC_PERC,      KC_CIRC,      KC_QUES,      _______,
    _______,      XXXXXXX,      XXXXXXX,      XXXXXXX,      KC_LGUI,      XXXXXXX,         KC_PIPE,        KC_EXLM,      KC_AT,        KC_HASH,      KC_TILD,      _______,
                                              XXXXXXX,      XXXXXXX,      XXXXXXX,         KC_UNDS,        KC_LPRN,      KC_RPRN
),

[_FN] = LAYOUT(
    _______,      KC_F12,       KC_F7,        KC_F8,        KC_F9,        XXXXXXX,         QK_BOOT,        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      _______,
    _______,      KC_F11,       KC_F4,        KC_F5,        KC_F6,        KC_DEL,          XXXXXXX,        KC_RSFT,      KC_RCTL,      KC_LALT,      KC_RALT,      _______,
    _______,      KC_F10,       KC_F1,        KC_F2,        KC_F3,        KC_INS,          XXXXXXX,        KC_RGUI,      XXXXXXX,      XXXXXXX,      XXXXXXX,      _______,
                                              KC_BSPC,      KC_ESC,       XXXXXXX,         XXXXXXX,        XXXXXXX,      XXXXXXX
)

};

// many settings taken from https://github.com/getreuer/qmk-keymap

#include "features/achordion.h"

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


uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  switch (tap_hold_keycode) {
    default:
      return 800;  // Use a timeout of 800 ms.
  }
}

uint16_t achordion_streak_chord_timeout(
    uint16_t tap_hold_keycode, uint16_t next_keycode) {
  // Disable streak detection on LT keys.
  if (IS_QK_LAYER_TAP(tap_hold_keycode)) {
    return 0;
  }

  // Otherwise, tap_hold_keycode is a mod-tap key.
  const uint8_t mod = mod_config(QK_MOD_TAP_GET_MODS(tap_hold_keycode));
  if ((mod & (MOD_LSFT | MOD_RSFT)) != 0) {
    return 100;  // A short streak timeout for Shift mod-tap keys.
  } else {
    return 220;  // A longer timeout otherwise.
  }
}

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
