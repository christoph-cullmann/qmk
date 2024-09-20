// Copyright @filterpaper
// Copyright Christoph Cullmann
// SPDX-License-Identifier: GPL-2.0+

// Basic keycode filter for tap-hold keys
#define GET_TAP_KEYCODE(k) ((k) & 0xff)

// Tap-hold decision helper macros
#define IS_LAYER_TAP(k)     (IS_QK_LAYER_TAP(k) && QK_LAYER_TAP_GET_LAYER(k))
#define IS_SHORTCUT(k)      (IS_QK_LAYER_TAP(k) && !QK_LAYER_TAP_GET_LAYER(k))
#define IS_MOD_TAP_SHIFT(k) (IS_QK_MOD_TAP(k) && (k) & (QK_LSFT))
#define IS_MOD_TAP_CAG(k)   (IS_QK_MOD_TAP(k) && (k) & (QK_LCTL|QK_LALT|QK_LGUI))

#define IS_HOMEROW(r)          (r->event.key.row == 1 || r->event.key.row == 5)
#define IS_HOMEROW_SHIFT(k, r) (IS_HOMEROW(r) && IS_MOD_TAP_SHIFT(k))
#define IS_HOMEROW_CAG(k, r)   (IS_HOMEROW(r) && IS_MOD_TAP_CAG(k))

#define IS_TYPING(k) ((uint8_t)(k) <= KC_Z && last_input_activity_elapsed() < QUICK_TAP_TERM)

#define IS_UNILATERAL(r, n) ( \
    (r->event.key.row == 1 && 0 <= n.event.key.row && n.event.key.row <= 2) || \
    (r->event.key.row == 5 && 4 <= n.event.key.row && n.event.key.row <= 6) )

#define IS_BILATERAL(r, n) ( \
    (r->event.key.row == 1 && 4 <= n.event.key.row && n.event.key.row <= 6) || \
    (r->event.key.row == 5 && 0 <= n.event.key.row && n.event.key.row <= 2) )

static uint_fast16_t inter_keycode;
static keyrecord_t   inter_record;

bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool     is_pressed[UINT8_MAX];
    const  uint16_t tap_keycode = GET_TAP_KEYCODE(keycode);

    if (record->event.pressed) {
        // Press the tap keycode if the tap-hold key follows the previous key swiftly
        if ((IS_HOMEROW_CAG(keycode, record) || IS_SHORTCUT(keycode)) && IS_TYPING(inter_keycode)) {
            is_pressed[tap_keycode] = true;
            record->keycode = tap_keycode;
        }
        // Cache incoming input for in-progress and subsequent tap-hold decisions
        inter_keycode = keycode;
        inter_record  = *record;
    }

    // Release the pressed tap keycode
    else if (is_pressed[tap_keycode]) {
        is_pressed[tap_keycode] = false;
        record->keycode = tap_keycode;
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
    return IS_MOD_TAP_SHIFT(keycode);
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    // Shorten interval for Shift
    return IS_HOMEROW_SHIFT(keycode, record) ? SHIFT_TAP_TERM : TAPPING_TERM;
}

// Simplify unused magic config functions
#ifndef MAGIC_ENABLE
uint8_t mod_config(uint8_t mod) { return mod; }
uint16_t keycode_config(uint16_t keycode) { return keycode; }
#endif

// Reduce marix scanning delay
#ifndef DIRECT_PINS
void matrix_io_delay(void) { __asm__ volatile("nop\nnop\nnop\n"); }
#endif
