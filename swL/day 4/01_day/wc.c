#include <stdio.h>
//   123
int get_width(int count) 
{
	int i;
	for(i=0; count; i++ )
		count /= 10;
	return i;
}

int main(int argc, char **argv)
{
	FILE *fp;
	int ch;
	int flag=0;
	int line_count=0;
	int word_count=0;
	int char_count=0;
	int width;
	fp = fopen(argv[1], "r");
	while( (ch = fgetc(fp)) != EOF)
	{
		if( ch == '\n' )
			line_count++;
		char_count++;

		if( ch==' ' || ch=='\n' || ch=='\t' )
		{
			flag=0;
		}
		else
		{
			if( flag == 0 ) 
			{
				word_count++;
				flag = 1;
			}
		}
	}
	width = get_width(char_count) ;
	//  14  27 167 wc.c
	printf("%*d %*d %*d %s\n", width, line_count,
			                   width, word_count,
							   width, char_count, argv[1] ); 
	fclose(fp);
	return 0;
}






