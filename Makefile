all:
	gcc -g -Wall -o game.x86 \
		`ferite-config --cflags --libs` \
		`sdl-config --cflags --libs` \
		-lSDL_image \
		-lSDL_gfx \
		Engine/game.c \
		Engine/array.c \
		Engine/string.c \
		Engine/engine.c \
		Engine/key.c \
		Engine/image.c
