#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <net/if.h>
#include <net/ethernet.h>
#include <netpacket/packet.h>

#include "nsu.h"
#include "debuglib.h"

static int raw_sendto(char *buf, int size, char *ifname)
{
	int rawsock;
	struct ifreq ifr;
	int ifindex;
	struct sockaddr_ll sll;

	printd("raw_sendto\n");
	printd("raw send data:\n");
	memdump(stdout, buf, size);

	if(buf == NULL || size < 0 || ifname == NULL){
		return -1;
	}

	// get raw socket
	rawsock = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
	if(rawsock < 0){
		printd("Error: socket() failure\n");
		return -1;
	}

	// get network interface
	memset(&ifr, 0x00, sizeof(ifr));
	strcpy(ifr.ifr_name, ifname);
	if(ioctl(rawsock, SIOCGIFINDEX, &ifr) < 0){
		printd("Error: ioctl() SIOCGIFINDEX failure\n");
		return -1;
	}
	ifindex = ifr.ifr_ifindex;

	// send raw packet
	memset(&sll, 0x00, sizeof(sll));
	sll.sll_family = AF_PACKET;
	sll.sll_halen = ETH_ALEN;
	sll.sll_ifindex = ifindex;
	
	return sendto(rawsock, buf, size, 0, (struct sockaddr *)&sll, sizeof(sll));
}

int nsu_ethernet_send(struct nsu_context *context)
{
	char ethernet_header[14];
	int size;
	int i;

	printd("nsu_ether_send\n");

	size = 14;
	for(i=0; i<size; i++) ethernet_header[i] = 0x00;

	nsu_push_header(context, ethernet_header, size);

	raw_sendto(&context->buf[context->bufpos], NSU_BUFFER_SIZE-context->bufpos, context->ifname);

	return 0;
}

int nus_ethernet_recv(struct nsu_context *context)
{
	printd("nsu_ether_recv\n");
	return 0;
}
