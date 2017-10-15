#!/bin/bash

# Build Tools

gcc -o Expanse main.c curses_main.c sdl_main.c $(pkg-config --cflags --libs sdl2)  -Wall -lX11 -lncurses -lSDL2_image -lm -I/home/svr01/Expanse/code/linux -ggdb -v
