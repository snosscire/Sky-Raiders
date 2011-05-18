#include "network.h"
#include <grapple/grapple.h>

FE_NATIVE_FUNCTION( game_engine_network_server_start )
{
	FeriteString *name = NULL;
	FeriteString *version = NULL;
	double port = 0.0;
	FeriteString *session = NULL;
	
	ferite_get_parameters(params, 4, &name, &version, &port, &session);
	
	grapple_server *server = fmalloc(sizeof(grapple_server));
	
	(*server) = grapple_server_init(name->data, version->data);
	//grapple_server_ip_set(server, "127.0.0.1");
	grapple_server_port_set(*server, port);
	grapple_server_protocol_set(*server, GRAPPLE_PROTOCOL_UDP);
	grapple_server_session_set(*server, session->data);
	//grapple_server_maxusers_set(server, 8);
	grapple_server_start(*server);
	
	FeriteNamespaceBucket *nsb = ferite_find_namespace(script, script->mainns, "Network.Server", FENS_CLS);
	FeriteVariable *server_variable = ferite_build_object(script, nsb->data);
	VAO(server_variable)->odata = server;
	MARK_VARIABLE_AS_DISPOSABLE(server_variable);
	FE_RETURN_VAR(server_variable);
}

FE_NATIVE_FUNCTION( game_engine_network_server_destroy )
{
	FeriteObject *self = FE_CONTAINER_TO_OBJECT;
	grapple_server server = *((grapple_server *)self->odata);
	grapple_server_destroy(server);
	self->odata = NULL;
	FE_RETURN_VOID;
}

FE_NATIVE_FUNCTION( game_engine_network_server_messages_waiting )
{
	FeriteObject *self = FE_CONTAINER_TO_OBJECT;
	grapple_server server = *((grapple_server *)self->odata);
	FE_RETURN_VAR(ferite_create_boolean_variable(script, "messagesWaiting" , grapple_server_messages_waiting(server), FE_STATIC));
}

FE_NATIVE_FUNCTION( game_engine_network_server_pull_message )
{
	FeriteObject *self = FE_CONTAINER_TO_OBJECT;
	grapple_server server = *((grapple_server *)self->odata);
	grapple_message *message = grapple_server_message_pull(server);
	
	if( message )
	{
		FeriteVariable *message_variable = NULL;
		
		switch( message->type )
		{
			case GRAPPLE_MSG_NEW_USER:
			{
				FeriteNamespaceBucket *nsb = ferite_find_namespace(script, script->mainns, "Network.NewUserMessage", FENS_CLS);
				message_variable = ferite_build_object(script, nsb->data);
				FeriteVariable *type_variable = ferite_create_number_long_variable(script, "type", message->type, FE_STATIC);
				FeriteVariable *id_variable = ferite_create_number_long_variable(script, "id", message->NEW_USER.id, FE_STATIC);
				FeriteVariable *name_variable = ferite_create_string_variable_from_ptr(script, "name", message->NEW_USER.name, 0, FE_CHARSET_DEFAULT, FE_STATIC);
				FeriteVariable *me_variable = ferite_create_boolean_variable(script, "me", message->NEW_USER.me, FE_STATIC);
				MARK_VARIABLE_AS_DISPOSABLE(type_variable);
				MARK_VARIABLE_AS_DISPOSABLE(id_variable);
				MARK_VARIABLE_AS_DISPOSABLE(name_variable);
				MARK_VARIABLE_AS_DISPOSABLE(me_variable);
				ferite_object_set_var(script, VAO(message_variable), "type", type_variable);
				ferite_object_set_var(script, VAO(message_variable), "id", id_variable);
				ferite_object_set_var(script, VAO(message_variable), "name", name_variable);
				ferite_object_set_var(script, VAO(message_variable), "me", me_variable);
				break;
			}
			case GRAPPLE_MSG_USER_DISCONNECTED:
			{
				FeriteNamespaceBucket *nsb = ferite_find_namespace(script, script->mainns, "Network.UserDisconnectedMessage", FENS_CLS);
				message_variable = ferite_build_object(script, nsb->data);
				FeriteVariable *type_variable = ferite_create_number_long_variable(script, "type", message->type, FE_STATIC);
				FeriteVariable *id_variable = ferite_create_number_long_variable(script, "id", message->USER_DISCONNECTED.id, FE_STATIC);
				MARK_VARIABLE_AS_DISPOSABLE(type_variable);
				MARK_VARIABLE_AS_DISPOSABLE(id_variable);
				ferite_object_set_var(script, VAO(message_variable), "type", type_variable);
				ferite_object_set_var(script, VAO(message_variable), "id", id_variable);
				break;
			}
			case GRAPPLE_MSG_USER_NAME:
			{
				FeriteNamespaceBucket *nsb = ferite_find_namespace(script, script->mainns, "Network.UserNameMessage", FENS_CLS);
				message_variable = ferite_build_object(script, nsb->data);
				FeriteVariable *type_variable = ferite_create_number_long_variable(script, "type", message->type, FE_STATIC);
				FeriteVariable *id_variable = ferite_create_number_long_variable(script, "id", message->USER_NAME.id, FE_STATIC);
				FeriteVariable *name_variable = ferite_create_string_variable_from_ptr(script, "name", message->USER_NAME.name, 0, FE_CHARSET_DEFAULT, FE_STATIC);
				MARK_VARIABLE_AS_DISPOSABLE(type_variable);
				MARK_VARIABLE_AS_DISPOSABLE(id_variable);
				MARK_VARIABLE_AS_DISPOSABLE(name_variable);
				ferite_object_set_var(script, VAO(message_variable), "type", type_variable);
				ferite_object_set_var(script, VAO(message_variable), "id", id_variable);
				ferite_object_set_var(script, VAO(message_variable), "name", name_variable);
				break;
			}
			case GRAPPLE_MSG_USER_MSG:
			{
				FeriteNamespaceBucket *nsb = ferite_find_namespace(script, script->mainns, "Network.UserDataMessage", FENS_CLS);
				message_variable = ferite_build_object(script, nsb->data);
				FeriteVariable *type_variable = ferite_create_number_long_variable(script, "type", message->type, FE_STATIC);
				FeriteVariable *id_variable = ferite_create_number_long_variable(script, "id", message->USER_MSG.id, FE_STATIC);
				FeriteVariable *data_variable = ferite_create_string_variable_from_ptr(script, "data", (char *)message->USER_MSG.data, 0, FE_CHARSET_DEFAULT, FE_STATIC);
				MARK_VARIABLE_AS_DISPOSABLE(type_variable);
				MARK_VARIABLE_AS_DISPOSABLE(id_variable);
				MARK_VARIABLE_AS_DISPOSABLE(data_variable);
				ferite_object_set_var(script, VAO(message_variable), "type", type_variable);
				ferite_object_set_var(script, VAO(message_variable), "id", id_variable);
				ferite_object_set_var(script, VAO(message_variable), "data", data_variable);
				break;
			}
			default:
			{
				break;
			}
		}
	
		grapple_message_dispose(message);
		
		if( message_variable )
		{
			FE_RETURN_VAR(message_variable);
		}
	}
	FE_RETURN_NULL_OBJECT;
}

