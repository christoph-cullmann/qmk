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

// bit larger debounce delay, the default is 5
#define DEBOUNCE 10

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

// the default is 200
#define TAPPING_TERM 175
#define TAPPING_TERM_PER_KEY

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define QUICK_TAP_TERM 0

// use permissive hold together with achordion
#define PERMISSIVE_HOLD

// delay hold/release to not mess up software
#define TAP_CODE_DELAY 10

// enable the https://sunaku.github.io/home-row-mods.html#typing-streaks inspired stuff
#define ACHORDION_STREAK

