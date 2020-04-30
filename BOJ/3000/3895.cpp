// baekjoon 3895 yechan
#include <cstdio>
#include <deque>
#include <algorithm>
using namespace std;

int N, K, M;

int main()
{
	while (1)
	{
		scanf("%d%d%d", &N, &K, &M);
		if (N+K+M == 0) break;

		deque<int> dq;
		for (int i=1; i<=N; i++) {
			dq.push_back(i);
		}

		for (int i=1; i<M; i++) {
			dq.push_back(dq[0]);
			dq.pop_front();
		}
		dq.pop_front();

		K--;
		for (int i=2; i<N; i++) {
			int cicle = K % dq.size();
			while (cicle--) {
				dq.push_back(dq[0]);
				dq.pop_front();
			}
			dq.pop_front();
		}
		printf("%d\n", dq[0]);
	}
	return 0;
}