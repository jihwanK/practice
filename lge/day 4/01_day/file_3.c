#include <stdio.h>
// ./a.out  filename 
int main( int argc, char **argv )
{
	FILE *fp;
	//signed char ch;
	int ch;
	int count=0;
	fp = fopen( argv[1] , "r");

	while( (ch = fgetc( fp )) != EOF )
		count++;

	printf("count=%d\n", count );

	fclose(fp);
	return 0;
}

