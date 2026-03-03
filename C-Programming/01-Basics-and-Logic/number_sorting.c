#include <stdio.h>

int main() {
	int num1 = 0, num2 = 0, num3 = 0;
	
	int result;

	printf("Enter 3 numbers:");
	result = scanf("%d %d %d", &num1, &num2, &num3);
	
	if (result != 3)
		printf ("Error in scanf");
		
	else if ( (num1 == num2) && (num1 == num3) )
		printf("All numbers are equal");
				
	else if ((num1 <= num2) && (num1 <= num3))  {
			/* num1 is smaller than other 2 numbers */
			printf("%d ", num1);
			if (num2 <= num3) printf("%d %d", num2, num3);
			else printf("%d %d", num3, num2);
		}
		
	else if ((num2 <= num1) && (num2 <= num3))  {
			/* num2 is smaller than other 2 numbers */
			printf("%d ", num2);
			if (num1 <= num3) printf("%d %d", num1, num3);
			else printf("%d %d", num3, num1);
		}
	else {                                     
			/* num3 is smaller than other 2 numbers */
			printf("%d ", num3);
			if (num1 <= num2) printf("%d %d", num1, num2);
			else printf("%d %d", num2, num1);
		}
	
	return 0;
}


