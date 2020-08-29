#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;
const int MAX_C=2001;
const int MAX_N=21;
const int MAX_INF=1e9;

int C, N;
int dp[MAX_C];
P cost[MAX_N];
bool inQueue[MAX_C];

int BFS() {
	dp[0] = 0;
	queue<int> q;
	q.push(0);
	int ret = MAX_INF;
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		inQueue[curr] = false;
		for (int i=0; i<N; i++) {
			int next_P = cost[i].second + curr;
			int next_C = cost[i].first + dp[curr];
			if (C <= next_P) ret = min(ret, next_C);
			else {
				if (dp[next_P] > next_C) {
					dp[next_P] = next_C;
					if (!inQueue[next_P]) {
						inQueue[next_P] = true;
						q.push(next_P);
					}

				}
			}
		}

	}
	return ret;
}

int main() {
	fill(dp, dp+MAX_C, MAX_INF);
	scanf("%d%d", &C, &N);
	for (int i=0; i<N; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		cost[i] = P(x, y);
	}
	printf("%d\n", BFS());
	return 0;
}