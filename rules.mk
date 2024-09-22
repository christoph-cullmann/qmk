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

# add achordion to improve home row modifiers
SRC += features/achordion.c

# add bongocat & luna for OLEDs
ifeq ($(strip $(OLED_ENABLE)), yes)
    SRC += features/oled_bongocat.c
    SRC += features/oled_luna.c
endif

# good optimizations
LTO_ENABLE = yes
