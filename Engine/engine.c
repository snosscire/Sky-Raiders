#include "include.h"

SDL_Surface *screen = NULL;

FE_NATIVE_FUNCTION( game_engine_set_screen )
{
	double width = 0.0;
	double height = 0.0;
	double fullscreen = 0.0;
	
	Uint32 flags = 0;
	
	ferite_get_parameters(params, 3, &width, &height, &fullscreen);

	flags |= SDL_HWPALETTE;
	flags |= SDL_HWSURFACE;
	flags |= SDL_HWACCEL;
	flags |= SDL_DOUBLEBUF;
	
	if( fullscreen )
	{
		flags |= SDL_FULLSCREEN;
	}
	
	screen = SDL_SetVideoMode((int)width, (int)height, 0, flags);
	if( screen )
	{
		//SDL_SetColorKey(screen, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(screen->format, 0, 0, 0));
		FE_RETURN_TRUE;
	}
	FE_RETURN_FALSE;
}

FE_NATIVE_FUNCTION( game_engine_clear_screen )
{
	if( screen )
	{
		SDL_Rect rect;
		rect.x = 0;
		rect.y = 0;
		rect.w = screen->w;
		rect.h = screen->h;
		SDL_FillRect(screen, &rect, SDL_MapRGB(screen->format, 0, 0, 0));
	}
	FE_RETURN_VOID;
}

FE_NATIVE_FUNCTION( game_engine_update_screen )
{
	if( screen )
	{
		SDL_Flip(screen);
	}
	FE_RETURN_VOID;
}

FE_NATIVE_FUNCTION( game_engine_screen_width )
{
	if( screen )
	{
		FE_RETURN_LONG(screen->w);
	}
	FE_RETURN_LONG(0);
}

FE_NATIVE_FUNCTION( game_engine_screen_height )
{
	if( screen )
	{
		FE_RETURN_LONG(screen->h);
	}
	FE_RETURN_LONG(0);
}

