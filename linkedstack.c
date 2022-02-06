// typedef struct StackNodeType
// {
// 	char data;
// 	struct StackNodeType* pLink;
// } StackNode;

// typedef struct LinkedStackType
// {
// 	int currentElementCount;	// 현재 원소의 개수
// 	StackNode* pTopElement;		// Top 노드의 포인터
// } LinkedStack;

#include <stdio.h>
#include <stdlib.h>
#include "linkedstack.h"

LinkedStack* createLinkedStack()
{
    LinkedStack *re;
    re = (LinkedStack *)malloc(sizeof(LinkedStack));
    if (re == NULL)
        return (NULL);
    re->currentElementCount = 0;
    re->pTopElement = 0;
    return (re);
}

int pushLS(LinkedStack* pStack, StackNode element)
{
    StackNode* top;
    if (pStack == NULL)
        return -1;
    StackNode *eNode = (StackNode *)malloc(sizeof (StackNode));
    if (eNode == NULL)
        return -1;
    eNode->data = element.data;
    eNode->pLink = NULL;
    top = pStack->pTopElement;
    eNode->pLink = top;
    pStack->pTopElement = eNode;
    pStack->currentElementCount++;
    return (1);
}
StackNode* popLS(LinkedStack* pStack)
{
    StackNode *pop;
    StackNode *temp;

    if (pStack == NULL)
        return NULL;
    if (isLinkedStackEmpty(pStack))
        return NULL;
    pop = pStack->pTopElement;
    temp = pop->pLink;
    pStack->pTopElement = temp;
    pStack->currentElementCount--;
    // free(pop);
    return (pop);
}
StackNode* peekLS(LinkedStack* pStack)
{
    if (isLinkedStackEmpty(pStack))
        return NULL;
    return (pStack->pTopElement);
}
void deleteLinkedStack(LinkedStack* pStack)
{
    StackNode *delNode = pStack->pTopElement;
    StackNode *nextNode;
    int index = pStack->currentElementCount;
    //delNode = pStack->pTopElement;
    if (pStack ==NULL)
        return ;
    if (pStack->pTopElement == NULL)
    {
        free(pStack);
        return ;
    }
    while (delNode)
    {
        nextNode = delNode->pLink;
        delNode = nextNode;
    }
    //while ()
    pStack->currentElementCount = 0;
    pStack->pTopElement = NULL;
    free(pStack);
}

int isLinkedStackEmpty(LinkedStack* pStack)
{
    if (pStack == NULL)
        return -1;
    if (pStack->pTopElement == NULL || pStack->currentElementCount == 0)
        return 1;
    return 0;
}
void    display(LinkedStack *pStack)
{
    StackNode *printNode = pStack->pTopElement;
    while(printNode)
    {
        printf("%c\n", printNode->data);
        printNode = printNode->pLink;
    }
}
// int main()
// {
//     LinkedStack* test = createLinkedStack();
//     StackNode *t;
//     StackNode e;
//     StackNode e1;
//     StackNode e2;

//     e.data = 'A';
//     e1.data = 'B';
//     e2.data = 'C';

//     pushLS(test, e);
//     // printf("%c\n", test->pTopElement->data);
//     pushLS(test, e1);
//     // printf("%c\n", test->pTopElement->data);
//     pushLS(test, e2);
//     // printf("%c\n", test->pTopElement->data);
//     //display(test);
//     //t = peekLS(test);

//     //printf("%c\n", t->data);
    
//     deleteLinkedStack(test);
//     test = NULL;
//     //printf("%c\n",popLS(test)->data);
//     //printf("%c\n", popLS(test)->data);
//     //popLS(test);
//     //popLS(test);
//     //popLS(test);
//     pushLS(test, e);
//     //printf("%d\n", pushLS(test, e));
//     display(test);
//     // printf("%c\n", test->pTopElement->data);
//     return 0;
// }
