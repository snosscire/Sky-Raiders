all:
	gcc -g -Wall -o game \
		`ferite-config --cflags --libs` \
		`sdl-config --cflags --libs` \
		-lSDL_image \
		-lSDL_mixer \
		-lSDL_gfx \
		-lenet \
		Engine/game.c \
		Engine/array.c \
		Engine/string.c \
		Engine/number.c \
		Engine/engine.c \
		Engine/key.c \
		Engine/image.c \
		Engine/network_enet.c
	gcc -g -Wall -o server \
		`ferite-config --cflags --libs` \
		`sdl-config --cflags --libs` \
		-lSDL_image \
		-lSDL_mixer \
		-lSDL_gfx \
		-lenet \
		Engine/server.c \
		Engine/array.c \
		Engine/string.c \
		Engine/number.c \
		Engine/engine.c \
		Engine/key.c \
		Engine/image.c \
		Engine/network_enet.c
