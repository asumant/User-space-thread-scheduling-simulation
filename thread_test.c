/*
----------------------------------------------------------
CSE 531 – Distributed and Multiprocessor Operating Systems
		Fall 2010
		Project #1

Submitted by : Akshay Sumant , Anand Dandekar
----------------------------------------------------------
*/

#include <stdio.h>
#include "threads.h"

int test_global;

void f1()
{
	int local_f1 = 0;
	while(1)	{
		printf ("in f1\n");
		test_global++;
		local_f1++;
		printf("test_global = %d local_f1= %d\n",test_global, local_f1);
		sleep(2);
		yield();  /* Preempts itself and transfers control to the next thread in queue */
		printf("after yield f1\n");
	}
}

void f2()
{
	int local_f2;
	while(1)	{
		printf ("in f2\n");
		test_global++;
		local_f2++;
		printf("test_global = %d local_f2= %d\n",test_global, local_f2);
		sleep(2);
		yield();
		printf("after yield f2\n");
	}
}


void f3()
{
	int local_f3;
	while(1)	{
		printf ("in f3\n");
		test_global++;
		local_f3++;
		printf("test_global = %d local_f3= %d\n",test_global, local_f3);
		sleep(2);
		yield();
		printf("after yield f3\n");
	}
}

int main()
{
	start_thread(f1); /* Initializing context for f1 */
	start_thread(f2); /* Initializing context for f2 */
	start_thread(f3); /* Initializing context for f3 */
	run(); /* Transfer control to first thread in queue */
	return 0;		
}
