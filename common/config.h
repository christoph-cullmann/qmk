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

// many settings taken from https://github.com/getreuer/qmk-keymap

// don't confuse apps
#define TAP_CODE_DELAY 5

// home row mods
#define TAPPING_TERM 170
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD

// no auto repeat stuff
#define QUICK_TAP_TERM 0

// enable streak detection
#define ACHORDION_STREAK

// tranfer enough info for the stuff we render on the OLEDs
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_MODS_ENABLE
#define SPLIT_OLED_ENABLE

//
// underglow configuration
//

// no lights if we sleep
#define RGBLIGHT_SLEEP

// the modes we do use for lights
#define RGBLIGHT_EFFECT_BREATHING
