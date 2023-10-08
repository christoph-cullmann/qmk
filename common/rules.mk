# Enable N-Key Rollover
NKRO_ENABLE = yes

# less features we don't use
COMMAND_ENABLE = no
CONSOLE_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no
MOUSEKEY_ENABLE = no
MUSIC_ENABLE = no
SPACE_CADET_ENABLE = no

# responsive debouncing
DEBOUNCE_TYPE = sym_eager_pk

# add achordion to improve home row modifiers
SRC += /home/cullmann/install/qmk/christoph-cullmann/common/achordion.c

# good optimizations
LTO_ENABLE = yes
