#include <stdio.h>
typedef unsigned short __sum16;
static unsigned short from32to16(unsigned int x)
{
	/* add up 16-bit and 16-bit for 16+c bit */
	x = (x & 0xffff) + (x >> 16);
	/* add up carry.. */
	x = (x & 0xffff) + (x >> 16);
	return x;
}
static unsigned int do_csum(const unsigned char *buff, int len)
{
	int odd;
	unsigned int result = 0;

	if (len <= 0)
		goto out;
	odd = 1 & (unsigned long) buff;
	if (odd) {
		result += (*buff << 8);
		len--;
		buff++;
	}
	if (len >= 2) {
		if (2 & (unsigned long) buff) {
			result += *(unsigned short *) buff;
			len -= 2;
			buff += 2;
		}
		if (len >= 4) {
			const unsigned char *end = buff + ((unsigned)len & ~3);
			unsigned int carry = 0;
			do {
				unsigned int w = *(unsigned int *) buff;
				buff += 4;
				result += carry;
				result += w;
				carry = (w > result);
			} while (buff < end);
			result += carry;
			result = (result & 0xffff) + (result >> 16);
		}
		if (len & 2) {
			result += *(unsigned short *) buff;
			buff += 2;
		}
	}
	if (len & 1)
		result += *buff;
	result = from32to16(result);
	if (odd)
		result = ((result >> 8) & 0xff) | ((result & 0xff) << 8);
out:
	return result;
}

__sum16 ip_csum(const void *iph, unsigned int ihl)
{
	return (__sum16)~do_csum(iph, ihl*4);
}

int main()
{
	unsigned short ip[] = {0x4500, 0x0028, 0x32bf, 0x4000, 0x8006, 
		                   0x0000, 0xc0a8, 0x0003, 0x7dd1, 0xfeb3 };
	__sum16 check;
	
    check = ip_csum( ip, 5);
	printf("check=%x\n", check);
	ip[5] = check;
	printf("송신완료...\n");

	ip[4]++;
    check = ip_csum( ip, 5);
	printf("check=%x\n", check);
	if( check == 0 )
		printf("올바른 패킷입니다.\n");
	else
		printf("잘못된 패킷입니다.\n");

	return 0;
}



















