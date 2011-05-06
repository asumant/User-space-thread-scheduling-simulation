#include <stdio.h>
#include <stdlib.h>
#include "TCB.h"


void InitQ (TCB_t *Q)
{
	Q = NULL;
}

void AddQ (TCB_t **Q, TCB_t *item)
{
	TCB_t *temp;
	if (*Q == NULL)	{	/*Check If Q is empty while adding node */
		*Q = item;
		(*Q)->next = *Q;
		(*Q)->prev = *Q;
	}
	else	{
		temp = (*Q)->prev;
		temp->next = item;
		temp = temp->next;
		temp->next = *Q;
		temp->prev = (*Q)->prev;
		(*Q)->prev = temp;
	}
}

TCB_t *DelQ (TCB_t **Q)	
{
	TCB_t *temp;

	if ( *Q == NULL)	{	/* Check If Q is already empty before deleting node */ 
		printf("no context in Queue!\n");
		return NULL;
	}
	else if ((*Q)->next == *Q)	{	/* Check If Q contains only one node before deleting */
		temp = *Q;
		*Q = NULL;
		return temp;
	}
	else	{
		temp = *Q;
		(*Q) = (*Q)->next;
		(*Q)->prev = temp->prev;
		temp->prev->next=*Q;
		temp->next = NULL;
		temp->prev = NULL; 
		return temp;
	}
}

void RotateQ(TCB_t **Q)
{
	if ( *Q == NULL)	{
		printf("no context in Queue!\n");
		return;
	}
	*Q = (*Q)->next;
}
