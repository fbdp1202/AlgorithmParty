// baekjoon 17232 yechan
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_N=101;
const int SIZE=1<<8;
const int size=SIZE/2;

struct query{
	int x, y, val;
	query():x(0),y(0),val(0){}
	query(int x, int y, int val):x(x),y(y),val(val){}
};

int N, M, T, K, a, b;
char board[MAX_N][MAX_N];

int arr[SIZE][SIZE];

void update(int x, int y, int val) {
	int i = y + size;
	int j = x + size;
	arr[i][j] = val;

	while (j > 0) {
		j /= 2;
		arr[i][j] = arr[i][j*2] + arr[i][j*2+1];
	}

	while (i > 0) {
		j = x + size;
		i /= 2;
		arr[i][j] = arr[i*2][j] + arr[i*2+1][j];
		while (j > 0) {
			j /= 2;
			arr[i][j] = arr[i][j*2] + arr[i][j*2+1];
		}
	}
}

int xquery(int y, int L, int R, int nodeNum, int nodeL, int nodeR) {
	if (R < nodeL || nodeR < L) return 0;
	if (L <= nodeL && nodeR <= R) return arr[y][nodeNum];
	int mid = (nodeL + nodeR) / 2;
	return xquery(y, L, R, nodeNum*2, nodeL, mid) + xquery(y, L, R, nodeNum*2+1, mid+1, nodeR);
}

int yquery(int L, int R, int x1, int x2, int nodeNum, int nodeL, int nodeR) {
	if (R < nodeL || nodeR < L) return 0;
	if (L <= nodeL && nodeR <= R) return xquery(nodeNum, x1, x2, 1, 0, size-1);
	int mid = (nodeL+nodeR)/2;
	return yquery(L, R, x1, x2, nodeNum*2, nodeL, mid) + yquery(L, R, x1, x2, nodeNum*2+1, mid+1, nodeR);
}

int yquery(int y1, int y2, int x1, int x2) {
	return yquery(y1, y2, x1, x2, 1, 0, size-1);
}

int main() {
	scanf("%d%d%d", &N, &M, &T);
	scanf("%d%d%d", &K, &a, &b);
	for (int i=0; i<N; i++) { // y = i
		scanf("%s", board[i]); // x = j
		for (int j=0; j<M; j++) {
			if (board[i][j] == '*') {
				update(j, i, 1); // update(x, y, val)
			}
		}
	}

	queue<query> q;
	while (T--) {
		for (int i=0; i<N; i++) {
			for (int j=0; j<M; j++) {
				int cur = (board[i][j] == '*');
				int life = yquery(i-K, i+K, j-K, j+K) - cur;
				if (cur) {
					if ((life < a) || (life > b)) {
						q.push(query(j, i, 0));
					}
				} else {
					if ((a < life) && (life <= b)) {
						q.push(query(j, i, 1));
					}
				}
			}
		}
		while (!q.empty()) {
			query tmp = q.front();
			board[tmp.y][tmp.x] = (tmp.val) ? '*' : '.';
			update(tmp.x, tmp.y, tmp.val);
			q.pop();
		}
	}
	for (int i=0; i<N; i++)
		printf("%s\n", board[i]);
	return 0;
}