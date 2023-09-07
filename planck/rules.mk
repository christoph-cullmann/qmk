# properly optimize
LTO_ENABLE = yes

# less debugging features
COMMAND_ENABLE = no
CONSOLE_ENABLE = no

# Enable N-Key Rollover
NKRO_ENABLE = yes

# less features we don't use
MOUSEKEY_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no

# add achordion to improve home row modifiers
SRC += ../common/achordion.c

# build
# qmk compile -kb planck/rev6_drop -km christoph-cullmann
# qmk flash -kb planck/rev6_drop -km christoph-cullmann
