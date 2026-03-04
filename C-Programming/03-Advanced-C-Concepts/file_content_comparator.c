#include <stdio.h> 

int main() 
{ 
	char line1[200], line2[200]; 
	FILE *fp1, *fp2;
	int diff = 1;

		
	/* Open the files READ only */
	if ((fp1 = fopen("chapter12_1.c", "r")) == NULL) {
		printf("Error opening chapter12_1.c\n");
		return 0;
	}
	if ((fp2 = fopen("chapter12_2.c", "r")) == NULL)  {
		printf("Error opening chapter12_2.c\n");
		return 0;
	}

	/* read line by line  */
	while ((fgets(line1, 200, fp1) != NULL) && (fgets(line2, 200, fp2) != NULL))  {
		/* compare lines */
		if (strcmp(line1, line2) != 0) {

			diff = 0;          /* indicates the lines are different */
			break;
		}		
	} 	
	
	if (diff)
		printf("Files are identical.");
	else
		printf("Files are different at line:\n%s\n%s", line1, line2);
	
	/* close files */
	fclose(fp1); 
	fclose(fp2); 
	
	return 0; 
} 




