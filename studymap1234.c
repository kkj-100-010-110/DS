
#include <stdio.h>
#include <stdlib.h>


//////////////////////////////////

#define WIDTH 8
#define HEIGHT 8

#define NUM_DIRECTIONS 4

typedef struct MapPositionType
{
	int x;				// 현재 위치 x좌표.
	int y;				// 현재 위치 y좌표.
	// int direction;		// 다음 위치로 이동 방향 
} MapPosition;



// offset: x, y
static int DIRECTION_OFFSETS[NUM_DIRECTIONS][2] = {
	{0, -1},		// 위쪽으로 이동	0
	{-1, 0},			// 왼쪽으로 이동	3
	{0, 1},			// 아래쪽으로 이동	2
	{1, 0}			// 오른쪽으로 이동	1
};
typedef struct StackNodeType
{
	MapPosition data;
	struct StackNodeType* pLink;
} StackNode;

typedef struct LinkedStackType
{
	int currentElementCount;	// 현재 노드 개수
	StackNode* pTopElement;		// Top 노드에 대한 포인터
} LinkedStack;
 
LinkedStack* createLinkedStack();
int pushLS(LinkedStack* pStack, StackNode element);
StackNode* popLS(LinkedStack* pStack);
StackNode* peekLS(LinkedStack* pStack);
void deleteLinkedStack(LinkedStack* pStack);
//int isLinkedStackFull(LinkedStack* pStack);
int isLinkedStackEmpty(LinkedStack* pStack);
void displayLinkedStack(LinkedStack* pStack);

#define TRUE		1
#define FALSE		0


LinkedStack* createLinkedStack()
{
	LinkedStack *stack;

	stack = (LinkedStack *)malloc(sizeof(LinkedStack));
	if (stack == NULL)
	{
		printf("(NULL)\n");
		return (NULL);
	}
	stack->currentElementCount = 0;
	stack->pTopElement = NULL;
	return (stack);
}

int pushLS(LinkedStack* pStack, StackNode element)
{
	StackNode* addNode;
	StackNode* top;

	if (pStack == NULL)
	{
		printf("(NULL)\n");
		return (FALSE);
	}
	addNode = (StackNode*)malloc(sizeof(StackNode));
	if (addNode == NULL)
		return (FALSE);
	*addNode = element;
	addNode->pLink = NULL;
	top = pStack->pTopElement;
	addNode->pLink = top;
	pStack->pTopElement = addNode;
	pStack->currentElementCount++;
	return (TRUE);
}

StackNode* popLS(LinkedStack* pStack)
{
	StackNode* pop;
	StackNode* top;

	if (pStack == NULL || pStack->pTopElement == NULL || pStack->currentElementCount == 0)
	{
		printf("(NULL)\n");
		return (NULL);
	}

	pop = pStack->pTopElement;
	top = pop->pLink;
	pStack->pTopElement = top;
	pStack->currentElementCount--;
	return (pop);
}

// pStack == NULL pStack->pTopElement == NULL
//의 구분을 잘하자!

StackNode* peekLS(LinkedStack* pStack)
{
	if (pStack == NULL || pStack->pTopElement == NULL || pStack->currentElementCount == 0)
	{
		printf("(NULL)\n");
		return (NULL);
	}
	return (pStack->pTopElement);
}

void deleteLinkedStack(LinkedStack* pStack)
{
	StackNode *delNode;
	StackNode *nextNode;

	if (pStack == NULL)
	{
		printf("(NULL)\n");
		return ;
	}
	else if (pStack->pTopElement == NULL)
	{
		printf("(NULL)\n");
		free(pStack);
		return ;
	}
	delNode = pStack->pTopElement;
	while (delNode)
	{
		nextNode = delNode->pLink;
		free(delNode);
		delNode = nextNode;
	}
	pStack->currentElementCount = 0;
	pStack->pTopElement = NULL;
	free(pStack);
	// pStack = NULL; 이거는 의미가 없다
}

int isLinkedStackEmpty(LinkedStack* pStack)
{
	if (pStack == NULL)
		return (FALSE);
	if (pStack->pTopElement == NULL)
		return (TRUE);
	return (FALSE);
}

void displayLinkedStack(LinkedStack* pStack)
{
	StackNode *printNode;

	if (pStack == NULL)
	{
		printf("pStack is (NULL)\n");
		return ;
	}
	printNode = pStack->pTopElement;
	printf("=== current : [%d] ===\n", pStack->currentElementCount);
	printf("[head]\n");
	printf(" ⇂\n");
	while (printNode)
	{
		printf("[%d, %d]\n", printNode->data.x, printNode->data.y);
		printNode = printNode->pLink;
		if (printNode != NULL)
			printf(" ⇂\n");
	}
	printf("[bottom]\n");
}

enum PosStatus { NOT_VISIT = 0, WALL = 1 , VISIT = 2  };
enum rdlu { RIGHT, DOWN, LEFT, UP};

void findPath(int mazeArray[HEIGHT][WIDTH],
		MapPosition startPos, MapPosition endPos, LinkedStack *pStack);
int pushLSMapPosition(LinkedStack* pStack, MapPosition data);
void printMaze(int mazeArray[HEIGHT][WIDTH], MapPosition S, MapPosition E);

void showPath(LinkedStack *pStack, int mazeArray[HEIGHT][WIDTH], MapPosition S, MapPosition E);

////////////////////////////////////////////

