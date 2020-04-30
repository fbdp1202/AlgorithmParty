// baekjoon 1743 yechan
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX_N 101

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

typedef pair<int,int> P;

int N, M, K, R, C, result;

bool matrix[MAX_N][MAX_N];

bool findposition()
{
	for (int i=1; i<=N; i++){
		for (int j=1; j<=M; j++){
			if (matrix[i][j]){
				R=i, C=j; return true;
			}
		}
	}

	return false;
}

int main()
{
	scanf("%d%d%d", &N, &M, &K);
	for (int i=0; i<K; i++) {
		scanf("%d%d", &R, &C);
		matrix[R][C]=true;
	}

	while(findposition()) {
		queue<P> q;
		q.push(P(R, C));
		int numfood=0;
		while (!q.empty()) {
			P pos = q.front(); q.pop();
			int x = pos.first, y = pos.second;
			if (matrix[x][y]){
				matrix[x][y]=false;
				numfood++;
				for (int d=0; d<4; d++) {
					int nx = x+dx[d];
					int ny = y+dy[d];
					q.push(P(nx, ny));
				}
			}
		}
		result = max(result, numfood);
	}
	printf("%d\n", result);
	return 0;
}