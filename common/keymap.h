/**
 * SPDX-FileCopyrightText: 2024 Christoph Cullmann <christoph@cullmann.io>
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

// our layers
enum my_layers {
    _DEF,
    _NUM,
    _NAV,
    _SYM,
    _FUN
};

// keys with tap hold functions
enum my_tap_hold {
    CC_N = RALT_T(KC_N),
    CC_S = LALT_T(KC_S),
    CC_H = LCTL_T(KC_H),
    CC_T = LSFT_T(KC_T),
    CC_M = LGUI_T(KC_M),

    CC_Y = RGUI_T(KC_Y),
    CC_C = RSFT_T(KC_C),
    CC_A = RCTL_T(KC_A),
    CC_E = LALT_T(KC_E),
    CC_I = RALT_T(KC_I),

    CC_SYM = MO(_SYM),
    CC_NUM = LT(_NUM, KC_R),
    CC_NAV = LT(_NAV, KC_SPC),
    CC_FUN = MO(_FUN)
};

// our keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_DEF] = LAYOUT(
    KC_B,    KC_F,    KC_L,    KC_K,    KC_Q,    KC_P,    KC_G,    KC_O,    KC_U,    KC_DOT,
    CC_N,    CC_S,    CC_H,    CC_T,    CC_M,    CC_Y,    CC_C,    CC_A,    CC_E,    CC_I,
    KC_X,    KC_V,    KC_J,    KC_D,    KC_Z,    KC_QUOT, KC_W,    KC_SCLN, KC_SLSH, KC_COMM,
                               CC_SYM,  CC_NUM,  CC_NAV,  CC_FUN
),

[_NUM] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_RBT,  KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC,
    KC_RALT, KC_LALT, KC_LCTL, KC_LSFT, KC_LGUI, KC_EQL,  KC_4,    KC_5,    KC_6,    KC_SLSH,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS, KC_1,    KC_2,    KC_3,    KC_GRV,
                               XXXXXXX, XXXXXXX, KC_MINS, KC_0
),

[_NAV] = LAYOUT(
    XXXXXXX, KC_PGUP, KC_UP,   KC_PGDN, XXXXXXX, QK_RBT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  KC_RGUI, KC_RSFT, KC_RCTL, KC_LALT, KC_RALT,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                               KC_TAB,  KC_ENT,  XXXXXXX, XXXXXXX
),

[_SYM] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,
    KC_RALT, KC_LALT, KC_LCTL, KC_LSFT, KC_LGUI, KC_PLUS, KC_DLR,  KC_PERC, KC_CIRC, KC_QUES,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PIPE, KC_EXLM, KC_AT,   KC_HASH, KC_TILD,
                               XXXXXXX, XXXXXXX, KC_UNDS, KC_RPRN
),

[_FUN] = LAYOUT(
    KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_DEL,  KC_RGUI, KC_RSFT, KC_RCTL, KC_LALT, KC_RALT,
    KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_INS,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                               KC_BSPC, KC_ESC,  XXXXXXX, XXXXXXX
)

};

#ifdef FLOW_TAP_TERM
uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t* record,
                           uint16_t prev_keycode) {
  // Only apply Flow Tap when following a letter key, and not hotkeys.
  if (get_tap_keycode(prev_keycode) <= KC_Z &&
      (get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) == 0) {
    switch (keycode) {
        // home row
        case CC_N:
        case CC_S:
        case CC_H:
        case CC_T:
        case CC_M:
        case CC_Y:
        case CC_C:
        case CC_A:
        case CC_E:
        case CC_I:
            return FLOW_TAP_TERM;

        default:
            return 0;
    }
  }

  return 0;  // Disable Flow Tap otherwise.
}
#endif  // FLOW_TAP_TERM

void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_ENABLE
    // underglow
    rgblight_mode_noeeprom(RGBLIGHT_DEFAULT_MODE);
#endif

#ifdef RGB_MATRIX_ENABLE
    // per-key
    rgb_matrix_mode_noeeprom(RGB_MATRIX_DEFAULT_MODE);
#endif
}

bool get_speculative_hold(uint16_t keycode, keyrecord_t* record) {
  return true;  // Enable for all mods.
}
