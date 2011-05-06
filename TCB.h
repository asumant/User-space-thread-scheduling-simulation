#include <ucontext.h>
#include <string.h>

/* Structure for the node of a Q */
typedef struct TCB_t	{
	ucontext_t context;
	struct TCB_t *next;
	struct TCB_t *prev;
}TCB_t;

TCB_t *RunQ; /* Global head pointer of a queue */ 

void init_TCB (TCB_t *tcb, void *function, void *stackP, int stack_size)
{
	memset(tcb, '\0' , sizeof(TCB_t));
	getcontext(&tcb->context);
	tcb->context.uc_stack.ss_sp = stackP;
	tcb->context.uc_stack.ss_size = (size_t) stack_size;
	makecontext(&tcb->context,function,0);
}
