#include "include.h"

int main(int argc, char *argv[] )
{
	FeriteScript *script = NULL;
	char *error_message = NULL;
	
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	SDL_EnableUNICODE(1);
	enet_initialize();

  int audio_rate = 22050;
  Uint16 audio_format = AUDIO_S16; /* 16-bit stereo */
  int audio_channels = 2;
  int audio_buffers = 4096;

  if(Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers)) {
    printf("Unable to open audio!\n");
  }

	
	srand(time(NULL));
	
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
	Mix_CloseAudio();
	SDL_Quit();
	
	return 0;
}
