#include <stdio.h>

int main(void) {

	int res, len, i, j;
	
	printf("Enter triangle's length':");

	/* read the number & make sure it is valid */
	res = scanf("%d", &len);
	if ((res != 1) || (len < 0))
	{
		printf("Invalid input");
		return 0;
	}
			
	/* print the triangle */
	for (i = 1; i <= len; i++)
	{
		/* print each line */
		for (j = 1; j <= i; j++)
			printf("*");
		
		printf("\n");
	}
		
	return 0;
}