FE_NATIVE_FUNCTION( game_engine_next_event )
{
	FeriteNamespace *self = FE_CONTAINER_TO_NS;
	FeriteVariable *event_variable = NULL;
	SDL_Event event;
	if( SDL_PollEvent(&event) )
	{
		switch( event.type )
		{
			case SDL_KEYDOWN:
			case SDL_KEYUP:
			{
				FeriteNamespaceBucket *nsb = ferite_find_namespace(script, self, "KeyboardEvent", FENS_CLS);
				FeriteVariable *type_variable = NULL;
				FeriteVariable *key_variable = NULL;
				FeriteVariable *mod_variable = NULL;
				FeriteVariable *unicode_variable = NULL;
				event_variable = ferite_build_object(script, nsb->data);
				type_variable = ferite_create_number_long_variable(script, "type", event.type, FE_STATIC);
				key_variable = ferite_create_number_long_variable(script, "key", event.key.keysym.sym, FE_STATIC);
				mod_variable = ferite_create_number_long_variable(script, "mod", event.key.keysym.mod, FE_STATIC);
				unicode_variable = ferite_create_number_long_variable(script, "unicode", event.key.keysym.unicode, FE_STATIC);
				ferite_object_set_var(script, VAO(event_variable), "type", type_variable);
				ferite_object_set_var(script, VAO(event_variable), "key", key_variable);
				ferite_object_set_var(script, VAO(event_variable), "mod", mod_variable);
				ferite_object_set_var(script, VAO(event_variable), "unicode", unicode_variable);
				break;
			}
			case SDL_MOUSEBUTTONDOWN:
			case SDL_MOUSEBUTTONUP:
			{
				FeriteNamespaceBucket *nsb = ferite_find_namespace(script, self, "MouseButtonEvent", FENS_CLS);
				FeriteVariable *type_variable = NULL;
				FeriteVariable *button_variable = NULL;
				FeriteVariable *x_variable = NULL;
				FeriteVariable *y_variable = NULL;
				event_variable = ferite_build_object(script, nsb->data);
				type_variable = ferite_create_number_long_variable(script, "type", event.type, FE_STATIC);
				button_variable = ferite_create_number_long_variable(script, "button", event.button.button, FE_STATIC);
				x_variable = ferite_create_number_long_variable(script, "x", event.button.x, FE_STATIC);
				y_variable = ferite_create_number_long_variable(script, "y", event.button.y, FE_STATIC);
				ferite_object_set_var(script, VAO(event_variable), "type", type_variable);
				ferite_object_set_var(script, VAO(event_variable), "button", button_variable);
				ferite_object_set_var(script, VAO(event_variable), "x", x_variable);
				ferite_object_set_var(script, VAO(event_variable), "y", y_variable);
				break;
			}
			case SDL_MOUSEMOTION:
			{
				FeriteNamespaceBucket *nsb = ferite_find_namespace(script, self, "MouseMotionEvent", FENS_CLS);
				FeriteVariable *type_variable = NULL;
				FeriteVariable *x_variable = NULL;
				FeriteVariable *y_variable = NULL;
				FeriteVariable *xrel_variable = NULL;
				FeriteVariable *yrel_variable = NULL;
				event_variable = ferite_build_object(script, nsb->data);
				type_variable = ferite_create_number_long_variable(script, "type", event.type, FE_STATIC);
				x_variable = ferite_create_number_long_variable(script, "x", event.motion.x, FE_STATIC);
				y_variable = ferite_create_number_long_variable(script, "y", event.motion.y, FE_STATIC);
				xrel_variable = ferite_create_number_long_variable(script, "xrel", event.motion.xrel, FE_STATIC);
				yrel_variable = ferite_create_number_long_variable(script, "yrel", event.motion.yrel, FE_STATIC);
				ferite_object_set_var(script, VAO(event_variable), "type", type_variable);
				ferite_object_set_var(script, VAO(event_variable), "x", x_variable);
				ferite_object_set_var(script, VAO(event_variable), "y", y_variable);
				ferite_object_set_var(script, VAO(event_variable), "xrel", xrel_variable);
				ferite_object_set_var(script, VAO(event_variable), "yrel", yrel_variable);
				break;				
			}
			case SDL_QUIT:
			{
				FeriteNamespaceBucket *nsb = ferite_find_namespace(script, self, "QuitEvent", FENS_CLS);
				FeriteVariable *type_variable = ferite_create_number_long_variable(script, "type", event.type, FE_STATIC);
				event_variable = ferite_build_object(script, nsb->data);
				ferite_object_set_var(script, VAO(event_variable), "type", type_variable);
				break;
			}
		}
	}
	if( event_variable )
	{
		MARK_VARIABLE_AS_DISPOSABLE(event_variable);
		FE_RETURN_VAR(event_variable);
	}
	FE_RETURN_NULL_OBJECT;
}

FE_NATIVE_FUNCTION( game_engine_current_working_directory ) {
    int length = 128;
    FeriteVariable *variable = NULL;
    char *buffer = NULL;
    char *returnValue = NULL;
    
    if( (buffer = fmalloc(length)) )
    {
        do
        {
            if( !(returnValue = getcwd(buffer, length - 1)) && errno == ERANGE )
            {
                length *= 2;
                buffer = frealloc(buffer, length);
            }
        }
        while( !returnValue && buffer && errno == ERANGE );
    }
    
    if( returnValue )
    {
        variable = fe_new_str_static("getcwd", returnValue, 0, FE_CHARSET_DEFAULT);
    }
    else
    {
        ferite_set_error(script, errno, "%s", strerror(errno));
        variable = fe_new_str_static("", "", 0, FE_CHARSET_DEFAULT);
    }
    
    if(buffer)
    {
    	ffree(buffer);
    }
    
    FE_RETURN_VAR(variable);
}

FE_NATIVE_FUNCTION( game_engine_current_time )
{
	FeriteVariable *current_time_variable = ferite_create_number_long_variable(script, "currentTime", SDL_GetTicks(), FE_STATIC);
	FE_RETURN_VAR(current_time_variable);
}

