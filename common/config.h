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
// underglow configuration
//

#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)

// no lights if we sleep
#define RGBLIGHT_SLEEP

#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_BREATHING
#define RGB_MATRIX_DEFAULT_HUE 152
#define RGB_MATRIX_DEFAULT_SAT 232
#define RGB_MATRIX_DEFAULT_VAL 200
#define RGB_MATRIX_DEFAULT_SPD 50

#define RGB_MATRIX_FRAMEBUFFER_EFFECTS

#define ENABLE_RGB_MATRIX_SOLID_COLOR
#define ENABLE_RGB_MATRIX_ALPHAS_MODS
#define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#define ENABLE_RGB_MATRIX_BREATHING
#define ENABLE_RGB_MATRIX_BAND_SAT
#define ENABLE_RGB_MATRIX_BAND_VAL
#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#define ENABLE_RGB_MATRIX_CYCLE_ALL
#define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#define ENABLE_RGB_MATRIX_DUAL_BEACON
#define ENABLE_RGB_MATRIX_RAINBOW_BEACON
#define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#define ENABLE_RGB_MATRIX_RAINDROPS
#define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS

#endif
