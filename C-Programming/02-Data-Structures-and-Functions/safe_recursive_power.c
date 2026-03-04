#include <stdio.h>
#include <limits.h>

int power(int x, int n){
	int f;
	if (n <=0) 
		return 1;
		
	f = power(x, n-1);
	
	if (x > (INT_MAX / f))
			printf("overflow occured\n");	
			
	return x * f;
	
}

int main(void) {

	int a, b;
	
	printf ("Enter 2 numbers:");
	
	if (scanf("%d %d", &a, &b) != 2)
		printf("error in scanf");
	else 
	    printf("power(%d, %d) = %d\n", a, b, power(a,b));	
   
	return 0;
}




