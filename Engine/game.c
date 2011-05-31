#include <stdio.h>
#include <stdlib.h>
#include <ferite.h>
#include <SDL/SDL.h>
#include <enet/enet.h>

#include "array.h"
#include "string.h"
#include "number.h"
#include "engine.h"

int main(int argc, char *argv[] )
{
	FeriteScript *script = NULL;
	char *error_message = NULL;
	
	SDL_Init(SDL_INIT_VIDEO);
	SDL_EnableUNICODE(1);
	enet_initialize();
	
	if( ferite_init(0, NULL) )
	{
		ferite_set_script_argv(argc, argv);
		script = ferite_script_compile("Game.fe");
		if( ferite_has_compile_error(script) )
		{
			error_message = ferite_get_error_log(script);
			fprintf(stderr, "[ferite: compile]\n%s", error_message);
		}
		else
		{
			ferite_array_init(script);
			ferite_string_init(script);
			ferite_number_init(script);
			game_engine_init(script);
			
			ferite_script_execute(script);
			if( ferite_has_runtime_error(script) )
			{
				error_message = ferite_get_error_log(script);
				fprintf(stderr, "[ferite: execution]\n%s", error_message);
			}
		}
		if( error_message )
		{
			ffree(error_message);
		}
		ferite_script_delete(script);
		ferite_deinit();
	}
	
	enet_deinitialize();
	SDL_Quit();
	
	return 0;
}
