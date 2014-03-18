#include <stdio.h>
#include <string.h>

#include "nsu.h"
#include "debuglib.h"

int main(int argc, char *argv[])
{
	struct nsu_context *context;
	char buf[100];
	int size;
	int i;

	puts("=== Network Stack in Userspace ===");

	nsu_create(&context);

	for(i=0; i<50; i++) buf[i] = i;
	size = 50;

	context->proto_l2 = NSU_L2_ETHERNET;
	context->proto_l3 = NSU_L3_IPV4;
	context->proto_l4 = NSU_L4_UDP;
	strcpy(context->ifname, "eth0");

	printd("send buffer data:\n");
	memdump(stdout, &context->buf[context->bufpos], NSU_BUFFER_SIZE-context->bufpos);

	nsu_send(context, buf, size);

	printd("send buffer data:\n");
	memdump(stdout, &context->buf[context->bufpos], NSU_BUFFER_SIZE-context->bufpos);

	nsu_destroy(&context);

	puts("=== Finished ===");

	return 0;
}	
