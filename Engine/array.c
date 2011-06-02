#include "include.h"

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

/*FE_NATIVE_FUNCTION( ferite_array_push )
{
	FeriteUnifiedArray *a = NULL;
	FeriteVariable *v = NULL;
	ferite_get_parameters(params, 2, &a, &v);
	ferite_uarray_push(script, a, v);
	FE_RETURN_VOID;
}

FE_NATIVE_FUNCTION( ferite_array_pop )
{
	FeriteUnifiedArray *a = NULL;
	ferite_get_parameters(params, 1, &a);
    FeriteVariable *v = ferite_uarray_pop(script, a);
    FE_RETURN_VAR(v);
}

FE_NATIVE_FUNCTION( ferite_array_unshift )
{
	FeriteUnifiedArray *a = NULL;
	FeriteString *v = NULL;
	ferite_get_parameters(params, 2, &a, &v);
	printf("unshift: %s\n", v->data);
    ferite_uarray_unshift(script, a, v);
    FE_RETURN_VOID;
}

FE_NATIVE_FUNCTION( ferite_array_shift )
{
	FeriteUnifiedArray *a = NULL;
	ferite_get_parameters(params, 1, &a);
    FeriteVariable *v = ferite_uarray_shift(script, a);
    FE_RETURN_VAR(v);
}*/

FE_NATIVE_FUNCTION( ferite_array_delete_at )
{
	FeriteUnifiedArray *a = NULL;
	double index = 0.0;
	ferite_get_parameters(params, 2, &a, &index);
	ferite_uarray_del_index(script, a, (int)index);
	FE_RETURN_VOID;
}

void ferite_array_init( FeriteScript *script )
{
	FeriteNamespaceBucket *nsb = ferite_find_namespace(script, script->mainns, "Array", FENS_NS);
	FeriteNamespace *array_namespace = (nsb && nsb->data ? nsb->data : ferite_register_namespace(script, "Array", script->mainns));
	/* FeriteNamespace *array_namespace = (nsb->data ? nsb->data : ferite_register_namespace(script, "Array", script->mainns)); */
	FeriteFunction *size_function = ferite_create_external_function(script, "size", ferite_array_size, "a");
	FeriteFunction *key_exists_function = ferite_create_external_function(script, "keyExists", ferite_array_key_exists, "as");
	FeriteFunction *delete_at_function = ferite_create_external_function(script, "deleteAt", ferite_array_delete_at, "an");
	/*FeriteFunction *push_function = ferite_create_external_function(script, "push", ferite_array_push, "av");
	FeriteFunction *pop_function = ferite_create_external_function(script, "pop", ferite_array_pop, "a");
	FeriteFunction *unshift_function = ferite_create_external_function(script, "unshift", ferite_array_unshift, "as");
	FeriteFunction *shift_function = ferite_create_external_function(script, "shift", ferite_array_shift, "a");*/
	ferite_register_ns_function(script, array_namespace, size_function);
	ferite_register_ns_function(script, array_namespace, key_exists_function);
	ferite_register_ns_function(script, array_namespace, delete_at_function);
	/*ferite_register_ns_function(script, array_namespace, pop_function);
	ferite_register_ns_function(script, array_namespace, push_function);
	ferite_register_ns_function(script, array_namespace, unshift_function);
	ferite_register_ns_function(script, array_namespace, shift_function);*/
}

