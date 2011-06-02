#include "include.h"

typedef struct __client {
	ENetHost *host;
	ENetPeer *peer;
} Client;

FE_NATIVE_FUNCTION( game_engine_network_server_start )
{
	double port = 0.0;
	
	ferite_get_parameters(params, 1, &port);
	
	ENetAddress address;
	ENetHost *server = NULL;
	
	address.host = ENET_HOST_ANY;
	address.port = (enet_uint16)port;
	
	server = enet_host_create(&address, 32, 0, 0);
	if( server )
	{
		FeriteNamespaceBucket *nsb = ferite_find_namespace(script, script->mainns, "Network.Server", FENS_CLS);
		FeriteVariable *server_variable = ferite_build_object(script, nsb->data);
		VAO(server_variable)->odata = server;
		MARK_VARIABLE_AS_DISPOSABLE(server_variable);
		FE_RETURN_VAR(server_variable);
	}
	FE_RETURN_NULL_OBJECT;
}

FE_NATIVE_FUNCTION( game_engine_network_server_destroy )
{
	FeriteObject *self = FE_CONTAINER_TO_OBJECT;
	ENetHost *server = (ENetHost *)self->odata;
	enet_host_destroy(server);
	self->odata = NULL;
	FE_RETURN_VOID;
}

FE_NATIVE_FUNCTION( game_engine_network_server_service )
{
	FeriteObject *self = FE_CONTAINER_TO_OBJECT;
	ENetHost *server = (ENetHost *)self->odata;
	ENetEvent event;
	
	double timeout = 0.0;
	ferite_get_parameters(params, 1, &timeout);
	
	if( enet_host_service(server, &event, (enet_uint32)timeout) )
	{
		FeriteVariable *message_variable = NULL;
		
		switch( event.type )
		{
			case ENET_EVENT_TYPE_NONE:
			{
				break;
			}
			case ENET_EVENT_TYPE_CONNECT:
			{
				FeriteVariable *peer_variable = NULL;
				FeriteVariable *type_variable = NULL;

				type_variable = ferite_create_number_long_variable(script, "type", event.type, FE_STATIC);
				
				peer_variable = ferite_build_object(script, (ferite_find_namespace(script, script->mainns, "Network.Peer", FENS_CLS))->data);
				message_variable = ferite_build_object(script, (ferite_find_namespace(script, script->mainns, "Network.ConnectMessage", FENS_CLS))->data);
				
				ferite_object_set_var(script, VAO(message_variable), "type", type_variable);
				ferite_object_set_var(script, VAO(message_variable), "peer", peer_variable);
				
				VAO(peer_variable)->odata = event.peer;

				MARK_VARIABLE_AS_DISPOSABLE(message_variable);
				
				break;
			}
			case ENET_EVENT_TYPE_DISCONNECT:
			{
				FeriteVariable *peer_variable = NULL;
				FeriteVariable *type_variable = NULL;
				
				type_variable = ferite_create_number_long_variable(script, "type", event.type, FE_STATIC);
				
				peer_variable = ferite_build_object(script, (ferite_find_namespace(script, script->mainns, "Network.Peer", FENS_CLS))->data);;
				message_variable = ferite_build_object(script, (ferite_find_namespace(script, script->mainns, "Network.DisconnectMessage", FENS_CLS))->data);
				
				ferite_object_set_var(script, VAO(message_variable), "type", type_variable);
				ferite_object_set_var(script, VAO(message_variable), "peer", peer_variable);
				
				MARK_VARIABLE_AS_DISPOSABLE(message_variable);
				
				free(event.peer->data);
				
				break;
			}
			case ENET_EVENT_TYPE_RECEIVE:
			{
				FeriteVariable *peer_variable = NULL;
				FeriteVariable *type_variable = NULL;
				FeriteVariable *data_variable = NULL;

				type_variable = ferite_create_number_long_variable(script, "type", event.type, FE_STATIC);
				data_variable = ferite_create_string_variable_from_ptr(script, "data", (char *)event.packet->data, event.packet->dataLength, FE_CHARSET_DEFAULT, FE_STATIC);
				
				peer_variable = ferite_build_object(script, (ferite_find_namespace(script, script->mainns, "Network.Peer", FENS_CLS))->data);
				message_variable = ferite_build_object(script, (ferite_find_namespace(script, script->mainns, "Network.DataMessage", FENS_CLS))->data);
				
				ferite_object_set_var(script, VAO(message_variable), "type", type_variable);
				ferite_object_set_var(script, VAO(message_variable), "peer", peer_variable);
				ferite_object_set_var(script, VAO(message_variable), "data", data_variable);
				
				MARK_VARIABLE_AS_DISPOSABLE(message_variable);
				
				VAO(peer_variable)->odata = event.peer;
				
				enet_packet_destroy(event.packet);
				
				break;
			}
			default:
			{
				break;
			}
		}
	
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
	ENetHost *server = (ENetHost *)self->odata;
	
	FeriteObject *peer = NULL;
	FeriteString *data = NULL;
	
	ENetPacket *packet = NULL;
	
	ferite_get_parameters(params, 2, &peer, &data);
	
	packet = enet_packet_create(data->data, data->length, ENET_PACKET_FLAG_NO_ALLOCATE | ENET_PACKET_FLAG_RELIABLE);
	
	/*
	printf("Test (1).\n");
	if( !peer ) {
		printf("Oh no (1).\n");
	}
	printf("Test (2).\n");
	if( !VAO(peer) ) {
		printf("Oh no (2).\n");
	}
	printf("Test (3).\n");
	if( VAO(peer)->odata ) {
		printf("Oh no (3).\n");
	}
	*/
	
	enet_peer_send((ENetPeer *)peer->odata, 0, packet);
	enet_host_flush(server);
	
	FE_RETURN_VOID;
}

FE_NATIVE_FUNCTION( game_engine_network_client_start )
{
	FeriteString *hostname = NULL;
	double port = 0.0;
	
	ENetAddress address;
	ENetHost *host = NULL;
	
	ferite_get_parameters(params, 2, &hostname, &port);
	
	enet_address_set_host(&address, hostname->data);
	address.port = port;
	
	host = enet_host_create(NULL, 1, 0, 0);
	
	if( host )
	{
		ENetPeer *peer = NULL;
		peer = enet_host_connect(host, &address, 2);
		
		if( peer )
		{
			Client *client = (Client *)malloc(sizeof(Client));
			FeriteVariable *client_variable = NULL;
			client->host = host;
			client->peer = peer;
			client_variable = ferite_build_object(script, (ferite_find_namespace(script, script->mainns, "Network.Client", FENS_CLS))->data);
			VAO(client_variable)->odata = client;
			MARK_VARIABLE_AS_DISPOSABLE(client_variable);
			FE_RETURN_VAR(client_variable);
		}
	}
	FE_RETURN_NULL_OBJECT;
}

FE_NATIVE_FUNCTION( game_engine_network_client_destroy )
{
	FeriteObject *self = FE_CONTAINER_TO_OBJECT;
	Client *client = (Client *)self->odata;
	enet_host_destroy(client->host);
	free(client);
	self->odata = NULL;
	FE_RETURN_VOID;
}

FE_NATIVE_FUNCTION( game_engine_network_client_service )
{
	FeriteObject *self = FE_CONTAINER_TO_OBJECT;
	Client *client = (Client *)self->odata;
	ENetEvent event;
	
	double timeout = 0.0;
	ferite_get_parameters(params, 1, &timeout);
	
	if( enet_host_service(client->host, &event, (enet_uint32)timeout) )
	{
		FeriteVariable *message_variable = NULL;
		
		switch( event.type )
		{
			case ENET_EVENT_TYPE_NONE:
			{
				break;
			}
			case ENET_EVENT_TYPE_CONNECT:
			{
				FeriteVariable *type_variable = NULL;
				type_variable = ferite_create_number_long_variable(script, "type", event.type, FE_STATIC);
				message_variable = ferite_build_object(script, (ferite_find_namespace(script, script->mainns, "Network.ConnectMessage", FENS_CLS))->data);
				ferite_object_set_var(script, VAO(message_variable), "type", type_variable);
				MARK_VARIABLE_AS_DISPOSABLE(message_variable);
				break;
			}
			case ENET_EVENT_TYPE_DISCONNECT:
			{
				FeriteVariable *type_variable = NULL;
				type_variable = ferite_create_number_long_variable(script, "type", event.type, FE_STATIC);
				message_variable = ferite_build_object(script, (ferite_find_namespace(script, script->mainns, "Network.DisconnectMessage", FENS_CLS))->data);
				ferite_object_set_var(script, VAO(message_variable), "type", type_variable);
				MARK_VARIABLE_AS_DISPOSABLE(message_variable);
				break;
			}
			case ENET_EVENT_TYPE_RECEIVE:
			{
				FeriteVariable *type_variable = NULL;
				FeriteVariable *data_variable = NULL;
				type_variable = ferite_create_number_long_variable(script, "type", event.type, FE_STATIC);
				data_variable = ferite_create_string_variable_from_ptr(script, "data", (char *)event.packet->data, event.packet->dataLength, FE_CHARSET_DEFAULT, FE_STATIC);
				message_variable = ferite_build_object(script, (ferite_find_namespace(script, script->mainns, "Network.DataMessage", FENS_CLS))->data);
				ferite_object_set_var(script, VAO(message_variable), "type", type_variable);
				ferite_object_set_var(script, VAO(message_variable), "data", data_variable);
				MARK_VARIABLE_AS_DISPOSABLE(message_variable);
				enet_packet_destroy(event.packet);
				break;
			}
			default:
			{
				break;
			}
		}
	
		if( message_variable )
		{
			FE_RETURN_VAR(message_variable);
		}
	}
	FE_RETURN_NULL_OBJECT;
}

FE_NATIVE_FUNCTION( game_engine_network_client_send )
{
	FeriteObject *self = FE_CONTAINER_TO_OBJECT;
	Client *client = (Client *)self->odata;
	
	FeriteString *data = NULL;
	
	ENetPacket *packet = NULL;
	
	ferite_get_parameters(params, 1, &data);
	
	packet = enet_packet_create(data->data, data->length, ENET_PACKET_FLAG_NO_ALLOCATE | ENET_PACKET_FLAG_RELIABLE);
	
	enet_peer_send(client->peer, 0, packet);
	enet_host_flush(client->host);
	
	FE_RETURN_VOID;
}

void game_engine_network_init( FeriteScript *script )
{
	FeriteNamespaceBucket *nsb = ferite_find_namespace(script, script->mainns, "Network", FENS_NS);
	FeriteNamespace *network_namespace = (nsb && nsb->data ? nsb->data : ferite_register_namespace(script, "Network", script->mainns));
	
	FeriteClass *server_class = ferite_register_inherited_class(script, network_namespace, "Server", NULL);
	FeriteClass *client_class = ferite_register_inherited_class(script, network_namespace, "Client", NULL);
	
	ferite_register_ns_variable(script, network_namespace, "MESSAGE_DATA", ferite_create_number_long_variable(script, "MESSAGE_DATA", ENET_EVENT_TYPE_RECEIVE, FE_STATIC));
	ferite_register_ns_variable(script, network_namespace, "MESSAGE_CONNECT", ferite_create_number_long_variable(script, "MESSAGE_CONNECT", ENET_EVENT_TYPE_CONNECT, FE_STATIC));
	ferite_register_ns_variable(script, network_namespace, "MESSAGE_DISCONNECT", ferite_create_number_long_variable(script, "MESSAGE_DISCONNECT", ENET_EVENT_TYPE_DISCONNECT, FE_STATIC));

	ferite_register_inherited_class(script, network_namespace, "Peer", NULL);
	
	ferite_register_inherited_class(script, network_namespace, "ConnectMessage", NULL);
	ferite_register_inherited_class(script, network_namespace, "DisconnectMessage", NULL);
	ferite_register_inherited_class(script, network_namespace, "DataMessage", NULL);
	
	FeriteFunction *server_start_function = ferite_create_external_function(script, "start", game_engine_network_server_start, "n");
	FeriteFunction *server_destroy_function = ferite_create_external_function(script, "destroy", game_engine_network_server_destroy, "");
	FeriteFunction *server_service_function = ferite_create_external_function(script, "service", game_engine_network_server_service, "n");
	FeriteFunction *server_send_function = ferite_create_external_function(script, "send", game_engine_network_server_send, "os");
	
	ferite_register_class_function(script, server_class, server_start_function, FE_TRUE);
	ferite_register_class_function(script, server_class, server_destroy_function, FE_FALSE);
	ferite_register_class_function(script, server_class, server_service_function, FE_FALSE);
	ferite_register_class_function(script, server_class, server_send_function, FE_FALSE);
	
	FeriteFunction *client_start_function = ferite_create_external_function(script, "start", game_engine_network_client_start, "sn");
	FeriteFunction *client_destroy_function = ferite_create_external_function(script, "destroy", game_engine_network_client_destroy, "");
	FeriteFunction *client_service_function = ferite_create_external_function(script, "service", game_engine_network_client_service, "n");
	FeriteFunction *client_send_function = ferite_create_external_function(script, "send", game_engine_network_client_send, "s");
	
	ferite_register_class_function(script, client_class, client_start_function, FE_TRUE);
	ferite_register_class_function(script, client_class, client_destroy_function, FE_FALSE);
	ferite_register_class_function(script, client_class, client_service_function, FE_FALSE);
	ferite_register_class_function(script, client_class, client_send_function, FE_FALSE);
}

