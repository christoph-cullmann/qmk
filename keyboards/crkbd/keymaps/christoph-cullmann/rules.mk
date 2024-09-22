# include common settings
ROOT_DIR := $(dir $(realpath $(lastword $(MAKEFILE_LIST))))
include ${ROOT_DIR}../../../../rules.mk

# build
# qmk compile -kb crkbd -km christoph-cullmann
# qmk flash -kb crkbd -km christoph-cullmann
