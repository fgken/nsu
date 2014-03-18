#include "stdio.h"
#include "stdio.h"
#include "nsu.h"
#include "debuglib.h"

int nsu_ip_send(struct nsu_context *context)
{
	char ip_header[20];
	int size;
	int i;

	printd("nsu_ether_send\n");

	size = 20;
	for(i=0; 2*i+1 < size; i++)
	{
		ip_header[2*i]   = 'I';
		ip_header[2*i+1] = 'P';
	}

	nsu_push_header(context, ip_header, size);

	nsu_ethernet_send(context);

	return 0;
}

int nus_ip_recv(struct nsu_context *context, void *buf, int size)
{
	printd("nsu_ether_recv\n");
	return 0;
}
