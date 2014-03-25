#include <stdio.h>
#include <string.h>

#include "nsu.h"
#include "debuglib.h"

int main(int argc, char *argv[])
{
	struct nsu_context *context;
	struct nsu_ethernet eth;
	struct nsu_ipv4 ip;
	struct nsu_udp udp;

	char buf[100];
	int size;
	int i;

	puts("=== Network Stack in Userspace ===");

	nsu_create(&context);

	for(i=0; i<50; i++) buf[i] = 0xff - i;
	size = 50;

	// --- set protocol ---
	// ethernet
	for(i=0; i<6; i++) eth.dstmac[i] = i, eth.srcmac[i] = i+0xf0;
	eth.type = 0x0800;
	// ip
	memset(&ip, 0x00, sizeof(ip));
	ip.ver = 4;
	ip.ihl = 5;
	for(i=0; i<4; i++) ip.dstip[i] = i+100, ip.srcip[i] = i+200;
	// udp
	memset(&udp, 0x00, sizeof(udp));
	udp.srcport = 0x5555;
	udp.dstport = 0x2222;

	nsu_set_protocol(context, NSU_L2_ETHERNET, &eth, sizeof(eth));
	nsu_set_protocol(context, NSU_L3_IPV4, &ip, sizeof(ip));
	nsu_set_protocol(context, NSU_L4_UDP, &udp, sizeof(udp));

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
