#include <string.h>

#include "nsu.h"
#include "debuglib.h"

#define ETHERNET_HEADER_SIZE	14

int nsu_ethernet_push_header(struct nsu_context *context)
{
	struct nsu_ethernet *etherinfo;
	char ethernet_header[ETHERNET_HEADER_SIZE];
	int size;
	int i;

	printd("nsu_ethernet_push_header\n");

	if(context == NULL || context->struct_protol2 == NULL){
		return -1;
	}

	etherinfo = context->struct_protol2;
	size = ETHERNET_HEADER_SIZE;

	// destination mac address
	memcpy(&ethernet_header[0], etherinfo->dstmac, 6);
	// source mac address
	memcpy(&ethernet_header[6], etherinfo->srcmac, 6);
	// type
	*((uint16_t *)(&ethernet_header[12])) = htons(etherinfo->type);

	nsu_push_header(context, ethernet_header, size);

	return 0;
}

int nsu_ethernet_recv(struct nsu_context *context)
{
	printd("nsu_ether_recv\n");
	return 0;
}
