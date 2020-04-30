// baekjoon 1697 yechan
#include <cstdio>
#include <algorithm>
typedef unsigned int 	(u32);
typedef unsigned short 	(u16);
typedef unsigned char 	(u8);
typedef signed int 		(s32);
typedef signed short 	(s16);
typedef signed char 	(s8);

#define MAX_INPUT_SIZE 100001

// -- Global variables

// Input
u32 g_N, g_K;

// BFS - Queue
u32 Q_front_flag;
u32 Q_rear_flag;

u32 Queue[MAX_INPUT_SIZE];

#define ENQUEUE(x, Q_pos) 	do { Queue[Q_pos] = (u32)x; Q_pos++; } while(0);
#define DEQUEUE(x, Q_pos) 	do { x = Queue[Q_pos]; Q_pos++; } while(0);

// BFS - visit buf
u8 visit_buf[MAX_INPUT_SIZE];

// Result
u32 g_opt_count;

static void SetInputBuffer( void )
{
	scanf("%d %d", &g_N, &g_K);
}

static __inline void CheckUnvisitedNode( s32 pos_x )
{
	if(visit_buf[pos_x] == 0)
	{
		ENQUEUE(pos_x, Q_rear_flag);
		visit_buf[pos_x] = 1;
	}
}

static void BFS( s32 pos_x )
{
	if(pos_x + 1 < MAX_INPUT_SIZE) 	CheckUnvisitedNode(pos_x + 1);
	if(pos_x - 1 >= 0) 				CheckUnvisitedNode(pos_x - 1);
	if(pos_x * 2 < MAX_INPUT_SIZE) 	CheckUnvisitedNode(pos_x * 2);
}

s32 main(void)
{
	u32 bound_for_next_step = 0;
	SetInputBuffer();
	if(g_K <= g_N){
		g_opt_count = g_N-g_K;
		printf("%d", g_opt_count);
		return 0;
	}

	ENQUEUE(g_N, Q_rear_flag);
	visit_buf[Q_rear_flag] = g_N;

	bound_for_next_step = Q_rear_flag;

	do {
		u32 curr_pos_x;
		DEQUEUE(curr_pos_x, Q_front_flag);
		BFS(curr_pos_x);

		if((curr_pos_x == (g_K)))
		{
			break;
		}

		if(Q_front_flag == bound_for_next_step)
		{
			bound_for_next_step = Q_rear_flag;
			g_opt_count++;
		}
	} while (Q_front_flag < Q_rear_flag);

	printf("%d", g_opt_count);
}