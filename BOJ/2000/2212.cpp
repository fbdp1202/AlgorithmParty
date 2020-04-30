// baekjoon 2212 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=10001;

int N, K;
int data[MAX_N];

int main() {
	scanf("%d%d", &N, &K);
	priority_queue<int, vector<int>, greater<int>> PQ;
	for (int i=0; i<N; i++)
		scanf("%d", &data[i]);

	sort(data, data+N);
	for (int i=1; i<N; i++)
		PQ.push(data[i] - data[i-1]);

	int ret = 0;
	while (N > K) {
		ret += PQ.top();
		PQ.pop();
		N--;
	}
	printf("%d\n", ret);
	return 0;
}