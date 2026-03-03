#include <stdio.h>
#define DEBUG

int main(void) {

	int digits= 0, uppercase = 0, lowercase = 0, res;
	char c;

	printf("Input your text:");

	do {
		/* read a character */
		res = scanf("%c", &c);

		if (res == 1)
		{
			/* find out which counter to increase */

			if ((c >= 48) && (c <= 57)) 		/* 0 - 9 */
				digits++;				
						
			else if ((c >= 65) && (c <= 90)) 	/* A - Z */
				uppercase++;
				
			else if ((c >= 97) && (c <= 122)) 	/* a - z */
				lowercase++;
			
		}

	} while((res == 1) && (c != '\n'));  /* repeat until the input is enter */

	printf("%d lowercase letters\n%d uppercase letters and\n%d digits\n", lowercase, uppercase, digits);

	return 0;
}

