#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int tag;
	int length;
	char data[8];
} Message;

/* union definition */
union mg {  
 char raw[16]; 
 Message msg;
};
typedef struct node {
	union mg message;
	struct node *NEXT;
} NODE;

int main(void)
{ 
	NODE *HEAD, *p;
	int i;
	
	/* allocate & update first node */
	HEAD = malloc(sizeof(NODE));
	
	HEAD->message.msg.tag = 10;
	HEAD->message.msg.length = 3;
	strcpy(HEAD->message.msg.data, "add");
	
	/* allocate & update second node */
	HEAD->NEXT =  malloc(sizeof(NODE));
	
	p = HEAD->NEXT;
	p->message.msg.tag = 10;
	p->message.msg.length = 6;
	strcpy(p->message.msg.data, "delete");
	

	/* allocate & update second node */
	p->NEXT =  malloc(sizeof(NODE));
	
	p = p->NEXT;
	p->message.msg.tag = 10;
	p->message.msg.length = 4;
	strcpy(p->message.msg.data, "move");
	p->NEXT = NULL;
	
	/* print the linked list */
	p = HEAD;
	while (p != NULL) {
		printf("\nNODE: ");
		for (i = 0; i < sizeof(union mg); i++)
			printf("%x ", p->message.raw[i]);

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



