#ifndef LIST_H_
#define LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct Node Node;
typedef struct NodeList NodeList;

struct Node{
    int_least8_t value;
    struct Node* next;
};

struct NodeList {
    struct Node* head;
};


struct Node* findLoopInNodeList(const NodeList* list);
void nodeListCreate(NodeList* list);
void nodeListDestroy(NodeList* list);
void nodeListInsertOnEnd(NodeList* list, Node* elem);
void insertToNodeList(NodeList* list, int_least8_t elemNum);
void makeLoop(const NodeList* list, int_least8_t elemPosM, int_least8_t elemPosS);
void printNodeList(const NodeList* list);

#endif /*LIST_H_*/
