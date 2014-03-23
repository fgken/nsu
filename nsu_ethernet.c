#include "nsu.h"
#include "debuglib.h"

int nsu_ethernet_push_header(struct nsu_context *context)
{
	char ethernet_header[14];
	int size;
	int i;

	printd("nsu_ethernet_push_header\n");

	size = 14;
	// FIXME:
	printd("Todo: push ethernet header in nsu_ethernet_push_header\n");

	nsu_push_header(context, ethernet_header, size);

	return 0;
}

int nsu_ethernet_recv(struct nsu_context *context)
{
	printd("nsu_ether_recv\n");
	return 0;
}