FE_NATIVE_FUNCTION( game_engine_load_image )
{
	FeriteString *path = NULL;
	double convert = 0.0;
	SDL_Surface *image = NULL;
	
	ferite_get_parameters(params, 2, &path, &convert);
	
	image = IMG_Load(path->data);
	if( image )
	{
		SDL_Surface *new = SDL_DisplayFormatAlpha(image);
		if( new )
		{
			SDL_FreeSurface(image);
			image = new;
		}
		FeriteNamespaceBucket *nsb = ferite_find_namespace(script, script->mainns, "Engine.Image", FENS_CLS);
		FeriteVariable *image_variable = ferite_build_object(script, nsb->data);
		VAO(image_variable)->odata = image;
		MARK_VARIABLE_AS_DISPOSABLE(image_variable);
		FE_RETURN_VAR(image_variable);
	}
	FE_RETURN_NULL_OBJECT;
}

FE_NATIVE_FUNCTION( game_engine_draw_image )
{
	FeriteObject *image = NULL;
	double screen_x = 0.0;
	double screen_y = 0.0;
	double image_x = 0.0;
	double image_y = 0.0;
	double image_w = 0.0;
	double image_h = 0.0;
	
	SDL_Surface *src = NULL;
	SDL_Rect src_rect;
	SDL_Rect dst_rect;
	
	ferite_get_parameters(params, 7, &image, &screen_x, &screen_y, &image_x, &image_y, &image_w, &image_h);
	
	src = image->odata;
	
	src_rect.x = image_x;
	src_rect.y = image_y;
	src_rect.w = image_w;
	src_rect.h = image_h;
	
	if( src_rect.w == 0 )
	{
		src_rect.w = src->w;
	}
	if( src_rect.h == 0 )
	{
		src_rect.h = src->h;
	}
	
	dst_rect.x = screen_x;
	dst_rect.y = screen_y;
	
	SDL_BlitSurface(src, &src_rect, screen, &dst_rect);
	
	FE_RETURN_VOID;
}

FE_NATIVE_FUNCTION( game_engine_draw_rectangle )
{
	double x = 0.0;
	double y = 0.0;
	double w = 0.0;
	double h = 0.0;
	double r = 0.0;
	double g = 0.0;
	double b = 0.0;
	ferite_get_parameters(params, 7, &x, &y, &w, &h, &r, &g, &b);
	if( screen )
	{
		SDL_Rect rect;
		rect.x = x;
		rect.y = y;
		rect.w = w;
		rect.h = h;
		SDL_FillRect(screen, &rect, SDL_MapRGB(screen->format, r, g, b));
	}
	FE_RETURN_VOID;
}

FE_NATIVE_FUNCTION( game_engine_sin )
{
	double number = 0.0;
	ferite_get_parameters(params, 1, &number);
	FE_RETURN_DOUBLE(sin(number));
}


FE_NATIVE_FUNCTION( game_engine_cos )
{
	double number = 0.0;
	ferite_get_parameters(params, 1, &number);
	FE_RETURN_DOUBLE(cos(number));
}

FE_NATIVE_FUNCTION( game_engine_print_line )
{
	FeriteString *str = NULL;
	ferite_get_parameters(params, 1, &str);
	printf("%s\n", str->data);
	FE_RETURN_VOID;
}

Mix_Music *music = NULL;

FE_NATIVE_FUNCTION( game_engine_play_music )
{
	FeriteString *file = NULL;
	ferite_get_parameters(params, 1, &file);
	
	Mix_HaltMusic();
	if( music  )
	{
		Mix_FreeMusic(music);
		music = NULL;
	}
	music = Mix_LoadMUS(file->data);
	if( music )
	{
		Mix_PlayMusic(music, -1);
	}
	
	FE_RETURN_VOID;
}

