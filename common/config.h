/**
 * SPDX-FileCopyrightText: 2024 Christoph Cullmann <christoph@cullmann.io>
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#pragma once

// enable NKRO by default
#define FORCE_NKRO

// Reduce input latency by lowering the USB polling interval
// from its 10ms default to the 1ms minimum that USB 1.x (Full Speed) allows:
#define USB_POLLING_INTERVAL_MS 1

// try to be nice to the old switches I did harvest
#define DEBOUNCE 10

// Unfortunately, some applications drop or swap fast key events. This is a
// partial fix to slow down the rate at which macros are sent.
#define TAP_CODE_DELAY 5

// home row mods
#define CHORDAL_HOLD
#define PERMISSIVE_HOLD
#define TAPPING_TERM 180
#define TAPPING_TERM_SLOW 250
#define TAPPING_TERM_PER_KEY

// no auto repeat stuff
#define QUICK_TAP_TERM 0

//
// underglow configuration
//

// no lights if we sleep
#define RGBLIGHT_SLEEP

// the modes we do use for lights
#define RGBLIGHT_EFFECT_BREATHING
