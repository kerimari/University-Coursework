#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int tag;
	int length;
	char data[8];
} Message;

typedef struct node {
	Message message;
	struct node *NEXT;
} NODE;

int main(void)
{ 
	NODE *HEAD, *p;
	
	/* allocate & update first node */
	HEAD = malloc(sizeof(NODE));
	
	HEAD->message.tag = 10;
	HEAD->message.length = 3;
	strcpy(HEAD->message.data, "add");
	
	/* allocate & update 2nd node */
	HEAD->NEXT =  malloc(sizeof(NODE));
	
	p = HEAD->NEXT;
	p->message.tag = 10;
	p->message.length = 6;
	strcpy(p->message.data, "delete");
	

	/* allocate & update 3rd node */
	p->NEXT =  malloc(sizeof(NODE));
	
	p = p->NEXT;
	p->message.tag = 10;
	p->message.length = 4;
	strcpy(p->message.data, "move");
	p->NEXT = NULL;	

	/* print nodes */
	p = HEAD;
	while (p != NULL) {
		printf("NODE: %d %d %s\n", p->message.tag, p->message.length, p->message.data);
		
		p = p->NEXT;		
	}

	/* deallocate dynamic memory */
	p = HEAD;
	while (p != NULL) {
		p = HEAD->NEXT;
		free (HEAD);
		HEAD = p;		
	}
		
return 0;
}



