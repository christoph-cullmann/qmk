# include common settings
ROOT_DIR := $(dir $(realpath $(lastword $(MAKEFILE_LIST))))
include ${ROOT_DIR}../../../../rules.mk

# build
# qmk compile -kb planck/rev6_drop -km christoph-cullmann
# qmk flash -kb planck/rev6_drop -km christoph-cullmann
