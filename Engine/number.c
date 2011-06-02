#include "include.h"

FE_NATIVE_FUNCTION( ferite_number_round )
{
	double number = 0.0;
	ferite_get_parameters(params, 1, &number);
	int sign = (number < 0 ? -1 : 1);
	FE_RETURN_LONG((long)(number + (0.5 * sign)));
}

FE_NATIVE_FUNCTION( ferite_number_floor )
{
	double number = 0.0;
	ferite_get_parameters(params, 1, &number);
	FE_RETURN_DOUBLE(floor(number));
}

void ferite_number_init( FeriteScript *script )
{
	FeriteNamespaceBucket *nsb = ferite_find_namespace(script, script->mainns, "Number", FENS_NS);
	FeriteNamespace *number_namespace = (nsb && nsb->data ? nsb->data : ferite_register_namespace(script, "Number", script->mainns));
	/* FeriteNamespace *array_namespace = (nsb->data ? nsb->data : ferite_register_namespace(script, "Number", script->mainns)); */
	FeriteFunction *round_function = ferite_create_external_function(script, "round", ferite_number_round, "n");
	FeriteFunction *floor_function = ferite_create_external_function(script, "floor", ferite_number_floor, "n");
	ferite_register_ns_function(script, number_namespace, round_function);
	ferite_register_ns_function(script, number_namespace, floor_function);
}

