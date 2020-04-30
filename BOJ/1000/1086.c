#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1001

const int dir[9][2] = {{-1,-1}, {-1,0}, {-1,1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

struct Number{
	int x, y, num;
};

struct Pos{
	int x, y;
};

int N, M;
int input[MAX_N][MAX_N];
int board[MAX_N][MAX_N];
Number number[MAX_N*MAX_N];
int visited[MAX_N*MAX_N];
Pos multi[MAX_N*MAX_N];

void makeNumber(int x, int y, int num, int idx) {
	number[idx].x = x;
	number[idx].y = y;
	number[idx].num = num;
}

void dfs(int here, int limit) {
	if (here == limit) {
		for (int i=0; i<N; i++) {
			for (int j=0; j<M; j++) {
				printf("%d ", board[i][j]);
			}
			puts("");
		}
		puts("");
		return;
	}
	int x = multi[here].x;
	int y = multi[here].y;

	board[x][y] = 0;
	dfs(here+1, limit);

	board[x][y] = 1;
	dfs(here+1, limit);
}

int main()
{
	int num = 0;
	scanf("%d%d", &N, &M);
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			char c;
			scanf(" %c", &c);
			if (c == '?') input[i][j] = -1;
			else {
				input[i][j] = c - '0';
				makeNumber(i, j, input[i][j], num);
				num++;
			}
		}
	}

	for (int i=0; i<N; i++)
		for (int j=0; j<M; j++)
			board[i][j] = -1;

	int impossible = 0;
	for (int i=0; i<num; i++) {
		int change = 0;
		for (int j=0; j<num; j++) {
			if (visited[j]) continue;

			int c = number[j].num;

			int ans[3] = {0};
			for (int d=0; d<9; d++) {
				int x = number[j].x + dir[d][0];
				int y = number[j].y + dir[d][1];
				if (x < 0 || x >= N || y < 0 || y >= M) continue;

				if (board[x][y] == -1) ans[0]++;
				if (board[x][y] == 0) ans[1]++;
				if (board[x][y] == 1) ans[2]++;
			}
			// impossible condition
			if (ans[2] > c) impossible = 1;
			if (ans[2] + ans[0] < c) impossible = 1;
			if (impossible) break;

			if (ans[0] + ans[2] == c) {
				for (int d=0; d<9; d++) {
					int x = number[j].x + dir[d][0];
					int y = number[j].y + dir[d][1];
					if (x < 0 || x >= N || y < 0 || y >= M) continue;
					if (board[x][y] == -1) {
						board[x][y] = 1;
					}
				}
				visited[j]=1;
				change=1;
			} else if (ans[2] == c) {
				for (int d=0; d<9; d++) {
					int x = number[j].x + dir[d][0];
					int y = number[j].y + dir[d][1];
					if (x < 0 || x >= N || y < 0 || y >= M) continue;
					if (board[x][y] == -1) {
						board[x][y] = 0;
					}
				}
				visited[j]=1;
				change=1;
			}
		}
		if (impossible) break;
		if (!change) break;
	}

	if (impossible) {
		puts("IMPOSSIBLE\n");
	} else {
		int multiSol = 0;
		for (int i=0; i<N; i++) {
			for (int j=0; j<M; j++) {
				if (board[i][j] == -1) {
					multi[multiSol].x = i;
					multi[multiSol].y = j;
					multiSol++;
				}
			}
		}
		if (multiSol) puts("MULTI SOL");
		else puts("SINGLE SOL");

		if (!multiSol) {
			for (int i=0; i<N; i++) {
				for (int j=0; j<M; j++) {
					printf("%d ", board[i][j]);
				}
				puts("");
			}
		} else {
			printf("the number of Solution is : %lld\n", (1LL<<multiSol));
			dfs(0, multiSol);
		}
	}

	return 0;
}