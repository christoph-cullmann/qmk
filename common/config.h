/**
 * SPDX-FileCopyrightText: 2024 Christoph Cullmann <christoph@cullmann.io>
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#pragma once

// got hit by key chatter with older switches
// better safe than sorry
#define DEBOUNCE 10

// home row mods - https://docs.qmk.fm/tap_hold
// https://github.com/getreuer/qmk-keymap/blob/main/config_getreuer.h
#define CHORDAL_HOLD
#define PERMISSIVE_HOLD
#define TAPPING_TERM 240
#define FLOW_TAP_TERM 100
#define QUICK_TAP_TERM 0

// enable caps word with pressing both shifts
// https://docs.qmk.fm/features/caps_word
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

// we have no lock key
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

// tranfer enough info for the stuff we render on the OLEDs
// https://docs.qmk.fm/features/split_keyboard
#define SPLIT_ACTIVITY_ENABLE
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_MODS_ENABLE
#define SPLIT_OLED_ENABLE

// try to ensure keyboard is properly alive
// https://docs.qmk.fm/features/split_keyboard
#define SPLIT_WATCHDOG_ENABLE

// not more than 8 layers
#define LAYER_STATE_8BIT

// disable more not used stuff
#define NO_ACTION_MACRO
#define NO_ACTION_ONESHOT
#define NO_ACTION_FUNCTION

//
// RGB underglow
//

#ifdef RGBLIGHT_ENABLE

// no lights if we sleep
#define RGBLIGHT_SLEEP

// default mode
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_BREATHING
#define RGBLIGHT_EFFECT_BREATHE_MAX 100

#endif

//
// per-key RGB
//

#ifdef RGB_MATRIX_ENABLE

// no lights if we sleep
#define RGB_MATRIX_SLEEP

// not too bright, if not already setup
#ifndef RGB_MATRIX_MAXIMUM_BRIGHTNESS
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 100
#endif

// default mode
#define ENABLE_RGB_MATRIX_STARLIGHT_DUAL_HUE
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_STARLIGHT_DUAL_HUE

#endif
