#include <stdio.h>


int main(void) {

	int n,i, max1, max2, num;
	
	printf("Enter number:");
	if(scanf("%d", &n) == 1)
	{
		printf ("Enter %d numbers:\n", n);
		/* read the first number and initialize max vaues */
		scanf("%d", &num);
		max1 = max2 = num;
		
		for (i =2; i <= n; i++)
		{
			scanf("%d", &num);
			
			if (num > max1)
			{
				max2 = max1;
	  			max1 = num;
			}
			else if (num > max2) 
				max2 = num;		
		}
	printf ("Max values are : %d %d\n", max1, max2);
	}

	return 0;
}


