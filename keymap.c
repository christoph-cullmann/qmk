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

//
// improve home row modifiers via achordion
//

#include "achordion.h"

bool process_record_user(uint16_t keycode, keyrecord_t* record)
{
    if (!process_achordion(keycode, record)) {
        return false;
    }

    return true;
}

void matrix_scan_user(void)
{
    achordion_task();
}

static bool planck_bottom_row(keypos_t pos)
{
    return pos.row % (MATRIX_ROWS / 2) == 3;
}

// works only for rows 0-2 or 4-6
static bool planck_on_left_hand(keypos_t pos)
{
    // planck is like a split keyboard, beside for the last row
    return pos.row < MATRIX_ROWS / 2;
}

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record)
{
    // last row is special for the planck, just allow there everything
    if (planck_bottom_row(tap_hold_record->event.key)) {
        return true;
    }
    if (planck_bottom_row(other_record->event.key)) {
        return true;
    }

    // now both keys are in rows 0-2 or 4-6, there we can check the left hand with the simple helper
    return planck_on_left_hand(tap_hold_record->event.key) != planck_on_left_hand(other_record->event.key);
}

// our layers, used as index in layers and rgb lights
enum planck_layers {
  _QWERTY,
  _NUM,
  _NAV,
  _CMD,
  _FN,
  _SYM
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_planck_grid(
    KC_Q,         KC_W,         KC_E,         KC_R,             KC_T,             XXXXXXX, XXXXXXX, KC_Y,            KC_U,              KC_I,         KC_O,           KC_P,
    LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F),     KC_G,             XXXXXXX, XXXXXXX, KC_H,            RSFT_T(KC_J),      RCTL_T(KC_K), LALT_T(KC_L),   RGUI_T(KC_QUOT),
    KC_Z,         RALT_T(KC_X), KC_C,         KC_V,             KC_B,             XXXXXXX, XXXXXXX, KC_N,            KC_M,              KC_COMM,      RALT_T(KC_DOT), KC_SLSH,
    XXXXXXX,      XXXXXXX,      XXXXXXX,      LT(_NUM, KC_TAB), LT(_NAV, KC_SPC), XXXXXXX, XXXXXXX, LT(_FN, KC_ENT), LT(_SYM, KC_BSPC), XXXXXXX,      XXXXXXX,        XXXXXXX
),

[_NUM] = LAYOUT_planck_grid(
    KC_ESC,       XXXXXXX,      C(KC_X),      C(KC_C),          C(KC_V),          XXXXXXX, XXXXXXX, KC_1,            KC_2,              KC_3,         KC_4,           KC_5,
    KC_LGUI,      KC_LALT,      KC_LCTL,      KC_LSFT,          XXXXXXX,          XXXXXXX, XXXXXXX, KC_6,            KC_7,              KC_8,         KC_9,           KC_0,
    XXXXXXX,      KC_RALT,      XXXXXXX,      XXXXXXX,          XXXXXXX,          XXXXXXX, XXXXXXX, KC_MINS,         KC_EQL,            KC_BSLS,      KC_GRV,         KC_SCLN,
    XXXXXXX,      XXXXXXX,      XXXXXXX,      KC_TAB,           KC_SPC,           XXXXXXX, XXXXXXX, KC_ENT,          KC_BSPC,           XXXXXXX,      XXXXXXX,        XXXXXXX
),

[_NAV] = LAYOUT_planck_grid(
    KC_ESC,       XXXXXXX,      C(KC_X),      C(KC_C),          C(KC_V),          XXXXXXX, XXXXXXX, KC_PGUP,         KC_HOME,           KC_UP,        KC_END,         KC_DEL,
    KC_LGUI,      KC_LALT,      KC_LCTL,      KC_LSFT,          XXXXXXX,          XXXXXXX, XXXXXXX, KC_PGDN,         KC_LEFT,           KC_DOWN,      KC_RGHT,        KC_SCLN,
    XXXXXXX,      KC_RALT,      XXXXXXX,      XXXXXXX,          XXXXXXX,          XXXXXXX, XXXXXXX, KC_LCBR,         KC_RCBR,           KC_LBRC,      KC_RBRC,        KC_COLN,
    XXXXXXX,      XXXXXXX,      XXXXXXX,      KC_TAB,           KC_SPC,           XXXXXXX, XXXXXXX, KC_ENT,          KC_BSPC,           XXXXXXX,      XXXXXXX,        XXXXXXX
),

[_FN] = LAYOUT_planck_grid(
    KC_F1,        KC_F2,        KC_F3,        KC_F4,            KC_F5,            XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX,           XXXXXXX,      XXXXXXX,        QK_BOOT,
    KC_F6,        KC_F7,        KC_F8,        KC_F9,            KC_F10,           XXXXXXX, XXXXXXX, XXXXXXX,         KC_RSFT,           KC_RCTL,      KC_LALT,        KC_RGUI,
    KC_F11,       KC_F12,       XXXXXXX,      XXXXXXX,          KC_PSCR,          XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX,           XXXXXXX,      KC_RALT,        XXXXXXX,
    XXXXXXX,      XXXXXXX,      XXXXXXX,      KC_TAB,           KC_SPC,           XXXXXXX, XXXXXXX, KC_ENT,          KC_BSPC,           XXXXXXX,      XXXXXXX,        XXXXXXX
),

[_SYM] = LAYOUT_planck_grid(
    KC_EXLM,      KC_AT,        KC_HASH,      KC_DLR,           KC_PERC,          XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX,           XXXXXXX,      XXXXXXX,        QK_BOOT,
    KC_CIRC,      KC_AMPR,      KC_ASTR,      KC_LPRN,          KC_RPRN,          XXXXXXX, XXXXXXX, XXXXXXX,         KC_RSFT,           KC_RCTL,      KC_LALT,        KC_RGUI,
    KC_UNDS,      KC_PLUS,      KC_PIPE,      KC_TILD,          KC_COLN,          XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX,           XXXXXXX,      KC_RALT,        XXXXXXX,
    XXXXXXX,      XXXXXXX,      XXXXXXX,      KC_TAB,           KC_SPC,           XXXXXXX, XXXXXXX, KC_ENT,          KC_BSPC,           XXXXXXX,      XXXXXXX,        XXXXXXX
)

};

/* plwnck rev6 RGB layout:
 * ----------------------------------
 * |   6       5       4        3   |
 * |               0                |
 * |   7       8       1        2   |
 * ----------------------------------
 */

const rgblight_segment_t PROGMEM qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 8, HSV_WHITE}
);

const rgblight_segment_t PROGMEM num_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 8, HSV_YELLOW}
);

const rgblight_segment_t PROGMEM nav_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 8, HSV_WHITE}
);

const rgblight_segment_t PROGMEM fn_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 8, HSV_RED}
);

const rgblight_segment_t PROGMEM sym_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 8, HSV_BLUE}
);

const rgblight_segment_t * const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    [_QWERTY] = qwerty_layer,
    [_NUM] = num_layer,
    [_NAV] = nav_layer,
    [_FN] = fn_layer,
    [_SYM] = sym_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state)
{
    rgblight_set_layer_state(_NUM, layer_state_cmp(state, _NUM));
    rgblight_set_layer_state(_NAV, layer_state_cmp(state, _NAV));
    rgblight_set_layer_state(_FN, layer_state_cmp(state, _FN));
    rgblight_set_layer_state(_SYM, layer_state_cmp(state, _SYM));
    return state;
}
