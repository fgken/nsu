#ifndef __NUS_H__
#define __NUS_H__

#include <stdint.h>

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
	uint8_t  dstmac[6];
	uint8_t  srcmac[6];
	uint16_t type;
};

// L3 Structures
struct nsu_ip {
	uint8_t  ver;		// Version [4bit]
	uint8_t  ihl;		// IP Header Length [4bit]
	uint8_t  tos;		// Type of Service
	uint16_t totallen;	// Totaol Length
	uint16_t id;		// Identification
	uint8_t  flag;		// Flags [3bit]
	uint16_t fragment;	// Fragment Offset [13bit]
	uint8_t  ttl;		// Time To Live
	uint8_t  proto;		// Protocol
	uint16_t checksum;	// Header Checksum
	uint32_t srcip;
	uint32_t dstip;
	void     *options;
};


// L4 Structures
struct nsu_udp {
	uint16_t srcport;
	uint16_t dstport;
	uint16_t len;
	uint16_t checksum;
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
