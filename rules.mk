# we use the caps word feature
# https://docs.qmk.fm/features/caps_word
CAPS_WORD_ENABLE = yes

# we use repeat and alternate repeat keys
# https://docs.qmk.fm/features/repeat_key
REPEAT_KEY_ENABLE = yes

# Enable N-Key Rollover
NKRO_ENABLE = yes

# optimize size
LTO_ENABLE = yes

# disable some stuff we don't need
COMBO_ENABLE = no
COMMAND_ENABLE = no
CONSOLE_ENABLE = no
EXTRAKEY_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no
MOUSEKEY_ENABLE = no
SPACE_CADET_ENABLE = no
SWAP_HANDS_ENABLE = no
UNICODE_ENABLE = no

# add bongocat & luna for OLEDs
ifeq ($(strip $(OLED_ENABLE)), yes)
    SRC += features/oled_bongocat.c
    SRC += features/oled_luna.c
endif
