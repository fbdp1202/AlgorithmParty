// baekjoon 1697 yechan
#include <cstdio>
#include <algorithm>
typedef unsigned int 	(u32);
typedef unsigned short 	(u16);
typedef unsigned char 	(u8);
typedef signed int 		(s32);
typedef signed short 	(s16);
typedef signed char 	(s8);

#define MAX_INPUT_SIZE 101

// -- Global variables

// Input
u32 g_N;
u32 input_buf[MAX_INPUT_SIZE][MAX_INPUT_SIZE];

// BFS - Queue
u32 Q_front_flag;
u32 Q_rear_flag;

u32 Queue[MAX_INPUT_SIZE*MAX_INPUT_SIZE];

#define ENQUEUE(x, Q_pos) 	do { Queue[Q_pos] = (u32)x; Q_pos++; } while(0);
#define DEQUEUE(x, Q_pos) 	do { x = Queue[Q_pos]; Q_pos++; } while(0);

// Result
u32 g_y;

static void SetInputBuffer( void )
{
	u32 i, j;
	scanf("%d", &g_N);
	for (i = 0; i < g_N; i++)
	{
		for (j = 0; j < g_N; j++)
		{
			scanf("%d", &input_buf[i][j]);
		}
	}
}

static void PrintInputBuffer( void )
{
	u32 i, j;
	for (i = 0; i < g_N; i++)
	{
		for (j = 0; j < g_N; j++)
		{
			printf("%d ", input_buf[i][j]);
		}
		printf("\n");
	}
}


static __inline void CheckUnvisitedNode( s32 pos_x )
{
	if(input_buf[g_y][pos_x] == 0){
		input_buf[g_y][pos_x] = 1;
		ENQUEUE(pos_x, Q_rear_flag);
	}
}

static void BFS( s32 pos_y )
{
	if (pos_y == g_y) return;
	u32 i;
	for (i = 0; i < g_N; i++){
		if(input_buf[pos_y][i] == 1){
			CheckUnvisitedNode( i );
		}
	}
}

static void FindEnqueue()
{
	u32 j;
	for (j = 0; j < g_N; j++)
	{
		if (input_buf[g_y][j])
		{
			ENQUEUE(j, Q_rear_flag);
		}
	}
}

s32 main(void)
{
	u32 bound_for_next_step = 0;
	u32 i;
	SetInputBuffer();
	for (i = 0; i < g_N; i++)
	{
		g_y = i;
		Q_rear_flag = Q_front_flag = 0;
		FindEnqueue();
		while (Q_front_flag < Q_rear_flag){
			u32 curr_pos_y;
			DEQUEUE(curr_pos_y, Q_front_flag);
			BFS(curr_pos_y);
		}
	}
	PrintInputBuffer();
}