#ifndef _LINKED_STACK_
#define _LINKED_STACK_

typedef struct StackNodeType
{
	char data;
	struct StackNodeType* pLink;
} StackNode;

typedef struct LinkedStackType
{
	int currentElementCount;	// 현재 원소의 개수
	StackNode* pTopElement;		// Top 노드의 포인터
} LinkedStack;

LinkedStack* createLinkedStack();
int pushLS(LinkedStack* pStack, StackNode element);
StackNode* popLS(LinkedStack* pStack);
StackNode* peekLS(LinkedStack* pStack);
void deleteLinkedStack(LinkedStack* pStack);
int isLinkedStackFull(LinkedStack* pStack);
int isLinkedStackEmpty(LinkedStack* pStack);

#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE		1
#define FALSE		0

#endif

/*
ArrayList* createArrayList(int maxElementCount)
{

	ArrayList *list = (ArrayList *)malloc(sizeof(ArrayList));
	if (!list)
		return NULL;

	ArrayListNode	*pElement;
	pElement = (ArrayListNode *)malloc(sizeof(ArrayListNode) * maxElementCount);
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


//void deleteArrayList(ArrayList* pList)

int isArrayListFull(ArrayList* pList)
{
	if (!pList)
		return -1;

	if (pList->maxElementCount <= pList->currentElementCount)
	{
		return 1;
	}
	return 0;
}

void grow(ArrayList *pList)
{
	if (pList == NULL)
		return ;

	int oldElementCount = pList->maxElementCount;
	int currentEleCount = pList->currentElementCount;
	int i;

	int newElementCount = oldElementCount + (oldElementCount >> 1) + 1;

	ArrayListNode *newData = (ArrayListNode *)malloc(sizeof(int) * newElementCount);
	if (newData == NULL)
	{
		return ;
	}

	for (i = 0; i < currentEleCount; i++)
	{
		newData[i] = pList->pElement[i];
	}

	pList->maxElementCount = newElementCount;
	free(pList->pElement);
	pList->pElement = newData;
}


ArrayListNode  ArrayListNodereturn(int element)
{
	ArrayListNode list;
	list.data = element;
	return list;
}

int addALElement(ArrayList* pList, int position, ArrayListNode element)
{
	if (!pList)
	       return -1;
	if (position > pList->currentElementCount)
	{
		return -1; // 배열이 3 까직인데 5 에 삽입 하려고 할때 에러
	}
	if (position < 0)
	{
		return -1;
	}

	if (isArrayListFull(pList))
		grow(pList);
	pList->currentElementCount++;
	int count = pList->currentElementCount;

	int i;
	for (i = count - 1; i >= position; i--)
	{
		pList->pElement[i + 1] = pList->pElement[i];
	}

	pList->pElement[position] = element;
	return 1;

}





int removeALElement(ArrayList* pList, int position)
{
	if (pList == NULL)
		return -1;
	if (position > pList->currentElementCount)
		return -1;
	if (position < 0)
		return -1;
	pList->currentElementCount--;
	int count = pList->currentElementCount;

	int i;
	for (i = position; i <= count; i++)
	{
		pList->pElement[i] = pList->pElement[i+1];
	}
	return 1;
}

ArrayListNode* getALElement(ArrayList* pList, int position)
{
	if (pList == NULL)
		return NULL;
	if (position > pList->currentElementCount)
		return NULL;
	if (position < 0)
		return NULL;
	return &pList->pElement[position];
}

void displayArrayList(ArrayList* pList)
{
	int i;
	printf("list = [");
	for (i = 0; i < pList->currentElementCount; i++)
	{
		printf("%d", pList->pElement[i].data);
		if (i != pList->currentElementCount - 1)
			printf(" , ");
	}
	printf("]\n");
}


void clearArrayList(ArrayList* pList)
{
	free(pList->pElement);
	pList->currentElementCount = 0;
	pList->maxElementCount = 0;
	free(pList);
}



int getArrayListLength(ArrayList* pList)
{
	if(pList == NULL)
	{
		return -1;
	}
	return pList->currentElementCount;
}
int main() {

    ArrayList *list = createArrayList(5);
    printf("capacity is %d\n", list->maxElementCount); // 5

    addALElement(list, 0, ArrayListNodereturn(1)); // [1]
    addALElement(list, 1, ArrayListNodereturn(2)); // [1, 2]
    addALElement(list, 2, ArrayListNodereturn(3)); // [1, 2, 3]
    addALElement(list, 3, ArrayListNodereturn(4)); // [1, 2, 3, 4]
    addALElement(list, 4, ArrayListNodereturn(5)); // [1, 2, 3, 4, 5]
    addALElement(list, 5, ArrayListNodereturn(6)); // [1, 2, 3, 4, 5, 6] => grow
    printf("capacity is %d\n", list->maxElementCount); // 8

    addALElement(list,6, ArrayListNodereturn(7)); // [1, 2, 3, 4, 5, 6, 7]
    addALElement(list,7, ArrayListNodereturn(8)); // [1, 2, 3, 4, 5, 6, 7, 8]
    addALElement(list,8, ArrayListNodereturn(9)); // [1, 2, 3, 4, 5, 6, 7, 8, 9] => grow
    printf("capacity is %d\n", list->maxElementCount); // 13

    addALElement(list, 0, ArrayListNodereturn(50)); // [50, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    addALElement(list, 2, ArrayListNodereturn(52)); // [50, 1, 52, 2, 3, 4, 5, 6, 7, 8, 9]
    addALElement(list, 4, ArrayListNodereturn(54)); // [50, 1, 52, 2, 54, 3, 4, 5, 6, 7, 8, 9]

    removeALElement(list, 1); // [50, 52, 2, 54, 3, 4, 5, 6, 7, 8, 9]
    removeALElement(list, 2); // [50, 52, 54, 3, 4, 5, 6, 7, 8, 9]
    removeALElement(list, 9); // [50, 52, 54, 3, 4, 5, 6, 7, 8]

    printf("size is %d\n", list->currentElementCount); // size is 9
    printf("list[0] is %d\n", getALElement(list, 0)->data); // list[0] is 50
    printf("list[2] is %d\n", getALElement(list, 2)->data); // list[2] is 54
   // printf("is list empty ? {0:NO , 1:YES} => %d\n", isEmpty(list));
//
    displayArrayList(list); // [50, 52, 54, 3, 4, 5, 6, 7, 8]
    clearArrayList(list);
    return 0;
}
*/
