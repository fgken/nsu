#include "stdio.h"
#include "stdio.h"
#include "nsu.h"
#include "debuglib.h"

int nsu_ipv6_push_header(struct nsu_context *context)
{
	char ipv6_header[20];
	int size;
	int i;

	printd("nsu_ipv6_push_header\n");

	size = 20;

	// FIXME:
	printd("Todo: push ipv6 header in nsu_ipv6_push_header\n");

	nsu_push_header(context, ipv6_header, size);

	return 0;
}

int nsu_ipv6_recv(struct nsu_context *context, void *buf, int size)
{
	printd("nsu_ipv6_recv\n");
	return 0;
}