void showPath(LinkedStack *pStack, int mazeArray[HEIGHT][WIDTH], MapPosition S, MapPosition E)
{
	printMaze(mazeArray,S,E);
	printf("\n");
	displayLinkedStack(pStack);
	printf("\n");
}
///////////////////////
void read_maze(int mazeArray[HEIGHT][WIDTH], MapPosition S, MapPosition E)
{
    int i;
    int j;
    // 시작점 탐색 
  
    printf("미로 \n"); 

    for(int i=0; i<HEIGHT; i++)
    { 
        for(int j=0; j<WIDTH; j++)
        { 
			if(i == S.x && j == S.y)
				printf(" S ");
			else if(i == E.x && j == E.y)
				printf(" E ");
            else if(mazeArray[i][j]== 0 )
            { 
                printf(" ◻︎ "); 
            }
            else if(mazeArray[i][j]== 1 )
            { 
                printf(" ◼︎ "); 
			}
        } 
        printf("\n"); 
    } 
    printf("\n이동 경로\n");  
}
//////////////////////////////////
void printMaze(int map[HEIGHT][WIDTH], MapPosition S, MapPosition E)
{
	int y;
	int x;

	for (y = 0; y < HEIGHT; y++)
	{
		for (x = 0; x < WIDTH; x++)
		{ 
			if(x == S.x && y == S.y)
				printf(" S ");
			else if(x == E.x && y == E.y)
				printf(" E ");
            else if(map[x][y]== 0 )
            { 
                printf(" ◻︎ "); 
            }
            else if(map[x][y]== 1 )
            { 
                printf(" ◼︎ "); 
			}
			else if(map[x][y] == 2)
			{
				printf(" # ");
			}
        } 
        printf("\n"); 
	}
}

int pushLSMapPosition(LinkedStack* pStack, MapPosition data)
{
	StackNode element;

	element.data = data;
	return (pushLS(pStack, element));
}

int check(int mazeArray[HEIGHT][WIDTH], int x, int y, int dir)
{
	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return (FALSE);
	if (dir == RIGHT && x + 1 < WIDTH && mazeArray[y][x + 1] == NOT_VISIT)
		return (TRUE);
	if (dir == DOWN && y + 1 < HEIGHT && mazeArray[y + 1][x] == NOT_VISIT)
		return (TRUE);
	if (dir == LEFT && x - 1 >= 0 && mazeArray[y][x - 1] == NOT_VISIT)
		return (TRUE);
	if (dir == UP && y - 1 >= 0 && mazeArray[y - 1][x] == NOT_VISIT)
		return (TRUE);
	return (FALSE);
}

static void dfs(int mazeArray[HEIGHT][WIDTH], LinkedStack *pStack, MapPosition startPos, MapPosition endPos)
{
	MapPosition pos;
	pos.x = pStack->pTopElement->data.x;
	pos.y = pStack->pTopElement->data.y;


	if (pos.x == endPos.x && pos.y == endPos.y)
	{
		mazeArray[pos.y][pos.x] = 2;
		return ;
	}
	else if (pos.x < 0 || pos.y < 0 || pos.x >= WIDTH || pos.y >= HEIGHT)
	{
	   return ;
	}
	else if(check(mazeArray, pos.x, pos.y, RIGHT)) //오른쪽
	{
		mazeArray[pos.y][pos.x] = 2;
		pos.x += 1;
		pushLSMapPosition(pStack, pos);
		dfs(mazeArray, pStack, startPos, endPos);
	}
	else if(check(mazeArray, pos.x, pos.y, DOWN)) //아래쪽
	{
		mazeArray[pos.y][pos.x] = 2;
		pos.y += 1;
		pushLSMapPosition(pStack, pos);
		dfs(mazeArray, pStack, startPos, endPos);
	}
	else if(check(mazeArray, pos.x, pos.y, LEFT)) //왼쪽
	{
		mazeArray[pos.y][pos.x] = 2;
		pos.x -= 1;
		pushLSMapPosition(pStack, pos);
		dfs(mazeArray, pStack, startPos, endPos);
	}
	else if(check(mazeArray, pos.x, pos.y, UP)) //위쪽
	{
		mazeArray[pos.y][pos.x] = 2;
		pos.y -= 1;
		pushLSMapPosition(pStack, pos);
		dfs(mazeArray, pStack, startPos, endPos);
	}
	else
	{
		StackNode* pop = popLS(pStack);
		if (pop->data.x == 0 && pop->data.y == 0)
		{
			printf("Can not Escape!!\n");
			free(pop);
			return ;
		}
		mazeArray[pos.y][pos.x] = 2;
		free(pop);
		dfs(mazeArray, pStack, startPos, endPos);
	}
}

void findPath(int mazeArray[HEIGHT][WIDTH],
		MapPosition startPos, MapPosition endPos, LinkedStack *pStack)
{
	pushLSMapPosition(pStack, startPos);
	dfs(mazeArray, pStack, startPos, endPos);
}
/////////////////////////////////////////


int mazeArray[HEIGHT][WIDTH] = {
	{0, 0, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 1, 0, 1, 1, 1, 0},
	{1, 1, 1, 0, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0},
	{1, 1, 1, 1, 1, 1, 1, 0},
};

int main()
{
	MapPosition startPos = {0, 0};
	MapPosition endPos = {7, 7};
	LinkedStack *pStack = createLinkedStack();
	read_maze(mazeArray, startPos, endPos);
	findPath(mazeArray, startPos, endPos, pStack);
	showPath(pStack, mazeArray, startPos, endPos);
	deleteLinkedStack(pStack);
	// system("leaks a.out");
}