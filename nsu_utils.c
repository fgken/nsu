#include "stdio.h"
#include "string.h"

#include "nsu_utils.h"
#include "nsu.h"
#include "debuglib.h"

// **************************************************************************
// --- Common ---
// **************************************************************************
int nsu_push_header(struct nsu_context *context, const void *data, int size)
{
	printd("push_header\n");

	if(context == NULL || context->bufpos - size < 0){
		return -1;
	}

	context->bufpos -= size;
	memcpy(context->buf + context->bufpos, data, size);
	
	return 0;
}

int nsu_pop_header(struct nsu_context *context, void *data, int size)
{
	printd("pop_header\n");
}

int nsu_get_layer(int proto_id)
{
	switch(proto_id){
		case NSU_L2_ETHERNET:
			return NSU_L2;

		case NSU_L3_IPV4:
		case NSU_L3_IPV6:
			return NSU_L3;

		case NSU_L4_UDP:
		case NSU_L4_TCP:
			return NSU_L4;

		default:
			break;
	}

	return NSU_LNONE;
}

int nsu_get_proto_struct(struct nsu_context *context, int proto_layer, int **proto_id, void ***struct_proto)
{
	if(struct_proto == NULL || proto_id == NULL){
		return -1;
	}

	switch(proto_layer){
		case NSU_L2:
			*proto_id = &context->proto_l2;
			*struct_proto = &context->struct_protol2;
			break;
		case NSU_L3:
			*proto_id = &context->proto_l3;
			*struct_proto = &context->struct_protol3;
			break;
		case NSU_L4:
			*proto_id = &context->proto_l4;
			*struct_proto = &context->struct_protol4;
			break;
		default:
			*proto_id = NULL;
			*struct_proto = NULL;
			return -1;		// fixme
	}

	return 0;
}

// **************************************************************************
// --- Helper ---
// **************************************************************************
int nsu_init_ethernet_header(struct nsu_ethernet *header, const char *dstmacstr, const char *srcmacstr)
{
	int i;
	char *endptr;
	const char *p;
	char dstmac[6];
	char srcmac[6];

	if(header == NULL || dstmacstr == NULL || srcmacstr == NULL){
		return -1;
	}

	for(i=0, p=dstmacstr; i<6; i++){
		dstmac[i] = strtol(p, &endptr, 16);
		if(*endptr == ':'){
			p = endptr+1;
		}
		else if(i == 5 && *endptr == '\0'){
			memcpy(header->dstmac, dstmac, sizeof(header->dstmac));
			break;
		}
		else{
			return -1;
		}
	}

	for(i=0, p=srcmacstr; i<6; i++){
		srcmac[i] = strtol(p, &endptr, 16);
		if(*endptr == ':'){
			p = endptr+1;
		}
		else if(i == 5 && *endptr == '\0'){
			memcpy(header->srcmac, srcmac, sizeof(header->srcmac));
			break
		}
		else{
			return -1;
		}
	}

	header->type = NSU_ETHERNET_TYPE_IPV4;

	return 0;
}
