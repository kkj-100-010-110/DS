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

// ����ü�� �ѹ��� ���°� ~ 
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
	{0, -1},		// �������� �̵�.
	{1, 0},			// ���������� �̵�.
	{0, 1},			// �Ʒ������� �̵�.
	{-1, 0}			// �������� �̵�.
};


typedef struct MapPositionType
{
	int x;				// ���� ��ġ x��ǥ.
	int y;				// ���� ��ġ y��ǥ.
	int direction;		// ���� ��ġ�� �̵� ����.
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