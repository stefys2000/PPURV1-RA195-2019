#include "list.h"

/*
Assignment num. 1
Main task was to create a function that checks if linked list contains element which next attribute points to one of previous elements.
Linked list is created in loop in which element is added to the end.
TEST:
    1) It was tested by adding 127 and less elements to the end of the linked list
    2) Manually adding elements to the list

insertToNodeList()
    Max number has to be less then 128 (127 e.g.) because of size of int_least8_t in value of node element.
    Value attribute is set to be index of element in list.

makeLoop()
    Element that is starting the loop (elemPosM - Element on Position/Master) can be the last element in list (on index 126 if number of elements is 127 e.g.).
    Element on which is pointed (elemPosS - Element on Position/Slave) can be any element in list except the elemPosM.
    If makeLoop() method is commented out, linked list is created without loop.

In findLoopInNodeList() method, functionality has been created in while loops.

MISRA WARNINGS:
    free and malloc had to be used because of clearing unused memory after program termination.

Stefan Mrdjanovic RA195/2019
*/

int main() {
    NodeList elemList;
    nodeListCreate(&elemList);
    insertToNodeList(&elemList, 127);
    makeLoop(&elemList,126,0);
    printNodeList(&elemList);
    nodeListDestroy(&elemList);

    return EXIT_SUCCESS;
}
