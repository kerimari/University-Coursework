#include <stdio.h> 
#include <fcntl.h> 
#define PERMS 0666 /* ReadWrite for owner, group, others */

int main() 
{ 
	char arr[4]; 
	int count = 0, r; 
	int f_read, f_write;
	
	/* Open this c file READ only */
	if ((f_read = open("chapter11_1.o", O_RDONLY, 0)) == -1) {
		printf("Error opening chapter11_1.o.\n");
		return 0;
	}
	/* Create or reset the file for WRITE */
	if ((f_write = creat("new.raw", PERMS)) == -1)  {
		printf("Error opening new.raw.\n");
		return 0;
	}

	/* read 4 bytes from the file  */
	while ((r = read(f_read, arr, 4)) == 4) 
	{
		/* to write this byte of the input file in the output file */
		count += write(f_write, arr, 4); 
		
		/* move 0x10 - 4 = 12 bytes further */ 
		if (lseek (f_read, 12, SEEK_CUR) == -1)
			printf("Error in lseek\n");
		
	} 
	/* print the number of bytes copied and the last read's return value */
	printf("%d %d", count, r);
	
	/* close files */
	close(f_write); 
	close(f_read); 
	
	return 0; 
} 



