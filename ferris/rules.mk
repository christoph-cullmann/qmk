# properly optimize
LTO_ENABLE = yes

# less debugging features
COMMAND_ENABLE = no
CONSOLE_ENABLE = no

# we have some real mouse
MOUSEKEY_ENABLE = no

# more features we not use
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MUSIC_ENABLE = no

# caps word is great for defines
CAPS_WORD_ENABLE = yes

# add achordion to improve home row modifiers
SRC += achordion.c

# per key debounce:  https://github.com/qmk/qmk_firmware/blob/master/docs/feature_debounce_type.md
DEBOUNCE_TYPE = sym_defer_pk
