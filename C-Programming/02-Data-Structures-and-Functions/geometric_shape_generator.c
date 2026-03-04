#include <stdio.h>


void shape1(int n)
{
	int i, j, k;
    for(i=1;i<=n;i++)
       {
       		/* print spaces */
           for(j=1;j<=n-i;j++)
               printf(" ");
               
           /* print stars */
           for(k=1;k<=2*i-1;k++)
             printf("*");
           
         /* print end of line */  
    	printf("\n");
        }	
}

void shape2(int n)
{
	int i, j, k;
    for(i=1;i<=n;i++)
    {
    	/* first line */
		printf("*");
		
		/* lines other than first line */
        for(j=2;j<=i;j++)
        {
            if( i==j || i==n )
            	printf("*");
            else
            	printf(" ");
        }
        
        /* print end of line */
        printf("\n");
    }	
}

void shape3(int n)
{
	int i, j, k;
	
    for(i=1;i<=n;i++)
    {
    	/* print spaces */
        for(j=1;j<=n-i;j++)
            printf(" ");
        
        /* print stars */
        for(k=1;k<=n;k++)
            printf("*");
            
        /* print end of line */
        printf("\n");
    }	
	
}

void shape4(int n)
{
	int i, j, k;
	
    for(i=n;i>=1;i--)
    {
    	/* print spaces */
    	for(j=1;j<=i-1;j++)
    		printf(" ");

		/* print stars */
    	for(k=1;k<=n;k++)
    		if((i==1) || (i==n) || (k==1) || (k==n))
    			printf("*");
    		else
    			printf(" ");
    			
    	/* print end of line */
    	printf("\n");
    }	
}




int main()
{
    int n, d;

    printf("Enter the number of rows:");
    scanf("%d",&n);
    printf("Enter shape selection:");
    scanf("%d",&d);

	switch (d)
	{
		case 1:
			shape1(n);
			break;
		case 2:
			shape2(n);
			break;	
		case 3:
			shape3(n);
			break;
		case 4:
			shape4(n);
			break;
		default :
			printf("No selection");
	}
	
    return 0;
}








