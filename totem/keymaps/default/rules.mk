# less debugging features
COMMAND_ENABLE = no
CONSOLE_ENABLE = no

# Enable N-Key Rollover
NKRO_ENABLE = yes

# more responsive debouncing: https://michael.stapelberg.ch/posts/2021-05-08-keyboard-input-latency-qmk-kinesis/
# sym_eager_pk does do some key chatter
DEBOUNCE_TYPE = asym_eager_defer_pk
