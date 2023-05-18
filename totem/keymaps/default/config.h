#pragma once

// The way how "handedness" is decided (which half is which), see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness for more options.
#define MASTER_LEFT

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
#define TAPPING_TERM 200

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define QUICK_TAP_TERM 0

// try to be more permissive with holds, allows to trigger modifiers faster
// achordion will avoid the worst
#define PERMISSIVE_HOLD

// caps word is great for defines
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
