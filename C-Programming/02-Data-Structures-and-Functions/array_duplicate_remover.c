#include <stdio.h> 

#define LEN 10   /* use this constant for length of the array */

int main(void) 
{ 
	int  X[LEN], Z[LEN];     /* declare arrays  */
	int i, j, m, k = 0, z;      /* declare index and length */
	int found = 0;
	
	/* read m and n */
	printf("Enter dimension of X array: ");
	if (scanf("%d", &m) != 1) {
		printf("Error in scanf\n");
		return 0;
	}	
	
	if (m > LEN) {
		printf("Dimension is off limits\n");
		return 0;
	}
	
	/* read the arrays */
	for(i = 0; i < m; i++) 
		{ 
		printf("X[%d] = ", i); 
		scanf("%d", &X[i]);
		} 	
		
	/* find common items */	
	for (i = 0; i < m; i++)		 
		/* for every item in X, search the successive items */
		for (j = i+1; j < m; j++) 
			/* check if it is common */
			if (X[i] == X[j])
			{
				/* before updating Z, make sure this is the first occurrance of repeated element */
				z = 0;
				do {
					found = (Z[z] == X[i]);
					z++;
				} while ((!found) && (z < k));
				
				/* if the common item is not present in Z, add this to Z */
				if (!found)	{
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



