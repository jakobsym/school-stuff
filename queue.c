#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/* LL methods */
void freelist(LLnode *p);
LLnode *createNode();

/* Queue methods */
queue *createQueueNode();
void Enqueue(queue *a, int x);
boolean isEmpty(queue *a);




/* Dynamically creating our queue, we must create a queue creation method */
struct queue{
	LLnode *front;
	LLnode *rear;
};
typedef struct queue queue;

/* Will be using this LL to create our Queue(front/rear) */
struct LLnode {
	int data;
	struct LLnode *next; /* next pointer */
};
typedef struct LLnode LLnode; /* LLnode is keyword to rep this struct */






int main() {
	queue q1;

	q1 = createQueueNode();



	return 0;
}


boolean isEmpty(queue *a){
	return(a->front == NULL);
}




/* allocating space for a node within queue, FREE later */
queue createQueueNode(){
	queue *a;

	a = (queue*)malloc(sizeof(queue));

	if(a != NULL){
		a->front = NULL;
		a->rear = NULL;
	}
	return a;
}

/* runtime = O(n); We are cycling through p (n) times */
void freelist(LLnode *p){
	if(p == NULL)
		return
	freelist(p->next);
	free(p);
}
