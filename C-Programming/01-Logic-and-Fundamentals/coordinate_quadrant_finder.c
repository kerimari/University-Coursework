#include <stdio.h>

int main() {
	float x, y;
	
	printf("Enter x and y coordinates:");
	int result = scanf("%f %f", &x, &y);
	
	if (result != 2)
		printf("Error in scanf.");
	
	else {
		
		printf ("(%f, %f) is ", x, y); /* print the coordinates */
		
		if (x == 0)
			printf("on the y-axis");
			
		else if (y == 0)
			printf("on the x-axis");
			
		else if (x > 0) {
			if (y > 0)
				printf("in quadrant I");     /* x>0 y>0 */
			else printf("in quadrant IV");   /* x>0 y<0 */
		}
	
		else {
			/* x<0 */
			if (y > 0)
				printf("in quadrant II");    /* x<0 y>0 */
			else printf("in quadrant III");   /* x<0 y<0 */
			
		}
		
	}
	
	return 0;
}


