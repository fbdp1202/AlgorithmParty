#include <bits/stdc++.h>
using namespace std;

const int MAX_N=10001;

int N, inNum[MAX_N], t[MAX_N], score[MAX_N];
vector<int> adj[MAX_N];

int main() {
	scanf("%d", &N);

	for (int i=0; i<N; i++) {
		scanf("%d", &t[i]);
		int num; scanf("%d", &num);
		while (num--) {
			int x; scanf("%d", &x);
			adj[x-1].push_back(i);
			inNum[i]++;
		}
	}

	queue<int> Q;
	for (int i=0; i<N; i++)
		if (inNum[i] == 0)
			Q.push(i);

	int result = 0;
	while (!Q.empty()) {
		int curr = Q.front(); Q.pop();
		result = max(result, score[curr] + t[curr]);
		for (int next: adj[curr]) {
			inNum[next]--;
			score[next] = max(score[next], score[curr] + t[curr]);
			if (inNum[next] == 0) {
				Q.push(next);
			}
		}
	}
	printf("%d\n", result);
	return 0;
}