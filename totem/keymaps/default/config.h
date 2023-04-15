#pragma once

/**
 * The way how "handedness" is decided (which half is which),
 * see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness for more options.
 */
#define MASTER_LEFT

/**
 * Tapping this number of times holds the key until tapped once again.
 */
#define ONESHOT_TAP_TOGGLE 0

/**
 * Time (in ms) before the one shot key is released.
 */
#define ONESHOT_TIMEOUT 3000
