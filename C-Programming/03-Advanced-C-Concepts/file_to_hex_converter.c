#include <stdio.h> 

int main() 
{ 
	char c; 
	FILE *fp1, *fp3;
		
	/* Open the files */
	if ((fp1 = fopen("chapter12_1.c", "r")) == NULL) {
		printf("Error opening chapter12_1.c\n");
		return 0;
	}

	if ((fp3 = fopen("ascii.txt", "w")) == NULL)  {
		printf("Error opening ascii.txt\n");
		return 0;
	}
	
	/* read file1 */	
	while (fscanf(fp1, "%c", &c) != EOF)  {
		/* write this byte as hex */
		fprintf(fp3, "%x", c);
		printf("%x",c);
	} 
	
	/* close files */
	fclose(fp1); 
	fclose(fp3);
	
	return 0; 
} 




