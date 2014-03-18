#ifndef __NUS_H__
#define __NUS_H__

// === etc ===
#define NSU_BUFFER_SIZE			1600

// === Network Protocol ===
// --- Layer 2 ---
#define NSU_L2_ETHERNET		1
// --- Layer 3 ---
#define NSU_L3_IPV4			1
#define NSU_L3_IPV6			2
// --- Layer 4 ---
#define NSU_L4_UDP			1
#define NSU_L4_TCP			2


// === NSU Structures ===
struct nsu_context {
	int  proto_l2;
	int  proto_l3;
	int  proto_l4;
	char *buf;
	int  bufpos;
	char ifname[16];
	void *proto_specified_param;
};

// === NSU APIs ===
int nsu_create(struct nsu_context **context);
void nsu_destroy(struct nsu_context **context);
int nsu_send(struct nsu_context *context, void *buf, int size);

#endif /* __NUS_H__ */
