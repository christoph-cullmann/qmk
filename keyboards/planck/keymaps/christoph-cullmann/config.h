/**
 * SPDX-FileCopyrightText: 2024 Christoph Cullmann <christoph@cullmann.io>
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#pragma once

// our shared config parts
#include "common/config.h"

//
// audio configuration
//

// fix startup sound
#define AUDIO_INIT_DELAY

// normal startup sound
#define STARTUP_SONG SONG(PLANCK_SOUND)
