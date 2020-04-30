// baekjoon 10472 yechan
#include <bits/stdc++.h>
using namespace std;

const int SIZE=10;
const int DP_SIZE=(1<<SIZE) + 1;
const int MAX_INF=1e9;

int T;
bool visited[DP_SIZE];
char c_input[3][4];
int sw[9];

int bfs(int start) {
	queue<int> q;
	q.push(start);
	memset(visited, 0, sizeof(visited));
	int ret = 0;
	while (!q.empty()) {
		int qSize = q.size();
		while (qSize--) {
			int curr = q.front();
			q.pop();
			visited[curr] = true;
			if (curr == 0) return ret;
			for (int i=0; i<9; i++) {
				int next = curr ^ sw[i];
				if (visited[next]) continue;
				q.push(next);
			}
		}
		ret++;
	}
	return -1;
}

int main() {
	sw[0] = (1<<0)+(1<<1)+(1<<3);				// 0 1 3
	sw[1] = (1<<0)+(1<<1)+(1<<2)+(1<<4); 		// 0 1 2 4
	sw[2] = (1<<1)+(1<<2)+(1<<5);				// 1 2 5
	sw[3] = (1<<0)+(1<<3)+(1<<4)+(1<<6);		// 0 3 4 6
	sw[4] = (1<<1)+(1<<3)+(1<<4)+(1<<5)+(1<<7);	// 1 3 4 5 7
	sw[5] = (1<<2)+(1<<4)+(1<<5)+(1<<8);		// 2 4 5 8
	sw[6] = (1<<3)+(1<<6)+(1<<7);				// 3 6 7
	sw[7] = (1<<4)+(1<<6)+(1<<7)+(1<<8); 		// 4 6 7 8
	sw[8] = (1<<5)+(1<<7)+(1<<8);				// 5 7 8

	scanf("%d", &T);
	while (T--) {
		int N = 0;
		for (int i=0; i<3; i++) {
			scanf("%s", c_input[i]);
			for (int j=0; j<3; j++)
				N += ((c_input[i][j] == '*') ? 1 : 0) * (1<<(i*3+j));
		}
		printf("%d\n", bfs(N));
	}
	return 0;
}