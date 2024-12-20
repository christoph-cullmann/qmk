# Enable N-Key Rollover
NKRO_ENABLE = yes

# add achordion to improve home row modifiers
SRC += features/achordion.c

# add bongocat & luna for OLEDs
ifeq ($(strip $(OLED_ENABLE)), yes)
    SRC += features/oled_bongocat.c
    SRC += features/oled_luna.c
endif
