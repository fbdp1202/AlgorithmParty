// baekjoon 5533 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N, data[200][3], visited[101];

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		for (int j=0; j<3; j++)
			scanf(" %d", &data[i][j]);

	for (int i=0; i<3; i++) {
		fill(visited, visited+101, -1);
		for (int j=0; j<N; j++) {
			if (visited[data[j][i]] == -1) {
				visited[data[j][i]] = j;
			}
			else {
				data[visited[data[j][i]]][i]=0;
				data[j][i]=0;
			}
		}
	}

	for (int i=0; i<N; i++) {
		int tmp = 0;
		for (int j=0; j<3; j++)
			tmp += data[i][j];
		printf("%d\n", tmp);
	}
	return 0;
}