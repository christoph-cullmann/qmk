# set flags we check in common settings
OLED_ENABLE = yes

# include common settings
ROOT_DIR := $(dir $(realpath $(lastword $(MAKEFILE_LIST))))
include ${ROOT_DIR}../../../../rules.mk
