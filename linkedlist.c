#include <stdlib.h>
#include <stdio.h>

/* structure that represents nodes of a list*/
struct node {
    int value; //using numbers here, but can be anything
    struct node* next; //struct pointer that points to next node in list
}; 
typedef struct node node_t;

void printList(node_t *head){
    node_t *temp = head; //temporary head so we can cycle through nodes
    while(temp != NULL){
        printf("%d |", temp->value); //prints value that temp is pointing to. Remember temp is basically the head and our head is initially pointing to 'n3'
        temp = temp->next; //cycle through all nodes
    }
    printf("\n");
}

int main() {
    node_t n1, n2, n3; //creation of 3 nodes. We can add more nodes via "node_t 'nx'" where x >= 1
    node_t *head; //creating an initial position for nodes

    n1.value = 12;
    n2.value = 21;
    n3.value = 50;

    /* linking our nodes 
    - We can rerrange nodes, simply by changing what the head points to, and what node.next = NULL */
    head = &n3;
    n3.next = &n2;
    n2.next = &n1;
    n1.next = NULL; //indicate ending so we know where to stop
    printList(head);

    return 0;
}
