// baekjoon 9576 yechan
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
typedef pair<int, int> P;

int T, N, M, a, b;

int main() {
	scanf("%d",&T);
	while (T--) {
		scanf("%d%d", &N, &M);
		priority_queue <P, vector<P>, greater<P> > PQ;
		priority_queue<int, vector<int>, greater<int> > q;
		for (int i=0; i<M; i++) {
			scanf("%d%d", &a, &b);
			PQ.push(P(a, b));
		}

		int curr = 1;
		int result = 0;

		while (!PQ.empty() || !q.empty()) {
			while (!PQ.empty() && PQ.top().first == curr) 
				q.push(PQ.top().second), PQ.pop();

			while (!q.empty() && q.top() < curr) 
				q.pop();

			if (!q.empty()) 
				q.pop(), result++;

			curr++;
		}
		printf("%d\n", result);
	}
	return 0;
}