FE_NATIVE_FUNCTION( game_engine_stop_music )
{
	Mix_HaltMusic();
	if( music )
	{
		Mix_FreeMusic(music);
		music = NULL;
	}
	FE_RETURN_VOID;
}

FE_NATIVE_FUNCTION( game_engine_set_sound_channels )
{
	double channels = 0.0;
	ferite_get_parameters(params, 1, &channels);
	Mix_AllocateChannels((int)channels);
	FE_RETURN_VOID;
}

FE_NATIVE_FUNCTION( game_engine_load_sound )
{
	FeriteString *path = NULL;
	Mix_Chunk *sound = NULL;
	
	ferite_get_parameters(params, 1, &path);
	
	sound = Mix_LoadWAV(path->data);
	if( sound )
	{
		FeriteNamespaceBucket *nsb = ferite_find_namespace(script, script->mainns, "Engine.Sound", FENS_CLS);
		FeriteVariable *sound_variable = ferite_build_object(script, nsb->data);
		VAO(sound_variable)->odata = sound;
		MARK_VARIABLE_AS_DISPOSABLE(sound_variable);
		FE_RETURN_VAR(sound_variable);
	}
	FE_RETURN_NULL_OBJECT;
}

void game_engine_init( FeriteScript *script )
{
	FeriteNamespaceBucket *nsb = ferite_find_namespace(script, script->mainns, "Engine", FENS_NS);
	FeriteNamespace *engine_namespace = (nsb && nsb->data ? nsb->data : ferite_register_namespace(script, "Engine", script->mainns));
	
	FeriteVariable *event_keydown_variable = ferite_create_number_long_variable(script, "EVENT_KEYDOWN", SDL_KEYDOWN, FE_STATIC);
	FeriteVariable *event_keyup_variable = ferite_create_number_long_variable(script, "EVENT_KEYUP", SDL_KEYUP, FE_STATIC);
	FeriteVariable *event_mousebuttondown_variable = ferite_create_number_long_variable(script, "EVENT_MOUSEBUTTONDOWN", SDL_MOUSEBUTTONDOWN, FE_STATIC);
	FeriteVariable *event_mousebuttonup_variable = ferite_create_number_long_variable(script, "EVENT_MOUSEBUTTONUP", SDL_MOUSEBUTTONUP, FE_STATIC);
	FeriteVariable *event_mousemotion_variable = ferite_create_number_long_variable(script, "EVENT_MOUSEMOTION", SDL_MOUSEMOTION, FE_STATIC);
	FeriteVariable *event_quit_variable = ferite_create_number_long_variable(script, "EVENT_QUIT", SDL_QUIT, FE_STATIC);
	
	FeriteVariable *button_left_variable = ferite_create_number_long_variable(script, "BUTTON_LEFT", SDL_BUTTON_LEFT, FE_STATIC);
	
	FeriteFunction *sin_function = ferite_create_external_function(script, "sin", game_engine_sin, "n");
	FeriteFunction *cos_function = ferite_create_external_function(script, "cos", game_engine_cos, "n");
	FeriteFunction *print_line_function = ferite_create_external_function(script, "printLine", game_engine_print_line, "s");
	FeriteFunction *set_screen_function = ferite_create_external_function(script, "setScreen", game_engine_set_screen, "nnn");
	FeriteFunction *clear_screen_function = ferite_create_external_function(script, "clearScreen", game_engine_clear_screen, "");
	FeriteFunction *update_screen_function = ferite_create_external_function(script, "updateScreen", game_engine_update_screen, "");
	FeriteFunction *next_event_function = ferite_create_external_function(script, "nextEvent", game_engine_next_event, "");
	FeriteFunction *current_time_function = ferite_create_external_function(script, "currentTime", game_engine_current_time, "");
	FeriteFunction *load_image_function = ferite_create_external_function(script, "loadImage", game_engine_load_image, "sn");
	FeriteFunction *draw_image_function = ferite_create_external_function(script, "drawImage", game_engine_draw_image, "onnnnnn");
	FeriteFunction *screen_width_function = ferite_create_external_function(script, "screenWidth", game_engine_screen_width, "");
	FeriteFunction *screen_height_function = ferite_create_external_function(script, "screenHeight", game_engine_screen_height, "");
	FeriteFunction *current_working_directory_function = ferite_create_external_function(script, "currentWorkingDirectory", game_engine_current_working_directory, "");
	FeriteFunction *draw_rectangle_function = ferite_create_external_function(script, "drawRectangle", game_engine_draw_rectangle, "nnnnnnn");
	FeriteFunction *play_music_function = ferite_create_external_function(script, "playMusic", game_engine_play_music, "s");
	FeriteFunction *stop_music_function = ferite_create_external_function(script, "stopMusic", game_engine_stop_music, "");
	FeriteFunction *set_sound_channels_function = ferite_create_external_function(script, "setSoundChannels", game_engine_set_sound_channels, "n");
	FeriteFunction *load_sound_function = ferite_create_external_function(script, "loadSound", game_engine_load_sound, "s");

	ferite_register_inherited_class(script, engine_namespace, "KeyboardEvent", NULL);
	ferite_register_inherited_class(script, engine_namespace, "MouseButtonEvent", NULL);
	ferite_register_inherited_class(script, engine_namespace, "MouseMotionEvent", NULL);
	ferite_register_inherited_class(script, engine_namespace, "QuitEvent", NULL);
	
	ferite_register_ns_variable(script, engine_namespace, "EVENT_KEYDOWN", event_keydown_variable);
	ferite_register_ns_variable(script, engine_namespace, "EVENT_KEYUP", event_keyup_variable);
	ferite_register_ns_variable(script, engine_namespace, "EVENT_MOUSEBUTTONDOWN", event_mousebuttondown_variable);
	ferite_register_ns_variable(script, engine_namespace, "EVENT_MOUSEBUTTONUP", event_mousebuttonup_variable);
	ferite_register_ns_variable(script, engine_namespace, "EVENT_MOUSEMOTION", event_mousemotion_variable);
	ferite_register_ns_variable(script, engine_namespace, "EVENT_QUIT", event_quit_variable);
	
	// SDL_BUTTON_LEFT, SDL_BUTTON_MIDDLE, SDL_BUTTON_RIGHT, SDL_BUTTON_WHEELUP, SDL_BUTTON_WHEELDOWN
	ferite_register_ns_variable(script, engine_namespace, "BUTTON_LEFT", button_left_variable);
	
	ferite_register_ns_function(script, engine_namespace, sin_function);
	ferite_register_ns_function(script, engine_namespace, cos_function);
	ferite_register_ns_function(script, engine_namespace, print_line_function);
	ferite_register_ns_function(script, engine_namespace, set_screen_function);
	ferite_register_ns_function(script, engine_namespace, clear_screen_function);
	ferite_register_ns_function(script, engine_namespace, update_screen_function);
	ferite_register_ns_function(script, engine_namespace, next_event_function);
	ferite_register_ns_function(script, engine_namespace, current_time_function);
	ferite_register_ns_function(script, engine_namespace, load_image_function);
	ferite_register_ns_function(script, engine_namespace, draw_image_function);
	ferite_register_ns_function(script, engine_namespace, screen_width_function);
	ferite_register_ns_function(script, engine_namespace, screen_height_function);
	ferite_register_ns_function(script, engine_namespace, current_working_directory_function);
	ferite_register_ns_function(script, engine_namespace, draw_rectangle_function);
	ferite_register_ns_function(script, engine_namespace, play_music_function);
	ferite_register_ns_function(script, engine_namespace, stop_music_function);
	ferite_register_ns_function(script, engine_namespace, set_sound_channels_function);
	ferite_register_ns_function(script, engine_namespace, load_sound_function);
	
	game_engine_key_init(script, engine_namespace);
	game_engine_image_init(script, engine_namespace);
	game_engine_sound_init(script, engine_namespace);
	game_engine_network_init(script);
}

