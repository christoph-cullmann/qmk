# Enable N-Key Rollover
NKRO_ENABLE = yes

# optimize size
LTO_ENABLE = yes

# use more snappy debounce algo
DEBOUNCE_TYPE = asym_eager_defer_pk

# disable some stuff we don't need

# no mouse emulation
MOUSEKEY_ENABLE = no

# no extrakeys disables stuff like the media keys and system volume control
EXTRAKEY_ENABLE = no

# add bongocat & luna for OLEDs
ifeq ($(strip $(OLED_ENABLE)), yes)
    SRC += features/oled_bongocat.c
    SRC += features/oled_luna.c
endif
