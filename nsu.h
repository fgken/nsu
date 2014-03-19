#ifndef __NUS_H__
#define __NUS_H__

// === etc ===
#define NSU_BUFFER_SIZE			1600

// === Network Layer ===a
#define NSU_LNONE			0
#define NSU_L2				2
#define NSU_L3				3
#define NSU_L4				4

// === Network Protocol ===
// --- Layer 2 ---
#define NSU_L2_NONE			0
#define NSU_L2_ETHERNET		1
// --- Layer 3 ---
#define NSU_L3_NONE			0
#define NSU_L3_IPV4			51
#define NSU_L3_IPV6			52
// --- Layer 4 ---
#define NSU_L4_NONE			0
#define NSU_L4_UDP			101
#define NSU_L4_TCP			102


// === NSU Structures ===
struct nsu_context {
	int  proto_l2;
	int  proto_l3;
	int  proto_l4;
	void *struct_protol2;
	void *struct_protol3;
	void *struct_protol4;
	char *buf;
	int  bufpos;
	char ifname[16];
};

// L2 Structures
struct nsu_ethernet {
	char dstmac[6];
	char srcmac[6];
	char type[2];
};

// L3 Structures
struct nus_ip {
	char dummy;
};


// L4 Structures
struct nus_udp {
	char dummy;
};

struct nsu_tcp {
	char dummy;
};

// === NSU APIs ===
int nsu_create(struct nsu_context **context);
void nsu_destroy(struct nsu_context **context);
int nsu_send(struct nsu_context *context, void *buf, int size);

int nsu_set_protocol(struct nsu_context *context, int proto_id, void *struct_proto, int size);

#endif /* __NUS_H__ */
