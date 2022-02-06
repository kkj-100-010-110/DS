#include <stdio.h>
#include <stdlib.h>
#include "arraystack.h"

ArrayStack* createArrayStack(int maxElementCount)
{
	ArrayStack *list = (ArrayStack *)malloc(sizeof(ArrayStack));
	if (!list)
		return NULL;

	ArrayStackNode	*pElement;
	
    pElement = (ArrayStackNode *)malloc(sizeof(ArrayStackNode) * maxElementCount);
	if(!(pElement))
		return (NULL);
	int i;
	for ( i = 0; i < list->maxElementCount; i++)
	{
		pElement[i].data = 0;
	}

	list->maxElementCount = maxElementCount;
	list->currentElementCount = 0;
	list->pElement = pElement;
	return list;
}
int isArrayStackFull(ArrayStack* pStack)
{
    if (!pStack)
		return -1;
	if (pStack->maxElementCount <= pStack->currentElementCount)
	{
		return 1;
	}
	return 0;
}
int pushAS(ArrayStack* pStack, ArrayStackNode element)
{
	int origin_current = pStack->currentElementCount;

    if (!pStack)
        return -1;
    if (isArrayStackFull(pStack))
    {   
        printf("Full\n");
        return -1;
    }     
	if (pStack->maxElementCount > origin_current)
	{
		pStack->pElement[origin_current].data = element.data;
        //origin_current++;
	}
	(pStack->currentElementCount)++;
	return (1);
}

ArrayStackNode  ArrayStackNodereturn(char element)
{
	ArrayStackNode list;
	list.data = element;
	return list;
}

ArrayStackNode* popAS(ArrayStack* pStack)
{
	ArrayStackNode *temp = (ArrayStackNode*)malloc(sizeof(ArrayStackNode));
	if (!temp)
		return NULL;
    int n = pStack->currentElementCount - 1;
    if (isArrayStackEmpty(pStack))
        return NULL;
    
    //printf("%c\n", pStack->pElement[n - 1].data);
	temp->data = pStack->pElement[n].data;
    pStack->pElement[n].data = 0;
    pStack->currentElementCount--;

    return (temp);
}

ArrayStackNode* peekAS(ArrayStack* pStack)
{
    int n = pStack->currentElementCount;
    printf("%c\n", pStack->pElement[n - 1].data);
    return (pStack->pElement);
}

void deleteArrayStack(ArrayStack* pStack)
{
    free(pStack->pElement);
	pStack->currentElementCount = 0;
	pStack->maxElementCount = 0;
	free(pStack);
}

int isArrayStackEmpty(ArrayStack* pStack)
{
    if (!pStack)
		return -1;
	if (pStack->currentElementCount == 0 && pStack->maxElementCount != 0)
	{
		return 1;
	}
	return 0;
}

// int main()
// {
//     ArrayStack* test;
//     int max = 5;

//     test = createArrayStack(max);
//     pushAS(test, ArrayStackNodereturn('a'));
//     pushAS(test, ArrayStackNodereturn('b'));
//     pushAS(test, ArrayStackNodereturn('c'));
//     pushAS(test, ArrayStackNodereturn('d'));
//     pushAS(test, ArrayStackNodereturn('e'));
//     // pushAS(test, ArrayStackNodereturn('f'));
//     // popAS(test);
// 	printf("%c\n", popAS(test)->data);

//     peekAS(test);

//     deleteArrayStack(test);
//     printf("%d\n", test->pElement->data);
//     // printf("%d\n", isArrayStackEmpty(test));
//     // 
//     return 0;
// }