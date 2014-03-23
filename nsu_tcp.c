#include "stdio.h"

#include "nsu.h"
#include "debuglib.h"

int nsu_tcp_push_header(struct nsu_context *context)
{
	char tcp_header[20];
	int size;
	int i;

	printd("nsu_tcp_push_header\n");

	// FIXME:
	size = 20;
	printd("Todo: push tcp header in nsu_tcp_push_header\n");

	nsu_push_header(context, tcp_header, size);

	return 0;
}

int nsu_tcp_recv(struct nsu_context *context, void *buf, int size)
{
	printd("nsu_ether_recv\n");
	return 0;
}
