#include <stdio.h>
#include <stdlib.h>
//#include "TCB.h"


typedef struct TCB_t    {
//        ucontext_t context;
	int context;
        struct TCB_t *next;
        struct TCB_t *prev;
}TCB_t;

TCB_t *Q;

void display();
/*void InitQ (TCB_t Q)
{
	Q = NULL;
} */

//void AddQ (TCB_t **Q, TCB_t *item)
void add(int data)
{
	TCB_t *temp;
	int tmp;
	if (Q == NULL)	{	/*Check If Q is empty while adding node */
		Q = (TCB_t*) malloc(sizeof(TCB_t));
		Q -> context = data;
		Q->next = Q;
		Q->prev = Q;
	}
	else	{
		temp = (TCB_t*) malloc(sizeof(TCB_t));
		temp->context= data;
		temp->next = Q;
		temp->prev = Q->prev;
		Q->prev->next=temp;
		Q->prev = temp;
	}
	display();
}

//TCB_t *DelQ (TCB_t **Q)	
void delete()
{
	TCB_t *temp;

	if ( Q == NULL)	{	/* Check If Q is already empty before deleting node */ 
		printf("no context in Queue!\n");
		return;
	}
	else if (Q->next == Q)	{	/* Check If Q contains only one node before deleting */
		//temp = *Q;
		//free(Q);
		Q = NULL;
		//return temp;
	}
	else	{
		/*temp = (*Q)->prev;
		(*Q)->prev = (*Q)->prev->prev;
		temp->next = NULL;
		temp->prev = NULL;
		(*Q)->prev->next = (*Q); */
		temp = Q;
		Q = Q->next;
		Q->prev = temp->prev;
		temp->prev->next=Q;
		temp->next = NULL;
		temp->prev = NULL; 
		//return temp;
	}
	display();
}

//void RotateQ(TCB_t **Q)
void RotateQ()
{
	if ( Q == NULL)	{
		printf("no context in Queue!\n");
		return;
	}
	Q = Q->next;
	display();
}

void display()
{
	TCB_t *temp = Q;

	if(Q != NULL)
	printf("Q is :%d ", Q->context);
	else return;
	temp = temp ->next;
	while (temp != Q)	{
		printf("%d ",temp->context);
		temp =temp -> next;
	}
	printf("\n");
}

int main()
{
	int ch,num;

	while (1)	{
	printf("enter choice: ");
	scanf("%d",&ch);

	
	switch(ch)
	{
		case 1: printf("enter number:");
			scanf("%d",&num);
			add(num);
			break;
		case 2: delete();
			break;
		case 3: RotateQ();
			break;
		case 4: exit(1);
	}
	}
	return 0;
}
