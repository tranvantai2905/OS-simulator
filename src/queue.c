#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */	
}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose priority is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	int index = 0;
	if(q->size == 0) return NULL;
	struct pcb_t * proc = q->proc[0];
	for(int i = 1 ; i < q->size ; i++) {
		if(proc->priority < q->proc[i]->priority) {
			proc = q->proc[i];
			index = i;
		}
	}
	for(int i = index ; i < q->size - 1 ; i++) {
		q->proc[i] = q->proc[i+1];
	}
	q->size--;
	return proc;
}

