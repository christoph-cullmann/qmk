/**
 * SPDX-FileCopyrightText: 2024 Christoph Cullmann <christoph@cullmann.io>
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#pragma once

// our shared config parts
#include "common/config.h"

// select hand configuration
#define SPLIT_USB_DETECT

// tranfer enough info for the stuff we render on the OLEDs
#define SPLIT_MODS_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_LAYER_STATE_ENABLE
