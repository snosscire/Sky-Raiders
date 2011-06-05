#include "include.h"

FE_NATIVE_FUNCTION( game_engine_sound_unload )
{
	FeriteObject *self = FE_CONTAINER_TO_OBJECT;
	Mix_Chunk *chunk = (Mix_Chunk *)self->odata;
	Mix_FreeChunk(chunk);
	self->odata = NULL;
	FE_RETURN_VOID;
}

FE_NATIVE_FUNCTION( game_engine_sound_play )
{
	FeriteObject *self = FE_CONTAINER_TO_OBJECT;
	Mix_Chunk *chunk = (Mix_Chunk *)self->odata;
	Mix_PlayChannel(-1, chunk, 0);
	FE_RETURN_VOID;
}

void game_engine_sound_init( FeriteScript *script, FeriteNamespace *engine_namespace )
{
	FeriteClass *class = ferite_register_inherited_class(script, engine_namespace, "Sound", NULL);
	FeriteFunction *unload_function = ferite_create_external_function(script, "unload", game_engine_sound_unload, "");
	FeriteFunction *play_function = ferite_create_external_function(script, "play", game_engine_sound_play, "");
	ferite_register_class_function(script, class, unload_function, FE_FALSE);
	ferite_register_class_function(script, class, play_function, FE_FALSE);
}

