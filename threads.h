#include "q.h"
#define stack_size 8192

void start_thread(void (*function) (void))
{
	void *stack;
	TCB_t *tcb;
	
	stack = malloc(stack_size);
	tcb = (TCB_t *) malloc(sizeof(TCB_t));
	init_TCB(tcb, function, stack, stack_size);
	AddQ(&RunQ,tcb);
}

void run ()
{
	ucontext_t parent;
	getcontext(&parent);
	swapcontext(&parent,&(RunQ->context));
}

void yield()
{
	ucontext_t parent; 
	getcontext(&parent); /* Store the current context in parent */
	RunQ->context = parent; /* Save the state of a current context before transferring control to the next thread */ 
	RotateQ(&RunQ);
	swapcontext(&parent, &(RunQ->context)); 
}
