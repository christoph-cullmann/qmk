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
    KC_B,         KC_F,         KC_L,         KC_K,         KC_Q,            KC_P,             KC_G,         KC_O,         KC_U,         KC_DOT,
    RALT_T(KC_N), LALT_T(KC_S), LCTL_T(KC_H), LSFT_T(KC_T), KC_M,            KC_Y,             RSFT_T(KC_C), RCTL_T(KC_A), LALT_T(KC_E), RALT_T(KC_I),
    KC_X,         KC_V,         KC_J,         LGUI_T(KC_D), KC_Z,            KC_QUOT,          RGUI_T(KC_W), KC_SCLN,      KC_SLSH,      KC_COMM,
                                              MO(_SYM),     LT(_NUM, KC_R),  LT(_NAV, KC_SPC), MO(_FN)
),

[_NUM] = LAYOUT(
    XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      QK_RBT,          KC_LBRC,          KC_7,         KC_8,         KC_9,         KC_RBRC,
    KC_RALT,      KC_LALT,      KC_LCTL,      KC_LSFT,      XXXXXXX,         KC_EQL,           KC_4,         KC_5,         KC_6,         KC_SLSH,
    XXXXXXX,      XXXXXXX,      XXXXXXX,      KC_LGUI,      XXXXXXX,         KC_BSLS,          KC_1,         KC_2,         KC_3,         KC_GRV,
                                              XXXXXXX,      XXXXXXX,         KC_MINS,          KC_0
),

[_NAV] = LAYOUT(
    XXXXXXX,      KC_PGUP,      KC_UP,        KC_PGDN,      XXXXXXX,         QK_RBT,           XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
    KC_HOME,      KC_LEFT,      KC_DOWN,      KC_RGHT,      KC_END,          XXXXXXX,          KC_RSFT,      KC_RCTL,      KC_LALT,      KC_RALT,
    XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,         XXXXXXX,          KC_RGUI,      XXXXXXX,      XXXXXXX,      XXXXXXX,
                                              KC_TAB,       KC_ENT,          XXXXXXX,          XXXXXXX
),

[_SYM] = LAYOUT(
    XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      QK_BOOT,         KC_LCBR,          KC_AMPR,      KC_ASTR,      KC_LPRN,      KC_RCBR,
    KC_RALT,      KC_LALT,      KC_LCTL,      KC_LSFT,      XXXXXXX,         KC_PLUS,          KC_DLR,       KC_PERC,      KC_CIRC,      KC_QUES,
    XXXXXXX,      XXXXXXX,      XXXXXXX,      KC_LGUI,      XXXXXXX,         KC_PIPE,          KC_EXLM,      KC_AT,        KC_HASH,      KC_TILD,
                                              XXXXXXX,      XXXXXXX,         KC_UNDS,          KC_RPRN
),

[_FN] = LAYOUT(
    KC_F12,       KC_F7,        KC_F8,        KC_F9,        KC_PSCR,         QK_BOOT,          XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
    KC_F11,       KC_F4,        KC_F5,        KC_F6,        KC_DEL,          XXXXXXX,          KC_RSFT,      KC_RCTL,      KC_LALT,      KC_RALT,
    KC_F10,       KC_F1,        KC_F2,        KC_F3,        KC_INS,          XXXXXXX,          KC_RGUI,      XXXXXXX,      XXXXXXX,      XXXXXXX,
                                              KC_BSPC,      KC_ESC,          XXXXXXX,          XXXXXXX
)

};

// parts taken from https://github.com/filterpaper/qmk_userspace

// Convert 5-bit packed mod-tap modifiers to 8-bit packed MOD_MASK modifiers
#define MOD_TAP_GET_MOD_BITS(k) (((k) & 0x0f00) >> (((k) & 0x1000) ? 4 : 8))
// Basic keycode filter for tap-hold keys
#define GET_TAP_KEYCODE(k) ((k) & 0xff)

// Tap-hold decision helper macros
#define IS_LAYER_TAP(k)     (IS_QK_LAYER_TAP(k) && QK_LAYER_TAP_GET_LAYER(k))
#define IS_SHORTCUT(k)      (IS_QK_LAYER_TAP(k) && !QK_LAYER_TAP_GET_LAYER(k))
#define IS_MOD_TAP_SHIFT(k) (IS_QK_MOD_TAP(k) && (k) & (QK_LSFT))
#define IS_MOD_TAP_CAG(k)   (IS_QK_MOD_TAP(k) && (k) & (QK_LCTL|QK_LALT|QK_LGUI))

#define IS_HOMEROW(r) (r->event.key.row == 1 || r->event.key.row == 5)
#define IS_HOMEROW_SHIFT(k, r) (IS_HOMEROW(r) && IS_MOD_TAP_SHIFT(k))
#define IS_HOMEROW_CAG(k, r)   (IS_HOMEROW(r) && IS_MOD_TAP_CAG(k))

#define IS_TYPING(k) ((uint8_t)(k) <= KC_Z && last_input_activity_elapsed() < INPUT_IDLE_MS)

#define IS_UNILATERAL(r, n) ( \
    (r->event.key.row == 1 && on_left_hand(n.event.key)) || \
    (r->event.key.row == 5 && !on_left_hand(n.event.key)) )

static uint_fast16_t inter_keycode;
static keyrecord_t   inter_record;

bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
    static   bool  is_pressed[UINT8_MAX];
    uint16_t const tap_keycode = GET_TAP_KEYCODE(keycode);

    if (record->event.pressed) {
        // Press the tap keycode if the tap-hold key follows an alphabet key swiftly
        if ((IS_HOMEROW_CAG(keycode, record) || IS_SHORTCUT(keycode)) && IS_TYPING(inter_keycode)) {
            is_pressed[tap_keycode] = true;
            record->keycode         = tap_keycode;
        }
        // Cache incoming input for in-progress and subsequent tap-hold decisions
        inter_keycode = keycode;
        inter_record  = *record;
    }

    // Release the pressed tap keycode
    else if (is_pressed[tap_keycode]) {
        is_pressed[tap_keycode] = false;
        record->keycode         = tap_keycode;
    }

    return true;
}


bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    // Tap the mod-tap key with an overlapping non-Shift key on the same hand
    // or the shortcut key with any overlapping key
    if ((IS_UNILATERAL(record, inter_record) && !IS_MOD_TAP_SHIFT(inter_keycode)) || IS_SHORTCUT(keycode)) {
        record->tap.count++;
        process_record(record);
        return false;
    }

    // Activate layer hold with another key press
    else return IS_LAYER_TAP(keycode);
}


bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    // Enable Shift with a nested key press
    return IS_HOMEROW_SHIFT(keycode, record);
}


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    // Shorten interval for Shift
    return IS_HOMEROW_SHIFT(keycode, record) ? SHIFT_TAP_TERM : TAPPING_TERM;
}

#ifndef NO_LED

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

#endif

// Simplify unused magic config functions
#ifndef MAGIC_ENABLE
uint8_t mod_config(uint8_t mod) { return mod; }
uint16_t keycode_config(uint16_t keycode) { return keycode; }
#endif

// Reduce marix scanning delay
#ifndef DIRECT_PINS
void matrix_io_delay(void) { __asm__ volatile("nop\nnop\nnop\n"); }
#endif
