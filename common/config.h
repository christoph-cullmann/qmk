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

// settings for home row modifiers
// details see https://precondition.github.io/home-row-mods

// detect typing streaks
#define ACHORDION_STREAK

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define QUICK_TAP_TERM 0

// home row mods
#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 180

// delay hold/release to not mess up software
#define TAP_CODE_DELAY 10

//
// underglow configuration
//

// no lights if we sleep
#define RGBLIGHT_SLEEP

// the modes we do use for lights
#define RGBLIGHT_EFFECT_BREATHING
