#ifndef _MY_PROTOCOL_H_
#define _MY_PROTOCOL_H_ 

typedef struct {
	int type;
	int length;
	char *data;
} MY_PROTOCOL;

void create_packet(MY_PROTOCOL*, int, int);

#endif
