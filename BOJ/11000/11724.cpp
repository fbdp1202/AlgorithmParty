///////////////////////////
// baekjoon 11724 yechan //
///////////////////////////
#include <cstdio>
#include <algorithm>

using namespace std;

typedef unsigned int	(u32);
typedef unsigned short 	(u16);
typedef unsigned char 	(u8);
typedef signed int		(s32);
typedef signed short	(s16);
typedef signed char 	(s8);

#define MAX_INPUT_SIZE 1001

// input
u32 input_buf[MAX_INPUT_SIZE][MAX_INPUT_SIZE];
u32 g_N, g_M;

// Queue
u32 Q_rear_flag;

u32 Q_front_flag;

u32 Queue[MAX_INPUT_SIZE*MAX_INPUT_SIZE];

#define ENQUEUE(x, Q_pos) 	do { Queue[Q_pos] = (u32)x; Q_pos++; } while(0)
#define DEQUEUE(x, Q_pos) 	do { x = Queue[Q_pos]; Q_pos++; } while(0)

// visit buf
u32 visit_buf[MAX_INPUT_SIZE];

// OUTPUT
u32 g_num;
u32 g_y;

static void SetInputBuffer( void )
{
	u32 i;
	u32 u, v;
	scanf("%d %d", &g_N, &g_M);
	for ( i = 0; i < g_M; i++ )
	{
		scanf("%d %d", &u, &v);
		input_buf[u-1][v-1] = 1;
		input_buf[v-1][u-1] = 1;
	}
}

static void PrintInputBuffer( void )
{
	u32 i, j;
	for ( i = 0; i < g_N; i++ )
	{
		for ( j = 0; j < g_N; j++ )
		{
			printf("%d ", input_buf[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

static __inline void CheckUnvisitedNode(int curr_pos_x, int curr_pos_y)
{
	if (input_buf[curr_pos_y][curr_pos_x] == 1)
	{
		input_buf[curr_pos_y][curr_pos_x] = 0;
		ENQUEUE(curr_pos_x, Q_rear_flag);
	}
}

static void BFS(int curr_pos_y)
{
	u32 i;
	visit_buf[curr_pos_y]=1;
	for ( i = 0; i < g_N; i++ )
	{
		CheckUnvisitedNode(i, curr_pos_y);
	}
}

static void newEnqueue()
{
	u32 i, j;
	for (i = g_y; i < g_N; i++)
	{
		for (j = 0; j < g_N; j++)
		{
			if(input_buf[i][j] == 1)
			{
				g_num++;
				break;
			}
		}
		if(j != g_N) break;
		else if(!visit_buf[i]){
			visit_buf[i] = 1;
			g_num++;
		}
	}
	g_y = i;
	if(g_y != g_N)
	{
		BFS(g_y);
	}
}

int main()
{
	u32 i;
	SetInputBuffer();

	newEnqueue();

	while ( Q_front_flag < Q_rear_flag )
	{
		u32 curr_pos_y;
		
		DEQUEUE(curr_pos_y, Q_front_flag);
		BFS(curr_pos_y);

		if ( Q_front_flag == Q_rear_flag ){
			Q_front_flag = 0;
			Q_rear_flag = 0;
			newEnqueue();
		}
	}

	printf("%d", g_num);
}