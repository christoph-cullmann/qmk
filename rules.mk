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

# add achordion to improve home row modifiers
SRC += achordion.c

# properly optimize
LTO_ENABLE = yes

# less debugging features
COMMAND_ENABLE = no
CONSOLE_ENABLE = no

# more features we not use
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MUSIC_ENABLE = no
