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

// tapping this number of times holds the key until tapped once again, disabled via 0
#define ONESHOT_TAP_TOGGLE 0

// time (in ms) before the one shot key is released
#define ONESHOT_TIMEOUT 3000

// we don't have any lock switches
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

// enable NKRO by default
#define FORCE_NKRO

//
// improve home row modifiers via achoridion
//

// settings for home row modifiers
// details see https://precondition.github.io/home-row-mods

// the default of 200
#define TAPPING_TERM 180

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define QUICK_TAP_TERM 0

// try to be more permissive with holds, allows to trigger modifiers faster
// achordion will avoid the worst
#define PERMISSIVE_HOLD

// caps word is great for defines
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
