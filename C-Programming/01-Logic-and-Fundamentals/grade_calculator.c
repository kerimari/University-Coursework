#include <stdio.h>

int main(void) {
	
	int marks;

	printf("Enter your marks:(0-100)");
	int result = scanf("%d", &marks);
	
	/* first verify if marks have been updated properly */
	if (result != 1)
		printf ("Error in scanf.");
		
	/* check if marks is in the expected range */
	else if ((marks > 100) || (marks < 0 ))
		printf("Your marks should be within 0-100 range.");
	
	/* find out the proper grade */	
	else if (marks > 89)
		printf ("Grade AA");   /* marks hihger than 89 */
		
	else if (marks > 84)
		printf ("Grade BA");   /* marks within 89-85 */
		
	else if (marks > 79)
		printf("Grade BB");    /* marks within 84-80 */

	else if (marks > 74)
		printf("Grade CB");    /* marks within 75-79 */
		
	else if (marks > 69)
		printf("Grade CC");    /* marks within 74-70 */

	else if (marks > 59)
		printf("Grade DC");    /* marks within 69-60 */
		
	else if (marks > 49)
		printf ("Grade DD");   /* marks within 59-50 */
		
	else printf("Grade FF");   /* marks lower than 50 */
	
	return 0;
}






