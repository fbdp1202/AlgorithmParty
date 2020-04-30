// baekjoon 16288 yechan
#include <cstdio>
#include <queue>
#include <vector>
#include <utility>
#include <functinoal>
#include <algorithm>
using namespace std;

const int MAX_N=101;

int N, K;
int seq[MAX_N];

int main()
{
	scanf("%d%d", &N, &K);
	for (int i=0; i<N; i++)
		scanf("%d", &seq[i]);

	priority_queue<int, vector<int>, greater<int> > pq;
	int pos = 0;
	int pqSize = 0;
	while (pos < N) {
		while (!pq.empty() && pq.top() < seq[pos])
			pq.pop(), pqSize--;
		pq.push(seq[pos++]);
		pqSize++;
		if (pqSize > K) return !printf("NO\n");
	}
	printf("YES\n");
	return 0;
}