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
#define NO_ACTION_ONESHOT
#define NO_MUSIC_MODE

// enable NKRO by default
#define FORCE_NKRO

// many settings taken from https://github.com/filterpaper/qmk_userspace

// Tap-hold settings
#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD_PER_KEY
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

// Input intervals
#define QUICK_TAP_TERM TAPPING_TERM - 70
#define SHIFT_TAP_TERM TAPPING_TERM - 50
#define COMBO_IDLE_MS  TAPPING_TERM + 100
#define INPUT_IDLE_MS  QUICK_TAP_TERM

//
// underglow configuration
//

// no lights if we sleep
#define RGBLIGHT_SLEEP

// the modes we do use for lights
#define RGBLIGHT_EFFECT_BREATHING
