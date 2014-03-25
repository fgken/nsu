#include "nsu.h"
#include "debuglib.h"

int nsu_udp_push_header(struct nsu_context *context)
{
	struct nsu_udp *udpinfo;
	char udp_header[8];
	int size;
	int i;

	printd("nsu_udp_push_header\n");

	if(context == NULL || context->struct_protol4 == NULL){
		return -1;
	}

	udpinfo = context->struct_protol4;
	size = 8;

	// Source Port
	*((uint16_t *)&udp_header[0]) = htons(udpinfo->srcport);
	// Destination Port
	*((uint16_t *)&udp_header[2]) = htons(udpinfo->dstport);
	// Length
	*((uint16_t *)&udp_header[4]) = htons(udpinfo->len);
	// Checksum
	*((uint16_t *)&udp_header[6]) = htons(udpinfo->checksum);

	nsu_push_header(context, udp_header, size);

	return 0;
}


