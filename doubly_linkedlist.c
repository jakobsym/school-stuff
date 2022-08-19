/* Doubly Linked List example
    - We use doubly linked list, because a singly linked list is not as efficient
    if changes need to be made to our list.
    - Saves time as we can just find any node, and updates its pointers

 */
#include <stdlib.h>
#include <stdio.h>

void insertAtHead(int n); // Will take an int as argument
void insertAtTail(int n); // Will take an int as argument
void printNodes();
void revprintNodes();


struct __NODE
{
    int data;
    struct __NODE *next; //next pointer
    struct __NODE *prev; 
   
};
typedef struct __NODE node;
node *NewNode(int n);

node *head = NULL; //global head variable
int main(){



    insertAtTail(1);
    insertAtHead(2);
    //insertAtHead(3);
    //insertAtHead(4);
    printNodes();
    revprintNodes();

    return 0;
}


void printNodes(){
    node* tmp = head;
    printf("Starting at head: ");
    while(tmp != NULL){
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

void revprintNodes(){
    node *tmp = head;
    /* Check if list is empty */
    if(tmp == NULL){
        return;
    }
    /* Going to last node */
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    /* Traversing backwards using prev pointer. */
    printf("Starting at tail: ");
    while(tmp != NULL){
        printf("%d ", tmp->data);
        tmp = tmp->prev;
    }
    printf("\n");
}

void insertAtHead(int n){
    node *tmp = NewNode(n);
    if(head == NULL){
        head = tmp;
        return;
    }
    /* If list is no longer empty */

    head->prev = tmp; // changing prev, allows us to put something in front of current head
    tmp->next = head; // tmp->prev is null, as this is head after function call
    head = tmp; // memory location of tmp, is now head
}


void insertAtTail(int n){
    node* newNode = NewNode(n);
    node *tmp = head;

    if(head == NULL){
        head = newNode;
        return;
    }

    while(tmp->next != NULL) {
        tmp = tmp->next; // Go to last node
        tmp->next = newNode;
        newNode->prev = tmp;
    }
}

node *NewNode(int n){
    node *newNode = (node*)malloc(sizeof(node)); // memory of this node is stored in heap
    newNode->data = n;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
