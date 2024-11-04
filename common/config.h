/**
 * SPDX-FileCopyrightText: 2024 Christoph Cullmann <christoph@cullmann.io>
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#pragma once

// no more than 8 layers
#define LAYER_STATE_8BIT

// we don't have any lock switches
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

// deactivate more features
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
#define NO_MUSIC_MODE

// enable NKRO by default
#define FORCE_NKRO

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

//
// underglow configuration
//

// no lights if we sleep
#define RGBLIGHT_SLEEP

// the modes we do use for lights
#define RGBLIGHT_EFFECT_BREATHING
