# configure miryoku
MIRYOKU_ALPHAS=QWERTY
MIRYOKU_EXTRA=QWERTY
MIRYOKU_TAP=QWERTY
MIRYOKU_NAV=INVERTEDT

# include miryoku defaults
MOUSEKEY_ENABLE = yes # Mouse keys
EXTRAKEY_ENABLE = yes # Audio control and System control
AUTO_SHIFT_ENABLE = yes # Auto Shift
include users/manna-harbour_miryoku/custom_rules.mk
include users/manna-harbour_miryoku/post_rules.mk

# properly optimize
LTO_ENABLE = yes
