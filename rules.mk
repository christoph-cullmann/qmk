# enable NKRO feature
# still default off even if that is set
NKRO_ENABLE = yes

# we use the caps word feature
# https://docs.qmk.fm/features/caps_word
CAPS_WORD_ENABLE = yes

# we use repeat and alternate repeat keys
# https://docs.qmk.fm/features/repeat_key
REPEAT_KEY_ENABLE = yes

# optimize size
LTO_ENABLE = yes

# debounce per key, I use keyboards with not that many keys :)
DEBOUNCE_TYPE=sym_defer_pk

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
