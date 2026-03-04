#include <stdio.h> 
#include <stdlib.h>
#include <fcntl.h> 
#include <signal.h>

void my_handler(int sig) {

	if (sig == SIGINT)
		printf("! not found\n");
		
	if (sig == SIGABRT) {
		printf("File not found\n");	
		abort();	
	}
		
}

int main(void) 
{ 
	char arr[4]; 
	int counters[0xFF];   /* create an array to store the number of repetitions for each byte value */
	int i, j, r, max, max_i, f_read; 
	
	signal(SIGINT, my_handler);
	signal(SIGABRT, my_handler);

	
	/* Open the file specified as the first parameter READ only */
	f_read = open("chapter11_1.c", O_RDONLY, 0); 
	if (f_read == -1) 
		raise(SIGABRT);


	/* clear the counters */
	for (i = 0; i < 0xFF; i++)
		counters[i] = 0;
		
	/* read 1 byte from the file  */
	while ((r = read(f_read, arr, 1)) == 1) {
		r = arr[0];
		counters[r]++;  /* increase the counter of this byte in the array */		
	} 
	
	/* print the biggest 10 counters */	
	for (j = 0; j < 10; j++) {
		/* find out the maximum */		
		max = counters[0];
		max_i = 0;
		for(i = 1; i < 0xFF; i++) 
			if (max < counters[i]) 
			{
				max = counters[i];
				max_i = i;
			}
		printf("%c = %d\n", max_i, max);   /* print the most repeated byte and its number of occurancies */
		counters[max_i] = 0;	           /* reset this to find the next max */	
	}
	
	/* close files */
	close(f_read); 
	
	if(counters[i] == 0)
		raise(SIGINT);	
		
		
	return 0; 
} 



