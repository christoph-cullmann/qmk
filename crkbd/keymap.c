// Copyright Christoph Cullmann
// SPDX-License-Identifier: GPL-2.0+

#include QMK_KEYBOARD_H

// layout helper macro, we just use 42 keys
#undef LAYOUT
#define LAYOUT(\
K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K10,   K11,\
K12,   K13,   K14,   K15,   K16,   K17,   K18,   K19,   K20,   K21,   K22,   K23,\
K24,   K25,   K26,   K27,   K28,   K29,   K30,   K31,   K32,   K33,   K34,   K35,\
                     K36,   K37,   K38,   K39,   K40,   K41\
)\
LAYOUT_split_3x6_3(\
K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K10,   K11,\
K12,   K13,   K14,   K15,   K16,   K17,   K18,   K19,   K20,   K21,   K22,   K23,\
K24,   K25,   K26,   K27,   K28,   K29,   K30,   K31,   K32,   K33,   K34,   K35,\
                     K36,   K37,   K38,   K39,   K40,   K41\
)

// our shared 42 keys keymap
#include "../common/keymap.h"