FE_NATIVE_FUNCTION( game_engine_network_server_send )
{
	FeriteObject *self = FE_CONTAINER_TO_OBJECT;
	grapple_server server = *((grapple_server *)self->odata);
	
	double target = 0.0;
	double flags = 0.0;
	FeriteString *data = NULL;
	
	ferite_get_parameters(params, 3, &target, &flags, &data);
	
	grapple_server_send(server, target, flags, data->data, data->length);
	
	FE_RETURN_VOID;
}

void game_engine_network_init( FeriteScript *script )
{
	FeriteNamespaceBucket *nsb = ferite_find_namespace(script, script->mainns, "Network", FENS_NS);
	FeriteNamespace *network_namespace = (nsb && nsb->data ? nsb->data : ferite_register_namespace(script, "Network", script->mainns));
	
	FeriteClass *server_class = ferite_register_inherited_class(script, network_namespace, "Server", NULL);
	FeriteClass *client_class = ferite_register_inherited_class(script, network_namespace, "Client", NULL);
	
	ferite_register_ns_variable(script, network_namespace, "MESSAGE_NONE", ferite_create_number_long_variable(script, "MESSAGE_NONE", GRAPPLE_MSG_NONE, FE_STATIC));
	ferite_register_ns_variable(script, network_namespace, "MESSAGE_NEW_USER", ferite_create_number_long_variable(script, "MESSAGE_NEW_USER", GRAPPLE_MSG_NEW_USER, FE_STATIC));
	ferite_register_ns_variable(script, network_namespace, "MESSAGE_NEW_USER_ME", ferite_create_number_long_variable(script, "MESSAGE_NEW_USER_ME", GRAPPLE_MSG_NEW_USER_ME, FE_STATIC));
	ferite_register_ns_variable(script, network_namespace, "MESSAGE_USER_NAME", ferite_create_number_long_variable(script, "MESSAGE_USER_NAME", GRAPPLE_MSG_USER_NAME, FE_STATIC));
	ferite_register_ns_variable(script, network_namespace, "MESSAGE_USER_DATA", ferite_create_number_long_variable(script, "MESSAGE_USER_DATA", GRAPPLE_MSG_USER_MSG, FE_STATIC));
	ferite_register_ns_variable(script, network_namespace, "MESSAGE_SESSION_NAME", ferite_create_number_long_variable(script, "MESSAGE_SESSION_NAME", GRAPPLE_MSG_SESSION_NAME, FE_STATIC));
	ferite_register_ns_variable(script, network_namespace, "MESSAGE_USER_DISCONNECTED", ferite_create_number_long_variable(script, "MESSAGE_USER_DISCONNECTED", GRAPPLE_MSG_USER_DISCONNECTED, FE_STATIC));
	ferite_register_ns_variable(script, network_namespace, "MESSAGE_SERVER_DISCONNECTED", ferite_create_number_long_variable(script, "MESSAGE_SERVER_DISCONNECTED", GRAPPLE_MSG_SERVER_DISCONNECTED, FE_STATIC));
	ferite_register_ns_variable(script, network_namespace, "MESSAGE_CONNECTION_REFUSED", ferite_create_number_long_variable(script, "MESSAGE_CONNECTION_REFUSED", GRAPPLE_MSG_CONNECTION_REFUSED, FE_STATIC));
	ferite_register_ns_variable(script, network_namespace, "MESSAGE_PING", ferite_create_number_long_variable(script, "MESSAGE_PING", GRAPPLE_MSG_PING, FE_STATIC));
	ferite_register_ns_variable(script, network_namespace, "MESSAGE_GROUP_CREATE", ferite_create_number_long_variable(script, "MESSAGE_GROUP_CREATE", GRAPPLE_MSG_GROUP_CREATE, FE_STATIC));
	ferite_register_ns_variable(script, network_namespace, "MESSAGE_GROUP_ADD", ferite_create_number_long_variable(script, "MESSAGE_GROUP_ADD", GRAPPLE_MSG_GROUP_ADD, FE_STATIC));
	ferite_register_ns_variable(script, network_namespace, "MESSAGE_GROUP_REMOVE", ferite_create_number_long_variable(script, "MESSAGE_GROUP_REMOVE", GRAPPLE_MSG_GROUP_REMOVE, FE_STATIC));
	ferite_register_ns_variable(script, network_namespace, "MESSAGE_GROUP_DELETE", ferite_create_number_long_variable(script, "MESSAGE_GROUP_DELETE", GRAPPLE_MSG_GROUP_DELETE, FE_STATIC));
	ferite_register_ns_variable(script, network_namespace, "MESSAGE_YOU_ARE_HOST", ferite_create_number_long_variable(script, "MESSAGE_YOU_ARE_HOST", GRAPPLE_MSG_YOU_ARE_HOST, FE_STATIC));
	ferite_register_ns_variable(script, network_namespace, "MESSAGE_CONFIRM_RECEIVED", ferite_create_number_long_variable(script, "MESSAGE_CONFIRM_RECEIVED", GRAPPLE_MSG_CONFIRM_RECEIVED, FE_STATIC));
	ferite_register_ns_variable(script, network_namespace, "MESSAGE_CONFIRM_TIMEOUT", ferite_create_number_long_variable(script, "MESSAGE_CONFIRM_TIMEOUT", GRAPPLE_MSG_CONFIRM_TIMEOUT, FE_STATIC));
	ferite_register_ns_variable(script, network_namespace, "MESSAGE_GAME_DESCRIPTION", ferite_create_number_long_variable(script, "MESSAGE_GAME_DESCRIPTION", GRAPPLE_MSG_GAME_DESCRIPTION, FE_STATIC));
	
	ferite_register_inherited_class(script, network_namespace, "NewUserMessage", NULL);
	ferite_register_inherited_class(script, network_namespace, "UserDisconnectedMessage", NULL);
	ferite_register_inherited_class(script, network_namespace, "UserNameMessage", NULL);
	ferite_register_inherited_class(script, network_namespace, "UserDataMessage", NULL);
	
	FeriteFunction *server_start_function = ferite_create_external_function(script, "start", game_engine_network_server_start, "ssns");
	FeriteFunction *server_destroy_function = ferite_create_external_function(script, "destroy", game_engine_network_server_destroy, "");
	FeriteFunction *server_messages_waiting_function = ferite_create_external_function(script, "messagesWaiting", game_engine_network_server_messages_waiting, "");
	FeriteFunction *server_pull_message_function = ferite_create_external_function(script, "pullMessage", game_engine_network_server_pull_message, "");
	FeriteFunction *server_send_function = ferite_create_external_function(script, "send", game_engine_network_server_send, "nns");
	
	ferite_register_class_function(script, server_class, server_start_function, FE_TRUE);
	ferite_register_class_function(script, server_class, server_destroy_function, FE_FALSE);
	ferite_register_class_function(script, server_class, server_messages_waiting_function, FE_FALSE);
	ferite_register_class_function(script, server_class, server_pull_message_function, FE_FALSE);
	ferite_register_class_function(script, server_class, server_send_function, FE_FALSE);
}

