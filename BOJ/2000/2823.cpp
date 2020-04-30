// baekjoon 2823 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
char data[10][11];
int R, C;

bool dfs(int x, int y) {
	
}

int main() {
	scanf("%d%d", &R, &C);
	for (int i=0; i<R; i++)
		scanf("%s", data[i]);
	for (int i=0; i<R; i++) {
		for (int j=0; j<C; j++) {
			if (data[i][j] == '.') {
				if (!dfs(i, j)) return !printf("0");
			}
		}
	}
	printf("1");
	return 0;
}