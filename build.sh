#!/bin/bash
gcc -std=c99 -Wall -Wextra -pedantic -Wundef -Wshadow -Wpointer-arith -Wcast-align -Wwrite-strings -o out/main src/main.c