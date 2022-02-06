#ifndef _MAP_DEF_
#define _MAP_DEF_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arraystack.h"

#define WIDTH 8
#define HEIGHT 8
#define MAZE_SIZE 8

#define NUM_DIRECTIONS 4
#define NOT_VISIT '0'
#define WALL '1'  
#define VISIT '2' 
#define BACKTRACKED '3'

// 구조체로 한번에 묶는거 ~ 
char maze[HEIGHT][WIDTH] = {
{'m', '0', '0', '1', '0', '1', '1', '0'},
{'0', '1', '0', '0', '0', '0', '0', '1'},
{'0', '1', '1', '1', '1', '1', '1', '1'},
{'0', '0', '0', '0', '0', '1', '0', '1'},
{'1', '1', '0', '1', '0', '0', '0', '1'},
{'1', '0', '0', '0', '1', '1', '1', '1'},
{'1', '0', '1', '0', '0', '1', '1', '1'},
{'1', '1', '1', '1', '0', '0', '0', 'x'}};
int n;

// offset: x, y
static int DIRECTION_OFFSETS[NUM_DIRECTIONS][2] = {
	{0, -1},		// 위쪽으로 이동.
	{1, 0},			// 오른쪽으로 이동.
	{0, 1},			// 아래쪽으로 이동.
	{-1, 0}			// 왼쪽으로 이동.
};


typedef struct MapPositionType
{
	int x;				// 현재 위치 x좌표.
	int y;				// 현재 위치 y좌표.
	int direction;		// 다음 위치로 이동 방향.
} MapPosition;

typedef struct pos {
    int x;
    int y;
} Position;

int offset[4][2] = { {-1, 0},
                     {0, 1},
                     {1, 0},
                     {0, -1} };

Position move_to(Position pos, int dir);
void read_maze();
bool movable(Position pos, int dir);

#endif