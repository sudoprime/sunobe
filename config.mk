VERSION = 0.1.0

SRC=./src/*.cpp
HDR=./inc
BIN=./bin

CFLAGS=-Wall -g -I "${HDR}" -ldl -std=c++11 -pthread -rdynamic

CC=g++
