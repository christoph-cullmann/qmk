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
  _FUN,
  _SUP,
  _HYP
};

// keys with tap hofd functions
#define CC_N RALT_T(KC_N)
#define CC_S LALT_T(KC_S)
#define CC_H LCTL_T(KC_H)
#define CC_T LSFT_T(KC_T)
#define CC_M LGUI_T(KC_M)

#define CC_Y RGUI_T(KC_Y)
#define CC_C RSFT_T(KC_C)
#define CC_A RCTL_T(KC_A)
#define CC_E LALT_T(KC_E)
#define CC_I RALT_T(KC_I)

#define CC_D LT(_SUP, KC_D)
#define CC_W LT(_HYP, KC_W)

#define CC_SYM LT(_SYM, KC_MINS)
#define CC_NUM LT(_NUM, KC_R)
#define CC_NAV LT(_NAV, KC_SPC)
#define CC_FUN LT(_FUN, KC_EQL)

// our keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_DEF] = LAYOUT(
    KC_B,    KC_F,    KC_L,    KC_K,    KC_Q,    KC_P,    KC_G,    KC_O,    KC_U,    KC_DOT,
    CC_N,    CC_S,    CC_H,    CC_T,    CC_M,    CC_Y,    CC_C,    CC_A,    CC_E,    CC_I,
    KC_X,    KC_V,    KC_J,    CC_D,    KC_Z,    KC_QUOT, CC_W,    KC_SCLN, KC_SLSH, KC_COMM,
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
),

[_SUP] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_LT,   KC_GT,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

[_HYP] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
)

};

#ifndef CC_NO_LED

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
        case _DEF:
            rgblight_sethsv_noeeprom(HSV_RED);
            break;

        case _NUM:
            rgblight_sethsv_noeeprom(HSV_GREEN);
            break;

        case _NAV:
            rgblight_sethsv_noeeprom(HSV_GOLD);
            break;

        case _SYM:
            rgblight_sethsv_noeeprom(HSV_WHITE);
            break;

        case _FUN:
            rgblight_sethsv_noeeprom(HSV_BLUE);
            break;

        case _SUP:
            rgblight_sethsv_noeeprom(HSV_YELLOW);
            break;

        case _HYP:
            rgblight_sethsv_noeeprom(HSV_CYAN);
            break;

        default:
            break;
    }

    return state;
}

#endif
