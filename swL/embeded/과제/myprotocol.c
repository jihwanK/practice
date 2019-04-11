#include <stdlib.h>
#include "myprotocol.h"

void create_packet(MY_PROTOCOL *prot, int type, int length)
{
	prot->type = type;
	prot->length = length;
	prot->data = malloc(sizeof(char) * length);
}
