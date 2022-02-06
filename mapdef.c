// #ifndef _MAP_DEF_
// #define _MAP_DEF_

// #define WIDTH 8
// #define HEIGHT 8
// #define MAZE_SIZE 8

// #define NUM_DIRECTIONS 4
// #define NOT_VISIT '0'
// #define WALL '1'  
// #define VISIT '2' 
// #define BACKTRACKED '3'

// // 구조체로 한번에 묶는거 ~ 
// char maze[HEIGHT][WIDTH] = {
// {'m', '0', '0', '1', '0', '1', '1', '0'},
// {'0', '1', '0', '0', '0', '0', '0', '1'},
// {'0', '1', '1', '1', '1', '1', '1', '1'},
// {'0', '0', '0', '0', '0', '1', '0', '1'},
// {'1', '1', '0', '1', '0', '0', '0', '1'},
// {'1', '0', '0', '0', '1', '1', '1', '1'},
// {'1', '0', '1', '0', '0', '1', '1', '1'},
// {'1', '1', '1', '1', '0', '0', '0', 'x'}};


// // offset: x, y
// static int DIRECTION_OFFSETS[NUM_DIRECTIONS][2] = {
// 	{0, -1},		// 위쪽으로 이동.
// 	{1, 0},			// 오른쪽으로 이동.
// 	{0, 1},			// 아래쪽으로 이동.
// 	{-1, 0}			// 왼쪽으로 이동.
// };


// typedef struct MapPositionType
// {
// 	int x;				// 현재 위치 x좌표.
// 	int y;				// 현재 위치 y좌표.
// 	int direction;		// 다음 위치로 이동 방향.
// } MapPosition;

// void read_maze();
// void print_maze();
// //bool movable(POS pos, int dir);

// #endif

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arraystack.h"

#include "mapdef.h"
void read_maze()
{
    int i;
    int j;
    // 시작점 탐색 
    MapPosition m;

    for(i=0;i<HEIGHT;i++) 
    { 
        for(j=0;j<WIDTH;j++) 
        { 
            if(maze[i][j]=='m') 
            { 
                m.x=i; 
                m.y=j; 
            } 
        } 
    } 
    printf("미로 \n"); 
    for(int i=0; i<HEIGHT; i++)
    { 
        for(int j=0; j<MAZE_SIZE; j++)
        { 
            if(maze[i][j]=='0')
            { 
                printf("◻︎"); 
            }
            else if(maze[i][j]=='1')
            { 
                printf("◼︎"); 
            }
            else 
            { 
                printf("%c",maze[i][j]); 
            } 
        } 
        printf("\n"); 
    } 
    printf("\n이동 경로\n"); 
    printf("시작 (%d,%d) -> ",m.x,m.y); 
}

bool movable(Position pos, int dir)
{
    if(pos.x < 0 || pos.y < 0 || pos.x > MAZE_SIZE || pos.y > MAZE_SIZE) 
        return 0; 
    if(maze[pos.x][pos.y] != WALL && maze[pos.x][pos.y] != VISIT) 
    {
        return 0; 
    }
}

int main()
{
    read_maze();

    ArrayStack* s = createArrayStack(100);
    // Position 대신 정수들을 저장하는 스택을 사용
    
    Position cur;
    cur.x = 0;
    cur.y = 0;

    int init_dir = 0; // 어떤 위치에 도착했을 때 처음으로 시도해 볼 이동 방향
    char s1[2];
    while (1) 
    {
        maze[cur.x][cur.y] = VISIT;
        if (cur.x == n - 1 && cur.y == n - 1) 
        {
            printf("Found the path.\n");
            break;
        }
        bool forwarded = false;
        for (int dir = init_dir; dir < 4; dir++) // 0:N, 1:E, 2:S, 3:W
        {
            if (movable(cur, dir)) 
            {
                ArrayStackNode dir1 = dir;
                //sprintf(s1, "%d",dir1);
                pushAS(s, dir1); 
                // 스택에는 현재 위치 대신 이동하는 방향을 push
                cur = move_to(cur, dir);
                forwarded = true;
                init_dir = 0; // 처음 방문하는 위치에서는 항상 0번 방향부터 시도
                break;
            }
        }
        if (!forwarded) 
        {
            maze[cur.x][cur.y] = BACKTRACKED;
            if (isArrayStackEmpty(s)) 
            {
                printf("No path exists.\n");
                break;
            }
            int d = (int)popAS(s)->data;
            cur = move_to(cur, (d + 2) % 4); // 이전 위치에서 지금 위치에 올 때 d방향으로 이동했었다면 되돌아 가려면 (d+2)%4번 방향으로 이동하면 된다.

            init_dir = d + 1; //되돌아 간 위치에서는 d + 1번 방향부터 시도해보면 된다.
        }
    }
    
}

/*
/// pos.h

#ifndef POS_H
#define POS_H

typedef struct pos {
    int x;
    int y;
} Position;

Position move_to(Position pos, int dir);

#endif


////
*/

Position move_to(Position pos, int dir)
{
    Position next;
    next.x = pos.x + offset[dir][0];
    next.y = pos.y + offset[dir][1];
    return next;
}
