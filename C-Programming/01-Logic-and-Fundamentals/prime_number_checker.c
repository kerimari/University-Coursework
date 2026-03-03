#include <stdio.h>
#define DEBUG

int main(void) {
	
	int num, res, reminder, i;
	
	do {
		printf("Enter a number(or something else to end):");
		res = scanf("%d", &num);
		
		if (res == 1) 
			{
			i = 2; reminder = 1;    /* initialize */
			
			/* skip numbers smaller than 2 */
			if (num <= 1)
				reminder = 0;
			
			/* if it is a prime number rem should be non zero when divided by any number */
			while ((reminder != 0) && (i < num)) {
				reminder = num % i;
				#ifdef DEBUG
				printf("reminder=%d\n", reminder);
				#endif
				i++;				
			}
			
			/* verify if there has been any non zero reminder */
			if (reminder != 0)
				printf("%d is a prime number.\n", num);
			else
				printf("NOT a prime number.\n", num);
			
			}

	} while(res == 1);        /* repeat until the input is not digits */
		
	printf ("End of the program.");

	return 0;
}





