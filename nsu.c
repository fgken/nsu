#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "nsu.h"
#include "debuglib.h"

int nsu_create(struct nsu_context **context)
{
	struct nsu_context *new_context;

	printd("nsu_create\n");

	new_context = malloc(sizeof(struct nsu_context));

	if(new_context == NULL)
	{
		printd("Error: malloc failure\n");
		return -1;
	}

	memset(new_context, 0x00, sizeof(struct nsu_context));
	*context = new_context;

	return 0;
}

void nsu_destroy(struct nsu_context **context)
{
	printd("nsu_destroy\n");

	if(context != NULL && *context != NULL)
	{
		free(*context);
		*context = NULL;
	}
}

int nsu_send(struct nsu_context *context, void *buf, int size)
{
	printd("nsu_send\n");
	return 0;
}

int nsu_recv(struct nsu_context *context, void *buf, int size)
{
	printd("nus_recv\n");
	return 0;
}
