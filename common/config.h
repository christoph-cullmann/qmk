/**
 * SPDX-FileCopyrightText: 2024 Christoph Cullmann <christoph@cullmann.io>
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#pragma once

// enable NKRO by default
#define NKRO_DEFAULT_ON 1

// Reduce input latency by lowering the USB polling interval
// from its 10ms default to the 1ms minimum that USB 1.x (Full Speed) allows:
#define USB_POLLING_INTERVAL_MS 1

// Unfortunately, some applications drop or misorder fast key events. This is a
// partial fix to slow down the rate at which macros are sent.
#define TAP_CODE_DELAY 5

// home row mods - https://docs.qmk.fm/tap_hold
#define CHORDAL_HOLD
#define PERMISSIVE_HOLD
#define TAPPING_TERM 250
#define QUICK_TAP_TERM 0

// Time (in ms) for combo processing
#define COMBO_TERM 50

// we have no lock key
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

// tranfer enough info for the stuff we render on the OLEDs
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_MODS_ENABLE
#define SPLIT_OLED_ENABLE

// not more than 8 layers
#define LAYER_STATE_8BIT

// we use no one shot keys
#define NO_ACTION_ONESHOT

//
// RGB underglow
//

#ifdef RGBLIGHT_ENABLE

// no lights if we sleep
#define RGBLIGHT_SLEEP

// default mode
#define ENABLE_RGBLIGHT_MODE_CHRISTMAS
#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_CHRISTMAS

#endif

//
// per key RGB
//

#ifdef RGB_MATRIX_ENABLE

// no lights if we sleep
#define RGB_MATRIX_SLEEP

// default mode
#define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_CYCLE_LEFT_RIGHT

// maximal brightness
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200

#endif
