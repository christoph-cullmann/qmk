/* Copyright 2022 Christoph Cullmann
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

// not more than 8 layers
#define LAYER_STATE_8BIT

// try to be more permissive with holds, allows to trigger modifiers faster
#define PERMISSIVE_HOLD

// fix startup sound
#define AUDIO_INIT_DELAY

// normal startup sound
#define STARTUP_SONG SONG(PLANCK_SOUND)

// no music mode used
#define NO_MUSIC_MODE

// we don't need locking
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

// we don't use one shot keys
#define NO_ACTION_ONESHOT

// no lights if we sleep
#define RGBLIGHT_SLEEP

// more modes for lights
#define RGBLIGHT_EFFECT_ALTERNATING
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_CHRISTMAS
#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_RGB_TEST
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_EFFECT_TWINKLE

// we want to have different backlight per layers
#define RGBLIGHT_LAYERS
