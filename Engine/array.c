#include "array.h"

FE_NATIVE_FUNCTION( ferite_array_size )
{
	FeriteUnifiedArray *a = NULL;
	ferite_get_parameters(params, 1, &a);
	FE_RETURN_LONG( a->size );
}

FE_NATIVE_FUNCTION( ferite_array_key_exists )
{
	FeriteUnifiedArray *a = NULL;
	FeriteString *key = NULL;
	ferite_get_parameters(params, 2, &a, &key);
	if( ferite_hash_get(script, a->hash, key->data) != NULL )
	{
		FE_RETURN_TRUE;
	}
	FE_RETURN_FALSE;
}

void ferite_array_init( FeriteScript *script )
{
	FeriteNamespaceBucket *nsb = ferite_find_namespace(script, script->mainns, "Array", FENS_NS);
	FeriteNamespace *array_namespace = (nsb && nsb->data ? nsb->data : ferite_register_namespace(script, "Array", script->mainns));
	/* FeriteNamespace *array_namespace = (nsb->data ? nsb->data : ferite_register_namespace(script, "Array", script->mainns)); */
	FeriteFunction *size_function = ferite_create_external_function(script, "size", ferite_array_size, "a");
	FeriteFunction *key_exists_function = ferite_create_external_function(script, "keyExists", ferite_array_key_exists, "as");
	ferite_register_ns_function(script, array_namespace, size_function);
	ferite_register_ns_function(script, array_namespace, key_exists_function);
}

