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

		switch(context->proto_l4){
			case NSU_L4_UDP:
				//return nsu_udp_send(context);
			case NSU_L4_TCP:
				nsu_push_header(context, buf, size);
				return nsu_tcp_send(context);
		}
	}
	return 0;
}

int nsu_recv(struct nsu_context *context, void *buf, int size)
{
	printd("nus_recv\n");
	return 0;
}
