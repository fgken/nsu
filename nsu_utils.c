#include "stdio.h"
#include "string.h"

#include "nsu_utils.h"
#include "nsu.h"
#include "debuglib.h"

int nsu_push_header(struct nsu_context *context, const void *data, int size)
{
	printd("push_header\n");

	if(context == NULL || context->bufpos - size < 0){
		return -1;
	}

	context->bufpos -= size;
	memcpy(context->buf + context->bufpos, data, size);
	
	return 0;
}

int nsu_pop_header(struct nsu_context *context, void *data, int size)
{
	printd("pop_header\n");
}

