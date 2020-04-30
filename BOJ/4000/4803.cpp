// baekjoon 4803 yechan
#include <cstdio>
#include <cstring>
using namespace std;
#define MAX_N 500
bool matrix[MAX_N][MAX_N];
int visited[MAX_N];
int N, M, u, v, x, result;

int findStart() {
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			if (matrix[i][j]){
				return i;
			}
		}
	}
	return -1;
}

bool dfs(int n) {
	bool ret = false;

	visited[n]=true;
	for (int i=0; i<N; i++) {
		if (matrix[n][i]) {
			if (visited[i]) ret = true;
			matrix[n][i] = matrix[i][n] = false;
			ret |= dfs(i);
		}
	}
	return ret;
}

int main() {
	int cnt = 1;
	while (scanf("%d%d", &N, &M) && (N || M)) {
		memset(matrix, 0, sizeof(matrix));
		memset(visited, 0, sizeof(visited));
		result = 0;
		for (int i=0; i<M; i++) {
			scanf("%d%d", &u, &v);
			matrix[u-1][v-1]=true;
			matrix[v-1][u-1]=true;
		}

		while (1) {
			x = findStart();
			if (x == -1) break;
			if (!dfs(x))
				result++;
		}
		for (int i=0; i<N; i++)
			if (!visited[i]) result++;
		printf("Case %d: ", cnt);
		if (result == 0) printf("No trees.\n");
		else if (result == 1) printf("There is one tree.\n");
		else printf("A forest of %d trees.\n", result);
		cnt++;
	}
	return 0;
}