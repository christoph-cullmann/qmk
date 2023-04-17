/*
                                             ▀▀▀▀▀     ▀▀▀▀▀          ▀▀█▀▀
                                             ▄▀▀▀▄  ▄  ▄▀▀▀▄  ▄  ▄▀▀▀▄  █  ▄▀▀▀▄
                                             █   █  █  █   █  █  █   █  █  █   █
                                              ▀▀▀   █   ▀▀▀   █   ▀▀▀   ▀   ▀▀▀
                                                    █      ▄▄▄█▄▄▄    █   █  
                                                    ▀      █  █  █     █▄█
                                                  ▀▀▀▀▀    █  █  █      ▀   
                                                           ▀  ▀  ▀  D E F A U L T  
                                                                                                                                  
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
*/

#include QMK_KEYBOARD_H

#include "totem.h"

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ D E F I N I T I O N S                                                                                                  │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

// ┌─────────────────────────────────────────────────┐
// │ d e f i n e   l a y e r s                       │
// └─────────────────────────────────────────────────┘ 

enum totem_layers {
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
    KC_W,           KC_L,         KC_Y,         KC_P,             KC_B,             KC_Z,            KC_F,              KC_O,            KC_U,           KC_QUOT,
     KC_C ,  KC_R ,  KC_S ,  KC_T ,   KC_G,             KC_M,              KC_N ,      KC_E ,     KC_I ,     KC_A ,
   KC_LSFT,  KC_Q ,   KC_J,          KC_V , KC_D ,     KC_K,             KC_X,             KC_H ,      KC_SLSH , KC_COMM,         KC_DOT ,KC_RSFT,
                                                MO(_NUM),           KC_SPC,  MO(_SYM),         MO(_FN),          KC_BSPC,  MO(_NAV)
),

[_SYM] = LAYOUT(
    XXXXXXX,        C(KC_X),      C(KC_C),      C(KC_V),          XXXXXXX,          KC_LCBR,         KC_AMPR,           KC_ASTR,         KC_LPRN,        KC_RCBR,
   OSM(MOD_LGUI),  OSM(MOD_LALT),  OSM(MOD_LCTL),  OSM(MOD_LSFT),    OSM(MOD_RALT),        KC_PLUS,         KC_DLR,            KC_PERC,         KC_CIRC,        KC_COLN,
   KC_LSFT,   XXXXXXX,        XXXXXXX,      KC_LGUI,      KC_RALT,          XXXXXXX,          KC_PIPE,         KC_EXLM,           KC_AT,           KC_HASH,        KC_TILD,KC_RSFT,
                                      _______,           _______,           _______,           KC_UNDS,         KC_LPRN, KC_RPRN
),

[_NUM] = LAYOUT(
    XXXXXXX,        C(KC_X),      C(KC_C),      C(KC_V),          XXXXXXX,          KC_LBRC,         KC_7,              KC_8,            KC_9,           KC_RBRC,
    OSM(MOD_LGUI),  OSM(MOD_LALT),  OSM(MOD_LCTL),  OSM(MOD_LSFT),    OSM(MOD_RALT),        KC_EQL,          KC_4,              KC_5,            KC_6,           KC_SCLN,
    KC_LSFT,  XXXXXXX,        XXXXXXX,      KC_LGUI,      KC_RALT,          XXXXXXX,          KC_BSLS,         KC_1,              KC_2,            KC_3,           KC_GRV,KC_RSFT,
                                    _______,              _______,           _______,           KC_MINS,         KC_0, KC_DOT
),

[_FN] = LAYOUT(
    KC_F12,         KC_F7,        KC_F8,        KC_F9,            KC_PSCR,          QK_BOOT,         XXXXXXX,           XXXXXXX,         XXXXXXX,        XXXXXXX,
    KC_F11,         KC_F4,        KC_F5,        KC_F6,            KC_DEL,           OSM(MOD_RALT),         OSM(MOD_RSFT),           OSM(MOD_RCTL),         OSM(MOD_LALT),        OSM(MOD_RGUI),
   KC_LSFT,   KC_F10,         KC_F1,        KC_F2,        KC_F3,            KC_INS,           XXXXXXX,         KC_RALT,           KC_RGUI,         XXXXXXX,        XXXXXXX,KC_RSFT,
                                     KC_TAB,            KC_ENT,           KC_ESC,           _______,          _______, _______
),

[_NAV] = LAYOUT(
    XXXXXXX,        KC_PGUP,      KC_UP,        KC_PGDN,          XXXXXXX,          QK_BOOT,         XXXXXXX,           XXXXXXX,         XXXXXXX,        XXXXXXX,
    KC_HOME,        KC_LEFT,      KC_DOWN,      KC_RGHT,          KC_END,            OSM(MOD_RALT),         OSM(MOD_RSFT),           OSM(MOD_RCTL),         OSM(MOD_LALT),        OSM(MOD_RGUI),
  KC_LSFT,    XXXXXXX,        XXXXXXX,      XXXXXXX,      XXXXXXX,          XXXXXXX,          XXXXXXX,         KC_RALT,           KC_RGUI,         XXXXXXX,        XXXXXXX,KC_RSFT,
                                     KC_TAB,            KC_ENT,           KC_ESC,             _______,          _______, _______
)

};

/*
  ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸


                                                          ██████
                                                            ██  ▄▄▄▄
                                                            ██ ██▀▀██
                                                            ▀▀ ██▄▄██
                                                        ██████  ▀▀▀▀
                                                          ██ ▄▄▄▄▄▄
                                                          ██ ██▀▀▀▀
                                                          ██ ██████
                                                             ██▄▄▄▄
                                                             ▀▀▀▀▀▀
                                                           ████████
                                                           ██ ██ ██
                                                           ██ ██ ██
                                                           ▀▀ ▀▀ ▀▀
                                                          ████████

*/



