// baekjoon 1039 yechan
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int M;

int getPosValue(int n, int p) {
	while (p--) n/=10;
	return n%10;
}

int swapValue(int n, int a, int b) {
	char S[8];
	sprintf(S, "%d", n);
	swap(S[M-a-1], S[M-b-1]);
	sscanf(S, "%d", &n);
	return n;
}

int main() {
	int N, K, result = -1;
	scanf("%d%d", &N, &K);

	queue<int> q;
	q.push(N);

	do {
		N/=10;
		M++;
	}while(N);

	for (int k=0; k<K; k++) {
		int qSize = q.size();
		bool visited[1000001] = {0};
		while (qSize--) {
			int curr = q.front(); q.pop();

			for (int i=0; i<M-1; i++) {
				for (int j=i+1; j<M; j++) {
					if (j==M-1 && !getPosValue(curr, i)) continue;
					int nx = swapValue(curr, i, j);
					if (!visited[nx]) {
						visited[nx] = true;
						q.push(nx);
					}
				}
			}
		}
	}

	while (!q.empty()) {
		result = max(result, q.front());
		q.pop();
	}

	printf("%d\n", result);
	return 0;
}