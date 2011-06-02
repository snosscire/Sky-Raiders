#ifndef GAME_ENGINE_INCLUDE_H
#define GAME_ENGINE_INCLUDE_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include <unistd.h>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_rotozoom.h>

#include <enet/enet.h>

#include <ferite.h>

/*#define GAME_API __declspec(dllexport)*/
/*#define FERITE_API __declspec(dllimport)*/
#define GAME_API __declspec(dllexport)
/*#define GAME_API*/


#include "array.h"
#include "string.h"
#include "number.h"
#include "engine.h"

#include "key.h"
#include "image.h"
#include "network.h"

#endif