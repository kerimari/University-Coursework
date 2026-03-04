#include <stdio.h>
#include <stdlib.h>

/* stack node structure */
struct node{
	double id;
	struct node *next;
};

/* add a node to the start and return new head */
struct node *push(struct node *head, double id){
	struct node *new_node;
	
	/* allocate dynamic memory for this node */
	new_node = malloc(sizeof(struct node));

	/* assign members */
	new_node->id = id;
	new_node->next = head; 
	
	/* return the new head */
	return new_node;	
}

/* delete the node from start and return new head*/
struct node *pop(struct node *head){
	struct node *ptr;
	
	/* check if stack is empty */
	if (head == NULL)
		return NULL;
		
	/* update head and deallocate the node to be deleted */
	ptr = head;
	head = head->next;
	free(ptr);

	/* return the new head */
	return head;
}

/* print the stack */
void print_stack(struct node *head){
	struct node *p = head;
	
	printf("head = %p\n", head);
	
	/* print the stack */
	while (p != NULL) {
		printf("id = %lf, next = %p\n", p->id, p->next);
		p = p->next;
	}	
}

void ins_at_pos(struct node *head, int position, double id){
	int i = 1;
	struct node *new_node, *p;
	
	/* check invalid conditions */
	if ((head == NULL) || (position <= 0))  {
		printf("Invalid insert\n");
		return;
	}
	
	p = head;
	while ((i < position) && (p->next != NULL)) {
		p = p->next;
		i++;		
	}
		
	/* allocate dynamic memory for this node */
	new_node = malloc(sizeof(struct node));	
	
	/* assign members */
	new_node->id = id;
	new_node->next = p->next; 
	
	p->next = new_node;			
}

void del_at_pos(struct node *head, int position){
	int i = 0;
	struct node *p, *prev;
	
	/* check invalid conditions */
	if ((head == NULL) || (position <= 0))  {
		printf("Invalid delete\n");
		return;
	}	
	
	p = head;
	while ((i < position) && (p->next != NULL)) {
		prev = p;
		p = p->next;
		i++;		
	}	
	
	/* cannot empty the stack (cannot update head) */
	if (p == head) {
		printf("Invalid delete\n");
		return;
	}
	
	prev->next = p->next;
	free(p);
	
}


int main() {
	
	struct node *head = NULL;  /* declare an empty list */
	int num, i;
	double id;
	
	printf("Enter number of nodes:");
	scanf("%d", &num);
	
	if (num > 0) {	
			
		/* add nodes */	
		for (i = 0; i < num; i++){

			printf("Enter id:");
			scanf("%lf", &id);    /* read id from user */
			
			head = push(head, id);     /* add a node for this id */
			
			print_stack(head);    /* print the stack after add */	
		}
	}
	printf("ins_at_pos(head, 2, 7)---------\n");	
	ins_at_pos(head, 2, 7);
	/* print the full stack */
	print_stack(head);
	printf("del_at_pos(head, 3)------------\n");
	del_at_pos(head, 3);
	/* print the full stack */
	print_stack(head);
	
	printf("Delete nodes--------------------\n");	
	/* delete nodes */
	while(head != NULL) {
		
		head = pop(head);
		print_stack(head);  /* print the stack after delete */
	}

   return 0;
}


