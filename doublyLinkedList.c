#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int value;
    void *prev;
    void *next;
} node;

typedef struct{
    node *head;
    node *tail;
}list;

void printList(list *listToTraverse){
    node *nodeToPrint;
    nodeToPrint = listToTraverse->head;
    while(nodeToPrint != NULL){
        if(listToTraverse->head == nodeToPrint){
            printf("%d", nodeToPrint->value);
        }
        else{
            printf(" <-> %d", nodeToPrint->value);
        }
        nodeToPrint = nodeToPrint->next;
    }
    printf("\n");
}

void addNodeToFront(list *listToAddTo, int valueToAdd){
    node *nodeToAdd = malloc(sizeof(node));
    nodeToAdd->value = valueToAdd;
    nodeToAdd->next = listToAddTo->head;
    listToAddTo->head->prev = nodeToAdd;
    listToAddTo->head = nodeToAdd;
}

void main(void){
    list l1;
    node n1, n2, n3;

    l1.head = &n1;
    n1.next = &n2;
    n1.prev = NULL;
    n2.next = &n3;
    n2.prev = &n1;
    n3.prev = &n2;
    n3.next = NULL;

    n1.value = 420;
    n2.value = 69;
    n3.value = 42;

    printList(&l1); 
    addNodeToFront(&l1, 17);
    printList(&l1);

}