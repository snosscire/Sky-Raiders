#include "string.h"

FE_NATIVE_FUNCTION( ferite_string_length )
{
	FeriteString *string = NULL;
	ferite_get_parameters(params, 1, &string);
	FE_RETURN_LONG(string->length);
}

FE_NATIVE_FUNCTION( ferite_string_byte_to_number )
{
	FeriteString *string = NULL;
	ferite_get_parameters(params, 1, &string);
	
	if( string->length == 0 )
	{
		FE_RETURN_LONG(-1);
	}
	else
	{
		unsigned char c = string->data[0];
		long r = 0 + c;
		FE_RETURN_LONG(r);
	}
}

void ferite_string_init( FeriteScript *script )
{
	FeriteNamespaceBucket *nsb = ferite_find_namespace(script, script->mainns, "String", FENS_NS);
	FeriteNamespace *string_namespace = (nsb && nsb->data ? nsb->data : ferite_register_namespace(script, "String", script->mainns));
	/* FeriteNamespace *array_namespace = (nsb->data ? nsb->data : ferite_register_namespace(script, "String", script->mainns)); */
	FeriteFunction *length_function = ferite_create_external_function(script, "length", ferite_string_length, "s");
	FeriteFunction *byte_to_number_function = ferite_create_external_function(script, "byteToNumber", ferite_string_byte_to_number, "s");
	ferite_register_ns_function(script, string_namespace, length_function);
	ferite_register_ns_function(script, string_namespace, byte_to_number_function);
}

