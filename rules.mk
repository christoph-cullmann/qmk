# Enable N-Key Rollover
NKRO_ENABLE = yes

# optimize size
LTO_ENABLE = yes

# use more snappy debounce algo
DEBOUNCE_TYPE = sym_eager_pk

# add bongocat & luna for OLEDs
ifeq ($(strip $(OLED_ENABLE)), yes)
    SRC += features/oled_bongocat.c
    SRC += features/oled_luna.c
endif
