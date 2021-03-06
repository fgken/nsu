#ifndef __NSUUTILS_H__
#define __NSUUTILS_H__

#include "nsu.h"

int nsu_push_header(struct nsu_context *context, const void *data, int size);
int nsu_pop_header(struct nsu_context *context, void *data, int size);


int nsu_init_ethernet_header(struct nsu_ethernet *header, const char *dstmacstr, const char *srcmacstr);
#endif /* __NSUUTILS_H__ */
