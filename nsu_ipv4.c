#include <string.h>

#include "nsu.h"
#include "debuglib.h"

int nsu_ipv4_push_header(struct nsu_context *context)
{
	struct nsu_ipv4 *ipinfo;
	char ipv4_header[20];
	int size;
	int i;

	printd("nsu_ipv4_push_header\n");

	if(context == NULL || context->struct_protol3 == NULL){
		return -1;
	}

	ipinfo = context->struct_protol3;
	size = 20;

	// Version, IP header length
	ipv4_header[0] = ((ipinfo->ver << 4)&0xf0) | (ipinfo->ihl&0x0f);
	// Type of Service
	ipv4_header[1] = ipinfo->tos;
	// Total Length
	*((uint16_t *)&ipv4_header[2]) = htons(ipinfo->totallen);
	// Identification
	*((uint16_t *)&ipv4_header[4]) = htons(ipinfo->id);
	// Fragment offset
	*((uint16_t *)&ipv4_header[6]) = htons(ipinfo->fragment);
	// Flags
	ipv4_header[6] = ipv4_header[6] | (ipinfo->flag << 5)&0xE0;
	// Time to Live
	ipv4_header[8] = ipinfo->ttl;
	// Protocol
	ipv4_header[9] = ipinfo->proto;
	// Header Checksum
	*((uint16_t *)&ipv4_header[10]) = htons(ipinfo->checksum);
	// Source IP Address
	memcpy(&ipv4_header[12], ipinfo->srcip, 4);
	// Destination IP Address
	memcpy(&ipv4_header[16], ipinfo->dstip, 4);
	// Options and Padding (Optional)

	nsu_push_header(context, ipv4_header, size);

	return 0;
}

int nsu_ipv4_recv(struct nsu_context *context, void *buf, int size)
{
	printd("nsu_ipv4_recv\n");
	return 0;
}
