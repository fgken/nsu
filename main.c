#include <stdio.h>

#include "nsu.h"
#include "debuglib.h"

int main(int argc, char *argv[])
{
	struct nsu_context *context;
	char buf[100];
	int size;
	int i;

	puts("=== Network Stack in Userspace ===");

	nsu_create(&context);

	for(i=0; i<50; i++) buf[i] = i;
	size = 50;

	nsu_send(context, buf, size);

	nsu_destroy(&context);

	puts("=== Finished ===");

	return 0;
}	
