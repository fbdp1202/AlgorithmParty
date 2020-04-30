// baekjoon 7569 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 100

const int dx[6] = {0, 0, 0, 0, 1, -1};
const int dy[6] = {0, 0, 1, -1, 0, 0};
const int dz[6] = {1, -1, 0, 0, 0, 0};

typedef struct _TAG_POSITION {
	int pos_x, pos_y, pos_z;
}__POS;

int Q_rear_flag, Q_front_flag;

__POS Queue[MAX_N*MAX_N*MAX_N];
#define ENQUEUE(x, y, z, Qos) \
		do { Queue[Qos].pos_x=x; Queue[Qos].pos_y=y; Queue[Qos].pos_z=z; Qos++; } while(0)
#define DEQUEUE(x, y, z, Qos) \
		do { x=Queue[Qos].pos_x; y=Queue[Qos].pos_y; z=Queue[Qos].pos_z; Qos++; } while(0)

int M, N, H, cnt, opt_num, box[MAX_N][MAX_N][MAX_N];
bool visited[MAX_N][MAX_N][MAX_N];

static void SetInputBuffer() {
	for (int i=0; i<H; i++){
		for (int j=0; j<N; j++){
			for (int k=0; k<M; k++){
				scanf("%d", &box[i][j][k]);

				if (box[i][j][k] == 1)
					ENQUEUE(k, j, i, Q_rear_flag);

				if (box[i][j][k])
					visited[i][j][k] = true, cnt++;
			}
		}
	}
}

static void CheckUnvisited(int x, int y, int z) {
	if ( (0 <= x && x < M) && (0 <= y && y < N) && (0 <= z && z < H) &&
		 !visited[z][y][x] && (box[z][y][x] != -1) ) {
		visited[z][y][x] = true; cnt++;
		ENQUEUE(x, y, z, Q_rear_flag);
	}
}

static void BFS(int x, int y, int z) {
	for (int d=0; d<6; d++) {
		int nx = x + dx[d], ny = y + dy[d], nz = z + dz[d];
		CheckUnvisited(nx, ny, nz);
	}
}

int main() {
	scanf("%d %d %d", &M, &N, &H);
	int box_size = M*N*H;
	SetInputBuffer();
	int Q_block_next_step = Q_rear_flag;

	while (Q_front_flag != Q_rear_flag) {
		int curr_pos_x=0, curr_pos_y=0, curr_pos_z=0;
		DEQUEUE(curr_pos_x, curr_pos_y, curr_pos_z, Q_front_flag);
		BFS(curr_pos_x, curr_pos_y, curr_pos_z);

		if (Q_front_flag == Q_block_next_step) {
			Q_block_next_step = Q_rear_flag;
			opt_num++;
		}
	}

	if (cnt == box_size) printf("%d", opt_num-1);
	else printf("-1");
	
	return 0;
}
