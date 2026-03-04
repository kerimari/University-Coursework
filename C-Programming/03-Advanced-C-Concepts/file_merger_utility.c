#include <stdio.h> 

int main() 
{ 
	char line[200]; 
	FILE *fp1, *fp2, *fp3;
		
	/* Open the files */
	if ((fp1 = fopen("chapter12_1.c", "r")) == NULL) {
		printf("Error opening chapter12_1.c\n");
		return 0;
	}
	if ((fp2 = fopen("chapter12_2.c", "r")) == NULL)  {
		printf("Error opening chapter12_2.c\n");
		return 0;
	}
	if ((fp3 = fopen("output.txt", "w")) == NULL)  {
		printf("Error opening output.txt\n");
		return 0;
	}
	
	/* copy file2  */
	while (fgets(line, 200, fp2) != NULL)  {
		fputs(line, fp3); 
	} 
	/* copy file1 */	
	while (fgets(line, 200, fp1) != NULL)  {
		fputs(line, fp3); 
	} 	
	
	/* close files */
	fclose(fp1); 
	fclose(fp2); 
	fclose(fp3);
	
	return 0; 
} 




