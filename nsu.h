#ifndef __NUS_H__
#define __NUS_H__

struct nsu_context {
	char ipaddr[4];
	char macaddr[4];
	char etcetc[8];
	char dummy[8];
	void *proto_specified_param;
};

int nsu_create(struct nsu_context **context);
void nsu_destroy(struct nsu_context **context);
int nsu_send(struct nsu_context *context, void *buf, int size);

#endif /* __NUS_H__ */
