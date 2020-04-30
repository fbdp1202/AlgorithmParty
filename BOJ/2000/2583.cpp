//baekjoon 2583 yechan
#include <cstdio>
#include <algorithm>

using namespace std;

typedef unsigned int	(u32);
typedef unsigned short 	(u16);
typedef unsigned char 	(u8);
typedef signed int		(s32);
typedef signed short	(s16);
typedef signed char 	(s8);

#define MAX_INPUT_SIZE 101

// input
u32 g_M, g_N, g_K;
u32 input_buf[MAX_INPUT_SIZE][MAX_INPUT_SIZE];

// Queue
typedef struct _tag_POSITION{
	u32 pos_x;
	u32 pos_y;
}__POS;

u32 Q_rear_flag;

u32 Q_front_flag;

__POS Queue[MAX_INPUT_SIZE*MAX_INPUT_SIZE];

#define ENQUEUE(x, y, Q_pos) 	do { Queue[Q_pos].pos_x = (u32)x; Queue[Q_pos].pos_y = (u32)y; Q_pos++; } while(0)
#define DEQUEUE(x, y, Q_pos) 	do { x = Queue[Q_pos].pos_x; y = Queue[Q_pos].pos_y; Q_pos++; } while(0)

// OUTPUT
u32 g_num;
u32 g_opt_length;
u32 g_len_arr[MAX_INPUT_SIZE*MAX_INPUT_SIZE];
u32 g_y;

static void fillRectangle(int x1, int y1, int x2, int y2)
{
	u32 i, j;
	for (i = y1; i < y2; i++ )
	{
		for (j = x1; j < x2; j++)
		{
			input_buf[i][j] = 1;
		}
	}
}

static void SetInputBuffer( void )
{
	u32 i;
	u32 x1, y1, x2, y2;
	scanf("%d %d %d", &g_M, &g_N, &g_K);
	for (int i = 0; i < g_K; i++)
	{
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		fillRectangle(x1, y1, x2, y2);
	}
}

static __inline void CheckUnvisitedNode(int curr_pos_x, int curr_pos_y)
{
	if (input_buf[curr_pos_y][curr_pos_x] == 0)
	{
		input_buf[curr_pos_y][curr_pos_x] = 1;
		ENQUEUE(curr_pos_x, curr_pos_y, Q_rear_flag);
		g_opt_length++;
	}
}

static void BFS(int curr_pos_x, int curr_pos_y)
{
	if (curr_pos_x + 1 < g_N) 	CheckUnvisitedNode(curr_pos_x + 1, curr_pos_y);
	if (curr_pos_x - 1 >= 0) 	CheckUnvisitedNode(curr_pos_x - 1, curr_pos_y);
	if (curr_pos_y + 1 < g_M) 	CheckUnvisitedNode(curr_pos_x, curr_pos_y + 1);
	if (curr_pos_y - 1 >= 0) 	CheckUnvisitedNode(curr_pos_x, curr_pos_y - 1);
}

static void newEnqueue()
{
	u32 i, j;
	for (i = g_y; i < g_M; i++)
	{
		for (j = 0; j < g_N; j++)
		{
			if(input_buf[i][j] == 0)
			{
				ENQUEUE(j, i, Q_rear_flag);
				input_buf[i][j] = 1;
				g_opt_length = 1;
				g_num++;
				break;
			}
		}
		if(j != g_N) break;
	}
	g_y = i;
}

int main()
{
	u32 bound_for_next_step = 0;
	SetInputBuffer();

	newEnqueue();

	bound_for_next_step = Q_rear_flag;

	while ( Q_front_flag < Q_rear_flag )
	{
		u32 curr_pos_x, curr_pos_y;
		
		DEQUEUE(curr_pos_x, curr_pos_y, Q_front_flag);
		BFS(curr_pos_x, curr_pos_y);

		if ( Q_front_flag == bound_for_next_step )
		{
			bound_for_next_step = Q_rear_flag;
		}

		if ( Q_front_flag == Q_rear_flag )
		{
			g_len_arr[g_num] = g_opt_length;
			newEnqueue();
			bound_for_next_step = Q_rear_flag;
		}
	}

	u32 i;
	printf("%d\n", g_num);

	if ( g_num != 0 )
	{
		sort(g_len_arr+1, g_len_arr+g_num+1);
		for ( i = 1; i <= g_num; i++ )
		{
			printf("%d ", g_len_arr[i]);
		}
	}
}