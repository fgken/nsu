#include <stdio.h>
#include <string.h>

#include "nsu.h"
#include "debuglib.h"

int main(int argc, char *argv[])
{
	struct nsu_context *context;
	struct nsu_ethernet eth;
	char buf[100];
	int size;
	int i;

	puts("=== Network Stack in Userspace ===");

	nsu_create(&context);

	for(i=0; i<50; i++) buf[i] = i;
	size = 50;

	nsu_set_protocol(context, NSU_L2_ETHERNET, &eth, sizeof(eth));
	strcpy(context->ifname, "eth0");

	dump_nsu(context);

	printd("send buffer data:\n");
	memdump(stdout, &context->buf[context->bufpos], NSU_BUFFER_SIZE-context->bufpos);

	nsu_send(context, buf, size);

	printd("send buffer data:\n");
	memdump(stdout, &context->buf[context->bufpos], NSU_BUFFER_SIZE-context->bufpos);

	nsu_destroy(&context);

	puts("=== Finished ===");

	return 0;
}	
