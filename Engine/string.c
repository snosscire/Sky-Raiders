#include "string.h"
#include <errno.h>

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

FE_NATIVE_FUNCTION( ferite_string_number_to_byte ) {
	double number = 0.0;
	ferite_get_parameters(params, 1, &number);
	FeriteString *string = NULL;

	if( (long)number >= 0 || (long)number <= 255 )
	{
		char c = (unsigned char)number;
		string = ferite_str_new(script, &c, 1, FE_CHARSET_DEFAULT);
	}
	else
	{
		string = ferite_str_new(script, NULL, 0, FE_CHARSET_DEFAULT);
	}
	
	FE_RETURN_STR(string, FE_TRUE);
}

FE_NATIVE_FUNCTION( ferite_string_to_number ) {
	FeriteString *string = NULL;
	ferite_get_parameters(params, 1, &string);
	if( string->length > 0 )
	{
		long l = 0;
		double d = 0.0;
		char *endptr;
		l = strtol(string->data, &endptr, 0);
		if( errno != ERANGE && *endptr == 0 )
		{
			FE_RETURN_LONG(l);
		}
		d = strtod(string->data, &endptr);
		if( errno != ERANGE )
		{
			FE_RETURN_DOUBLE(d);
		}
	}
	FE_RETURN_LONG(0);
}

void ferite_string_init( FeriteScript *script )
{
	FeriteNamespaceBucket *nsb = ferite_find_namespace(script, script->mainns, "String", FENS_NS);
	FeriteNamespace *string_namespace = (nsb && nsb->data ? nsb->data : ferite_register_namespace(script, "String", script->mainns));
	/* FeriteNamespace *array_namespace = (nsb->data ? nsb->data : ferite_register_namespace(script, "String", script->mainns)); */
	FeriteFunction *length_function = ferite_create_external_function(script, "length", ferite_string_length, "s");
	FeriteFunction *byte_to_number_function = ferite_create_external_function(script, "byteToNumber", ferite_string_byte_to_number, "s");
	FeriteFunction *number_to_byte_function = ferite_create_external_function(script, "numberToByte", ferite_string_number_to_byte, "n");
	FeriteFunction *to_number_function = ferite_create_external_function(script, "toNumber", ferite_string_to_number, "s");
	ferite_register_ns_function(script, string_namespace, length_function);
	ferite_register_ns_function(script, string_namespace, byte_to_number_function);
	ferite_register_ns_function(script, string_namespace, number_to_byte_function);
	ferite_register_ns_function(script, string_namespace, to_number_function);
}

