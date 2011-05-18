all:
	gcc -g -Wall -o game \
		`ferite-config --cflags --libs` \
		`sdl-config --cflags --libs` \
		-lSDL_image \
		-lSDL_gfx \
		-lgrapple \
		Engine/game.c \
		Engine/array.c \
		Engine/string.c \
		Engine/number.c \
		Engine/engine.c \
		Engine/key.c \
		Engine/image.c \
		Engine/network.c
	gcc -g -Wall -o server \
		`ferite-config --cflags --libs` \
		`sdl-config --cflags --libs` \
		-lSDL_image \
		-lSDL_gfx \
		-lgrapple \
		Engine/server.c \
		Engine/array.c \
		Engine/string.c \
		Engine/number.c \
		Engine/engine.c \
		Engine/key.c \
		Engine/image.c \
		Engine/network.c
