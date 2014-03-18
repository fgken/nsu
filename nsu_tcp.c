#include "stdio.h"

#include "nsu.h"
#include "debuglib.h"

int nsu_tcp_send(struct nsu_context *context)
{
	char tcp_header[20];
	int size;
	int i;

	printd("nsu_ether_send\n");

	size = 20;
	for(i=0; 3*i+2 < size; i++)
	{
		tcp_header[3*i]   = 'T';
		tcp_header[3*i+1] = 'C';
		tcp_header[3*i+2] = 'P';
	}

	nsu_push_header(context, tcp_header, size);

	nsu_ip_send(context);
	
	return 0;
}

int nus_tcp_recv(struct nsu_context *context, void *buf, int size)
{
	printd("nsu_ether_recv\n");
	return 0;
}
