#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "nsu.h"
#include "nsu_utils.h"
#include "debuglib.h"

int nsu_create(struct nsu_context **context)
{
	struct nsu_context *new_context;
	void *new_buf;

	printd("nsu_create\n");

	new_context = malloc(sizeof(struct nsu_context));
	new_buf = malloc(NSU_BUFFER_SIZE);

	if(new_context == NULL)
	{
		printd("Error: malloc failure\n");
		return -1;
	}

	memset(new_context, 0x00, sizeof(struct nsu_context));
	new_context->buf = new_buf;
	new_context->bufpos = NSU_BUFFER_SIZE;

	*context = new_context;

	return 0;
}

void nsu_destroy(struct nsu_context **context)
{
	printd("nsu_destroy\n");

	if(context != NULL && *context != NULL)
	{
		if((*context)->buf != NULL){
			free((*context)->buf);
			(*context)->buf = NULL;
		}

		if((*context)->struct_protol2 != NULL){
			free((*context)->struct_protol2);
			(*context)->struct_protol2 = NULL;
		}

		if((*context)->struct_protol3 != NULL){
			free((*context)->struct_protol3);
			(*context)->struct_protol3 = NULL;
		}

		if((*context)->struct_protol4 != NULL){
			free((*context)->struct_protol4);
			(*context)->struct_protol4 = NULL;
		}

		free(*context);
		*context = NULL;
	}
}

int nsu_send(struct nsu_context *context, void *buf, int size)
{
	printd("nsu_send\n");
	printd("send data:\n");
	memdump(stdout, buf, size);
	
	if(context != NULL){
		// push data
		nsu_push_header(context, buf, size);

		// push L4 header
		switch(context->proto_l4){
			case NSU_L4_UDP:
				nsu_udp_push_header(context);
				break;
			case NSU_L4_TCP:
				nsu_tcp_push_header(context);
				break;
			default:
				break;
		}

		// push L3 header
		switch(context->proto_l3){
			case NSU_L3_IPV4:
				nsu_ipv4_push_header(context);
				break;
			case NSU_L3_IPV6:
				nsu_ipv6_push_header(context);
				break;
			default:
				break;
		}

		// push L2 header
		switch(context->proto_l2){
			case NSU_L2_ETHERNET:
				nsu_ethernet_push_header(context);
				break;
			default:
				break;
		}

		// send packet through the nic(raw socket, tap etc.)
		nsu_nic_send(context);
	}
	return 0;
}

int nsu_recv(struct nsu_context *context, void *buf, int size)
{
	printd("nsu_recv\n");
	return 0;
}

int nsu_set_protocol(struct nsu_context *context, int proto_id, void *struct_proto, int size)
{
	void **old_struct;
	int  *old_proto_id;
	void **new_struct;

	printd("nsu_set_protocol\n");

	if(context == NULL || struct_proto == NULL || size < 0){
		return -1;
	}

	new_struct = malloc(size);
	if(new_struct == NULL){
		return -1;
	}
	memcpy(new_struct, struct_proto, size);

	nsu_get_proto_struct(context, nsu_get_layer(proto_id), &old_proto_id, &old_struct);
	if(*old_struct != NULL){
		free(*old_struct);
		*old_struct = NULL;
	}

	*old_proto_id = proto_id;
	*old_struct = new_struct;
}
