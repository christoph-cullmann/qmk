# properly optimize
LTO_ENABLE = yes

# less debugging features
COMMAND_ENABLE = no
CONSOLE_ENABLE = no

# per key debounce:  https://github.com/qmk/qmk_firmware/blob/master/docs/feature_debounce_type.md
DEBOUNCE_TYPE = sym_defer_pk
