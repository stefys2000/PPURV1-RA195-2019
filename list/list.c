#include "list.h"

static Node* end= NULL;

struct Node* findLoopInNodeList(const NodeList* list)
{
    Node* i = list->head;
    while (i != end)
    {
        Node* j = list->head;
        while (j != i)
        {
            if (i->next == j)
            {
                /* goto finish; */
                return i;
            }
            j = j->next;
        }
        i = i->next;
    }

/*
finish:
    return i;
*/

    return end;
}

void nodeListCreate(NodeList* list)
{
    list->head = end;
}

void nodeListDestroy(NodeList* list)
{
    Node* tempDestElem;
	Node* delete;
    Node* check = findLoopInNodeList(list);

    if(check != end){
        tempDestElem = list->head;
        while(tempDestElem->next != check){
            tempDestElem = tempDestElem->next;
        }
        tempDestElem->next = end;
        free(check);
    }
    tempDestElem = list->head;

	while(tempDestElem != end) {
		delete = tempDestElem;
        tempDestElem = tempDestElem->next;
        free(delete);
	}
	free(tempDestElem);
	list->head = end;
}

void nodeListInsertOnEnd(NodeList* list, Node* elem)
{
    Node* tempInsElem = list->head;
    if (tempInsElem == end)
    {
        list->head = elem;
        elem->next = end;
    }
    else
    {
        while (tempInsElem->next != end)
        {
            tempInsElem = tempInsElem->next;
        }
        tempInsElem->next = elem;
        elem->next = end;
    }
}

void insertToNodeList(NodeList* list, int_least8_t elemNum)
{
    int8_t posCounter = 0;

    while (posCounter < elemNum)
    {
        struct Node* insElem = (struct Node*)malloc(sizeof(struct Node));
        insElem->value = posCounter;
        insElem->next = end;

        nodeListInsertOnEnd(list,insElem);
        posCounter++;
    }
}

void makeLoop(const NodeList* list, int_least8_t elemPosM, int_least8_t elemPosS)
{
    struct Node* tempLoopElem1 = list->head;
    struct Node* tempLoopElem2 = list->head;

    int_least8_t temp1PosCounter = 0;
    int_least8_t temp2PosCounter = 0;

    while (temp1PosCounter < elemPosM)
    {
        tempLoopElem1 = tempLoopElem1->next;
        temp1PosCounter++;
    }

    while (temp2PosCounter < elemPosS)
    {
        tempLoopElem2 = tempLoopElem2->next;
        temp2PosCounter++;
    }

    tempLoopElem1->next = tempLoopElem2;
}


void printNodeList(const NodeList* list)
{
    /*Using placeholder %d instead of %"PRIi8" because of C's default argument promotions (using %d for all signed types)*/

    Node* loopElem = findLoopInNodeList(list);

    if(loopElem != end)
    {
        printf("\n\nElement on address: %p is making a loop by pointing to element on address: %p\n\n\n", loopElem, loopElem->next);
    }
    else
    {
        printf("\n\nPrinting list \n\n");
        Node* printElem = list->head;
        while (printElem != end)
        {
            printf("Index: %d\tNext: %p", printElem->value, printElem-> next);
            if (printElem == list->head)
            {
                printf("\t<--- HEAD\n");
            } else
            {
                printf("\n");
            }
            printElem = printElem->next;
        }
        printf("\n\n");
    }
}
