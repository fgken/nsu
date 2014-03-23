#include "nsu.h"
#include "debuglib.h"

int nsu_udp_push_header(struct nsu_context *context)
{
	char udp_header[20];
	int size;
	int i;

	printd("nsu_udp_push_header\n");

	// FIXME:
	size = 20;
	printd("Todo: push udp header in nsu_udp_push_header\n");

	nsu_push_header(context, udp_header, size);

	return 0;
}


