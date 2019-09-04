#include <stdio.h>
#include <unistd.h>
// # ./a.out -al -iR

#define  a_OPT   (1<<0)
#define  i_OPT   (1<<1)
#define  l_OPT   (1<<2)
#define  R_OPT   (1<<3)
int main(int argc, char **argv)
{
	int ch;
	int flag=0;
	while( (ch = getopt( argc, argv, "ailR")) != -1)
	{
		if( ch == 'a' ) flag |= a_OPT;
		if( ch == 'i' ) flag |= i_OPT;
		if( ch == 'l' ) flag |= l_OPT;
		if( ch == 'R' ) flag |= R_OPT;
	}
	if( flag & a_OPT )	
		printf("a Option\n");

	if( flag & i_OPT )	
		printf("i Option\n");

	if( flag & l_OPT )	
		printf("l Option\n");

	if( flag & R_OPT )	
		printf("R Option\n");
	return 0;
}
