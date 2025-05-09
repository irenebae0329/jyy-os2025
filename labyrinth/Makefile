NAME := $(shell basename $(PWD))
export MODULE := M1
all: $(NAME)
PROJECT_ROOT := $(shell pwd)
CFLAGS := -DPROJECT_ROOT=\"$(PROJECT_ROOT)\"

include ../.shadow/oslabs.mk
