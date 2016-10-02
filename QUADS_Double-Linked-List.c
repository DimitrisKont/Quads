/*******************************************************************
*					Doubly Linked List Quads
*
*	author: Dimitrios Kontogiannidis
*	language: C
*   version: 0.2
*
*   thanks to: https://gist.github.com/mycodeschool/7429492
********************************************************************/
#include<stdio.h>
#include<stdlib.h>

#define STAR_OP "*"
#define RESULT_OP "$$"
#define NULL_OP "-"

#define JUMP "jump"
#define IFB "ifb"


int quad_id = 0;

struct Node{
    struct Data{
        int id;
        char operator;
        char * x_op;
        char * y_op;
        char * z_op;
    }data;
    struct Node* next;
    struct Node* prev;
};

struct listNode{
    int label;
    struct listNode* next;
    struct listNode* prev;
};

struct List{
    int garbage;
	struct listNode* head;
};

struct Node * head;


/*******************************************************************************
    Create and return a quad.
********************************************************************************/
struct Node* genQuad(char quad_operator, char * quad_x_op, char * quad_y_op, char * quad_z_op){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data.id = quad_id;
    newNode->data.operator = quad_operator;
    newNode->data.x_op = quad_x_op;
    newNode->data.y_op = quad_y_op;
    newNode->data.z_op = quad_z_op;
    newNode->prev = NULL;
    newNode->next = NULL;
    quad_id++;
    return newNode;
}

/*******************************************************************************
    Return the label of the next quad.
********************************************************************************/
int nextQuad(){
    return quad_id;
}

/*******************************************************************************
    Create an empty list.
********************************************************************************/
struct List* emptyList(){
    struct List* newList = (struct List*)malloc(sizeof(struct List));
    newList->head = NULL;

    return newList;
}

/*******************************************************************************
    Create a list that has only one node with @label.
********************************************************************************/
struct List* makeList(int label){
    struct List* newList = (struct List*)malloc(sizeof(struct List));
    struct listNode* newNode = (struct listNode*)malloc(sizeof(struct listNode));
    newNode->label = label;
    newNode->prev = NULL;
    newNode->next = NULL;
    newList->head = newNode;

    return newList;
}

/*******************************************************************************
    Merge list_1 with list_2.
********************************************************************************/
struct List* mergeList(struct List * list_1,struct List* list_2){
    struct List * newList = (struct List*)malloc(sizeof(struct List));
    struct listNode * ls_node = list_1->head;
    newList->head = ls_node;
    while(ls_node->next != NULL){
        ls_node = ls_node->next;
    }
    ls_node->next = list_2->head;

    return newList;
}

/*******************************************************************************
    Insert a quad in the form of a node at the beggining of our structure.
    NOT USED !!!
********************************************************************************/
void InsertAtHead(int quad_id,char quad_operator, char * quad_x_op, char * quad_y_op, char * quad_z_op){
    struct Node* newNode = genQuad(quad_operator,quad_x_op, quad_y_op, quad_z_op);
    if(head==NULL){
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

/*******************************************************************************
    Insert a quad in the form of a node at the end of our structure.
********************************************************************************/
void InsertAtTail(char quad_operator, char * quad_x_op, char * quad_y_op, char * quad_z_op){
    struct Node* temp = head;
    struct Node* newNode = genQuad(quad_operator,quad_x_op, quad_y_op, quad_z_op);
    if(head == NULL){
        head = newNode;
        return;
    }
    while(temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

/*******************************************************************************
    Print the list of all generated quads.
********************************************************************************/
void printList(){
    struct Node* temp = head;
    printf("\nQUADS: \n");
    while(temp != NULL){
        printf("%d :  ",temp->data.id);
        printf("%c, ",temp->data.operator);
        printf("%s, ",temp->data.x_op);
        printf("%s, ",temp->data.y_op);
        printf("%s, ",temp->data.z_op);
        printf("%p\n", &(temp->data.id));
        printf("%p\n", &(temp->data.operator));
        printf("%p\n", &(temp->data.x_op));
        printf("%p\n", &(temp->data.y_op));
        printf("%p\n", &(temp->data.z_op));
        printf("\n");
        temp = temp->next;
    }
}

/*******************************************************************************
    Replace all the unknown labels of the quads cointained in @ls with @label.
********************************************************************************/
void backpatch(struct List* ls,int label){
    int index = nextQuad();
    while(ls->head != NULL){
        struct Node * temp = head;
        while(temp->data.z_op != STAR_OP){
            temp = temp->next;
        }

        ls->head = ls->head->next;
    }
    printf("backpatch");
}

int main() {

	/*Driver code to test the implementation*/
	head = NULL; // empty list. set head as NULL.

	// Calling an Insert and printing list both in forward as well as reverse direction.
	InsertAtTail('+',"a","b","$1");
    InsertAtTail('*',"5","6","$1");
    InsertAtTail('-',"8","32","$1");
    printList();

}
