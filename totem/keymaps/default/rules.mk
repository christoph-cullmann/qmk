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

# more responsive debouncing: https://michael.stapelberg.ch/posts/2021-05-08-keyboard-input-latency-qmk-kinesis/
DEBOUNCE_TYPE = asym_eager_defer_pk

# add achordion to improve home row modifiers
SRC += ../../../common/achordion.c

# build
# qmk compile -kb totem -km default
# qmk flash -kb totem -km default
