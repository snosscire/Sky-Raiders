#include "image.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_rotozoom.h>

FE_NATIVE_FUNCTION( game_engine_image_unload )
{
	FeriteObject *self = FE_CONTAINER_TO_OBJECT;
	SDL_FreeSurface((SDL_Surface *)self->odata);
	self->odata = NULL;
	FE_RETURN_VOID;
}

FE_NATIVE_FUNCTION( game_engine_image_width )
{
	FeriteObject *self = FE_CONTAINER_TO_OBJECT;
	SDL_Surface *image = self->odata;
	FeriteVariable *width = ferite_create_number_long_variable(script, "width", image->w, FE_STATIC);
	MARK_VARIABLE_AS_DISPOSABLE(width);
	FE_RETURN_VAR(width);
}

FE_NATIVE_FUNCTION( game_engine_image_height )
{
	FeriteObject *self = FE_CONTAINER_TO_OBJECT;
	SDL_Surface *image = self->odata;
	FeriteVariable *height = ferite_create_number_long_variable(script, "height", image->h, FE_STATIC);
	MARK_VARIABLE_AS_DISPOSABLE(height);
	FE_RETURN_VAR(height);
}

FE_NATIVE_FUNCTION( game_engine_image_rotate )
{
	FeriteObject *self = FE_CONTAINER_TO_OBJECT;
	SDL_Surface *image = self->odata;
	double angle = 0.0;
	double smooth = 0.0;
	double zoom = 0.0;
	ferite_get_parameters(params, 2, &angle, &zoom, &smooth);
	SDL_Surface *rotated_image = rotozoomSurfaceXY(image, angle, zoom, zoom, smooth);
	if( rotated_image )
	{
		FeriteVariable *rotated_image_object = ferite_build_object(script, self->klass);
		VAO(rotated_image_object)->odata = rotated_image;
		MARK_VARIABLE_AS_DISPOSABLE(rotated_image_object);
		FE_RETURN_VAR(rotated_image_object);
	}
	FE_RETURN_NULL_OBJECT;
}

FE_NATIVE_FUNCTION( game_engine_image_get_color )
{
	FeriteObject *self = FE_CONTAINER_TO_OBJECT;
	SDL_Surface *surface = (SDL_Surface *)self->odata;
	double r, g, b = 0.0;
	ferite_get_parameters(params, 3, &r, &g, &b);
	FE_RETURN_LONG(SDL_MapRGB(surface->format, (Uint8)r, (Uint8)g, (Uint8)b));
}

FE_NATIVE_FUNCTION( game_engine_image_set_transparent_color )
{
	FeriteObject *self = FE_CONTAINER_TO_OBJECT;
	double color = 0.0;
	ferite_get_parameters(params, 1, &color);
	SDL_SetColorKey(self->odata, SDL_SRCCOLORKEY | SDL_RLEACCEL, (Uint32)color);
	FE_RETURN_VOID;
}

void game_engine_image_init( FeriteScript *script, FeriteNamespace *engine_namespace )
{
	FeriteClass *class = ferite_register_inherited_class(script, engine_namespace, "Image", NULL);
	FeriteFunction *unload_function = ferite_create_external_function(script, "unload", game_engine_image_unload, "");
	FeriteFunction *width_function = ferite_create_external_function(script, "width", game_engine_image_width, "");
	FeriteFunction *height_function = ferite_create_external_function(script, "height", game_engine_image_height, "");
	FeriteFunction *rotate_function = ferite_create_external_function(script, "rotate", game_engine_image_rotate, "nnn");
	FeriteFunction *get_color_function = ferite_create_external_function(script, "getColor", game_engine_image_get_color, "nnn");
	FeriteFunction *set_transparent_color_function = ferite_create_external_function(script, "setTransparentColor", game_engine_image_set_transparent_color, "n");
	ferite_register_class_function(script, class, unload_function, FE_FALSE);
	ferite_register_class_function(script, class, width_function, FE_FALSE);
	ferite_register_class_function(script, class, height_function, FE_FALSE);
	ferite_register_class_function(script, class, rotate_function, FE_FALSE);
	ferite_register_class_function(script, class, get_color_function, FE_FALSE);
	ferite_register_class_function(script, class, set_transparent_color_function, FE_FALSE);
	ferite_register_class_variable(script, class, "path", ferite_create_string_variable(script, "path", NULL, FE_STATIC), FE_FALSE);
	ferite_register_class_variable(script, class, "references", ferite_create_number_long_variable(script, "references", 0, FE_STATIC), FE_FALSE);
}

