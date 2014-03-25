#include <stdio.h>

#include "debuglib.h"
#include "nsu.h"

void memdump(FILE *f, const unsigned char *buf, int size)
{
    int len, i, j, c;

    for(i=0;i<size;i+=16) {
        len = size - i;
        if (len > 16)
            len = 16;
        fprintf(f, "%08x ", i);
        for(j=0;j<16;j++) {
            if (j < len)
                fprintf(f, " %02x", buf[i+j]);
            else
                fprintf(f, "   ");
        }
        fprintf(f, " ");
        for(j=0;j<len;j++) {
            c = buf[i+j];
            if (c < ' ' || c > '~')
                c = '.';
            fprintf(f, "%c", c);
        }
        fprintf(f, "\n");
    }
}

void dump_nsu(struct nsu_context *context)
{
	printf( "dump struct nsu_context : 0x%x\n"
			"  proto_l2=%d\n"
			"  proto_l3=%d\n"
			"  proto_l4=%d\n"
			"  struct_protol2=0x%x\n"
			"  struct_protol3=0x%x\n"
			"  struct_protol4=0x%x\n"
			"  buf=0x%x\n"
			"  bufpos=%d\n"
			"  ifname=%s\n"
			,context
			,context->proto_l2
			,context->proto_l3
			,context->proto_l4
			,context->struct_protol2
			,context->struct_protol3
			,context->struct_protol4
			,context->buf
			,context->bufpos
			,context->ifname
		  );
}
