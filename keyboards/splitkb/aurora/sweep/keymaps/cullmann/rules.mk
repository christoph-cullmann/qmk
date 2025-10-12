# include common settings
ROOT_DIR := $(dir $(realpath $(lastword $(MAKEFILE_LIST))))
include ${ROOT_DIR}../../../../../../rules.mk

# we use an Liatris cpu
CONVERT_TO=liatris
