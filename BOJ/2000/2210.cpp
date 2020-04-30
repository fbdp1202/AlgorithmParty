// baekjoon 2210 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int result, board[5][5], num;
bool visited[1000000];

void Tracking(int x, int y, int c) {
	num += board[y][x];
	if(c == 6) {
		if(!visited[num])
			visited[num] = true, result++;
	}
	else {
		for (int d=0; d<4; d++) {
			int nx = x + dx[d], ny = y + dy[d];
			if (0 <= nx && nx <= 4 && 0 <= ny && ny <= 4) {
				num *= 10;
				Tracking(nx, ny, c+1);
				num /= 10;
			}
		}
	}
}

int main() {
	for (int i=0; i<5; i++)
		for (int j=0; j<5; j++)
			scanf("%d", &board[i][j]);

	for (int i=0; i<5; i++)
		for (int j=0; j<5; j++)
			num=0, Tracking(j, i, 1);

	return !printf("%d", result);
}