#include <stdio.h>
struct ethhdr {
	unsigned char   h_dest[6];   
	unsigned char   h_source[6]; 
	unsigned short  h_proto;        
}  __attribute__((packed));

int main()
{
	struct ethhdr ethhdr; 
	printf("sizeof(ethhdr)=%lu\n", sizeof(ethhdr) );
	return 0;
}
