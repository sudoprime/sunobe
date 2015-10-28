#!/usr/bin/env gmake

include config.mk

UNAME   := $(shell uname -s)

all: prep options kera test
	
options:
	@echo "compiler options:"
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "CC       = ${CC}"
	@echo "UNAME    = ${UNAME}"

kera:
	$(CC) $(CFLAGS) $(SRC) -o $(BIN)/kera

prep:
	@echo "preparing."

clean:
	@rm -f $(BIN)/*

test:
	./bin/kera

.PHONY: clean options all
