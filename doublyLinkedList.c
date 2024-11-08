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

int optionsMenu(void){
    printf("Hello! I am here to help you store data in lists!\n");
    printf("What would you like to do?\n");
    printf("\t1. Add a node to the front of your list.\n");
    printf("\t2. Remove a node from the front of your list.\n");
    printf("\t3. Add a node to the back of your list.\n");
    printf("\t4. Rmove a node from the back of your list.\n");
    printf("\t5. Remove a node based on value.\n");
    printf("\t6. Remove a node based on index.\n");
    printf("\t7. Exit.\n");
    int choice;
    scanf("%d", &choice);
    return choice;
}

void printList(list *listToTraverse){
    node *nodeToPrint;
    nodeToPrint = listToTraverse->head;
    if(nodeToPrint == NULL){
        printf("Your list is empty, try adding some values.\n");
        return;
    }
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
    if(listToAddTo->head != NULL){
        listToAddTo->head->prev = nodeToAdd;
    }
    if(listToAddTo->tail = NULL){
        listToAddTo->tail = nodeToAdd;
    }
    listToAddTo->head = nodeToAdd;
}

void deleteNodeFromFront(list *listToDeleteFrom){
    if(listToDeleteFrom->head == NULL){
        printf("No elements to delete from list.\n");
    }
    else if (listToDeleteFrom->head->next != NULL){
        node *tmp = listToDeleteFrom->head;
        listToDeleteFrom->head = listToDeleteFrom->head->next;
        listToDeleteFrom->head->prev = NULL;
        free(tmp);
        tmp = NULL;
    }
    else if (listToDeleteFrom->head->next == NULL){ 
        node *tmp = listToDeleteFrom->head;
        listToDeleteFrom->head = NULL;
        free(tmp);
        tmp = NULL;        
    }
}

void addNodeToBack(list *listToAddTo, int value){   
    node *newNode = malloc(sizeof(node));
    node *tmpNode;
    newNode->value = value;
    if(listToAddTo->head == NULL && listToAddTo->tail == NULL){
        listToAddTo->head = newNode;
        listToAddTo->tail = newNode;
        return;
    }
    tmpNode = listToAddTo->head;
    newNode->next = NULL;
    while(tmpNode->next != NULL){
        tmpNode = tmpNode->next;
    }
    newNode->prev = &tmpNode;
    tmpNode->next = newNode;
    listToAddTo->tail = newNode;
}

void deleteNodeFromBack(list *listToDeleFrom){
    node *tmp = malloc(sizeof(node));
    node *tmp2 = malloc(sizeof(node));
    tmp = listToDeleFrom->head;
    while(tmp->next != NULL){
        tmp2 = tmp;
        tmp = tmp->next;
    }
    tmp2->next = NULL;
    listToDeleFrom->tail = tmp2;
    free(tmp);
    tmp = NULL;
}

void main(void){
    list l1;
    l1.head = NULL;
    l1.tail = NULL;

    int option = 0;
    int arg1 = 0;
    int arg2 = 0;
    while((option >= 0) && (option <= 6)){
        printList(&l1);
        option = optionsMenu();
        switch (option){
        case 1:
            printf("Let's add a node to the front of the list!\n");
            printf("What value do you want this node to have?\n");
            scanf("%d", &arg1);
            printf("Good choice! I'll go ahead and add that to your list.\n");
            addNodeToFront(&l1,arg1);
            break;
        case 2:
            printf("Deleting first node.\n");
            deleteNodeFromFront(&l1);
            break;
        case 3:
            printf("Let's add a node to the back of the list!\n");
            printf("What value do you want this node to have?\n");
            scanf("%d", &arg1);
            printf("Good choice! I'll go ahead and add that to your list.\n");
            addNodeToBack(&l1,arg1);
            break;
        case 4:
            printf("Deleting last node.\n");
            deleteNodeFromBack(&l1);
            break;
        }
    }
    printf("Goodbye\n");
}