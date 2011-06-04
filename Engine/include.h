#ifndef GAME_ENGINE_INCLUDE_H
#define GAME_ENGINE_INCLUDE_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_rotozoom.h>

#include <enet/enet.h>

#include <ferite.h>

#ifdef WIN32
#define GAME_API __declspec(dllexport)
#else
#define GAME_API extern
#endif

#include "array.h"
#include "string.h"
#include "number.h"
#include "engine.h"

#include "key.h"
#include "image.h"
#include "network.h"

#endif
