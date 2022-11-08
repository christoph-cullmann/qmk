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

//
// improve home row modifiers via achoridion
//

// settings for home row modifiers
// details see https://precondition.github.io/home-row-mods

// bit lower the default from 200
#define TAPPING_TERM 180

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

// try to be more permissive with holds, allows to trigger modifiers faster
// achordion will avoid the worst
#define PERMISSIVE_HOLD

//
// remove some features we don't need
//

// not more than 8 layers
#define LAYER_STATE_8BIT

// we don't need locking
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

// we don't use one shot keys
#define NO_ACTION_ONESHOT
