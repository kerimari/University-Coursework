#include <stdio.h>
#define DEBUG

int main(void) {

	int len, i, res, space, star;

	printf("Enter diamond's length:");

	/* read the maximum length of rows & make sure it is valid */
	res = scanf("%d", &len);
	if ((res != 1) || (len < 0) || ((len % 2) == 0))
	{
		printf("Invalid input");
		return 0;
	}
		
	/* first star has to be in the middle */
	#ifdef DEBUG
	printf("spaces=%d\n", len/2);
	#endif
	
	/* print the first half of the diamond */
	for (space = len/2, star = 1; star <= len; space--, star += 2)
	{
		/* print each line */		
		for (i = 0; i < space; i++) 
			#ifdef DEBUG
			printf(" ");
			#else
			printf(" ");
			#endif
			
		for (i = 0; i < star; i++)
			printf("*");
			
		printf("\n");
	}

	/* print the second half => same pattern printed in reverse order */
	for (space = 1, star = len-2; star >= 1; space++, star -= 2)
	{
		/* print each line */
		for (i = 0; i < space; i++)
			#ifdef DEBUG
			printf(" ");
			#else
			printf(" ");
			#endif
			
		for (i = 0; i < star; i++)
			printf("*");
			
		printf("\n");
	}

	return 0;
}

