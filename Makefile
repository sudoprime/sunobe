#!/usr/bin/env gmake

include config.mk

UNAME   := $(shell uname -s)

all: prep options kera sunobe
	
options:
	@echo "compiler options:"
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "CC       = ${CC}"
	@echo "UNAME    = ${UNAME}"

kera:
	@echo "building kera..."

sunobe:
	@echo "building sunobe..."

prep:
	@echo "preparing."

clean:
	@rm -f $(BIN)/*

.PHONY: clean options all kera
