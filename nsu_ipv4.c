#include "stdio.h"
#include "stdio.h"
#include "nsu.h"
#include "debuglib.h"

int nsu_ipv4_push_header(struct nsu_context *context)
{
	char ipv4_header[20];
	int size;
	int i;

	printd("nsu_ipv4_push_header\n");

	size = 20;

	// FIXME:
	printd("Todo: push ipv4 header in nsu_ipv4_push_header\n");

	nsu_push_header(context, ipv4_header, size);

	return 0;
}

int nsu_ipv4_recv(struct nsu_context *context, void *buf, int size)
{
	printd("nsu_ipv4_recv\n");
	return 0;
}
