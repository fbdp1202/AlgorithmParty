// baekjoon 7562 yechan
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX_I 300
const int dx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
const int dy[8] = {2, -2, 1, -1, 2, -2, 1, -1};

typedef struct _TAG_POSITION{
	int pos_x, pos_y;
}__POS;

__POS Queue[MAX_I*MAX_I];
#define ENQUEUE(x, y, Qos) \
		do { Queue[Qos].pos_x=x; Queue[Qos].pos_y=y; Qos++; } while(0)
#define DEQUEUE(x, y, Qos) \
		do { x=Queue[Qos].pos_x; y=Queue[Qos].pos_y; Qos++; } while(0)

int T, I, sx, sy, ex, ey, visited[MAX_I][MAX_I];
int Q_rear_flag, Q_front_flag, Q_block_next_step;

static void CheckUnvisited(int nx, int ny) {
	if ( !visited[ny][nx] && 
		 !(nx < 0 || ny < 0 || nx >= I || ny >= I )) {
		visited[ny][nx]=1;
		ENQUEUE(nx, ny, Q_rear_flag);
	}
}

static void BFS(int x, int y) {
	for (int d=0; d<8; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];
		CheckUnvisited(nx, ny);
	}
}

int main() {
	scanf("%d", &T);
	while (T--) {
		Q_rear_flag = 0, Q_front_flag=0, Q_block_next_step = 0;
		scanf("%d", &I);
		scanf("%d %d", &sx, &sy);
		scanf("%d %d", &ex, &ey);

		memset(visited, 0, sizeof(visited));

		ENQUEUE(sx, sy, Q_rear_flag);
		visited[sy][sx]=1;

		Q_block_next_step = Q_rear_flag;
		int result = 0;
		while(Q_rear_flag != Q_front_flag) {
			int curr_pos_x, curr_pos_y;
			DEQUEUE(curr_pos_x, curr_pos_y, Q_front_flag);
			if(curr_pos_y == ey && curr_pos_x == ex) {
				break;
			}
			BFS(curr_pos_x, curr_pos_y);
			if(Q_front_flag == Q_block_next_step) {
				Q_block_next_step = Q_rear_flag;
				result++;
			}
		}
		printf("%d\n", result);
	}
	return 0;
}