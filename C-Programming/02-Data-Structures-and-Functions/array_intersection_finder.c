#include <stdio.h> 

#define LEN 10   /* use this constant for length of the array */

int main(void) 
{ 
	int  X[LEN], Y[LEN], Z[LEN];  /* declare arrays  */
	int i, j, m, n, k = 0;         /* declare index and length */
	int found;
	
	/* read m and n */
	printf("Enter dimensions of X and Y arrays: ");
	if (scanf("%d %d", &m, &n) != 2) {
		printf("Error in scanf\n");
		return 0;
	}	
	
	if ((m > LEN) || (n > LEN))	{
		printf("Dimensions are off limits\n");
		return 0;
	}
	
	/* read the arrays */
	for(i = 0; i < m; i++) 	{ 
		printf("X[%d] = ", i); 
		scanf("%d", &X[i]);
		} 
		
	for(i = 0; i < n; i++)	{ 
		printf("Y[%d] = ", i); 
		scanf("%d", &Y[i]);
		} 	
		
	/* find common items */	
	for (i = 0; i < m; i++)	{
		j = 0; found = 0;  /* initialize at each iteration */
		
		/* loop through each Y item to see if  X[i] exist in Y */
		do {
			found = (X[i] == Y[j]);
			j++;
		} while ((!found) && (j < n));
		
		/* store the X[i] to Z if found in Y */
		if (found)	{
			Z[k] = X[i];
			k++;
		}
	}
	
	/* print Z */
	printf("Common elements are:\n");
	for(i = 0; i < k; i++) 
		printf("Z[%d] = %d\n", i, Z[i]); 

	return 0; 
}



