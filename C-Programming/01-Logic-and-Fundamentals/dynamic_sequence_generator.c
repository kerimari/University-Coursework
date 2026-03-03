#include <stdio.h>

int main(void) {
	
	int num, res, i;
	
	do {
		printf("Enter a number(or something else to end:");
		res = scanf("%d", &num);
		
		if (res == 1) 
			{
			/* use different loop for negative numbers */
			if (num >= 0)
				for (i = 3; i <= num; i+=3)
					printf("%d ", i);
			else
				for (i = -3; i >= num; i-=3)
					printf("%d ", i);				
			}
			printf("\n");

	} while(res == 1);        /* repeat until the input is not digits */
		
	printf ("End of the program.");

	return 0;
}





