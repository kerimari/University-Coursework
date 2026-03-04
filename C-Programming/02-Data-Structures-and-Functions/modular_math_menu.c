#include <stdio.h>

int maximum(int num1, int num2, int num3)
{
	int max;
	
	/* assign the max of num1 & num2 to min */
	if (num1 > num2) 
			max = num1;
	else max = num2;

	/* assign the minimum of max & num3 */					
	if (max < num3) 
			max = num3;
			
	return max;		
}
			
void print_ordered(int num1, int num2, int num3)
{
 	if ((num1 <= num2) && (num1 <= num3))  {
			/* num1 is smaller than other 2 numbers */
			printf("%d ", num1);
			if (num2 <= num3) printf("%d %d", num2, num3);
			else printf("%d %d\n", num3, num2);
		}
		
	else if ((num2 <= num1) && (num2 <= num3))  {
			/* num2 is smaller than other 2 numbers */
			printf("%d ", num2);
			if (num1 <= num3) printf("%d %d", num1, num3);
			else printf("%d %d\n", num3, num1);
		}
	else {                                     
			/* num3 is smaller than other 2 numbers */
			printf("%d ", num3);
			if (num1 <= num2) printf("%d %d", num1, num2);
			else printf("%d %d\n", num2, num1);
		}	
}
	
float average(int num1, int num2, int num3)
{
	float sum = num1 + num2 + num3;
		return (sum / 3);
}
		
int main() {
	int n1 = 0, n2 = 0, n3 =0;
	int result;
	char c;

	printf("Enter 3 numbers:");
	result = scanf("%d %d %d", &n1, &n2, &n3);
	
	if (result != 3){
		printf ("Error in scanf");
		return 0;
	}
	
	printf("Enter selection (1 for maximum, 2 for print_ordered, 3 for average, 4 to end):");	
	
	do {
		/* read a character */
		result = scanf("%c", &c);	
		if (result == 1) {
			/* find out which function to call */
			switch (c){
				case ('1'):
					printf("maximum is %d\n", maximum(n1, n2, n3));
					break;
				case ('2'):
					print_ordered(n1, n2, n3);
					break;
				case ('3'):
					printf("average is %f\n", average(n1, n2, n3));
					break;
				default:
					if ((c != '\n') && (c != '4'))
						printf("Invalid selection\n");
			}		
		}
	} while((result == 1) && (c != '4'));  /* repeat until the input is enter */
	
	return 0;
}






