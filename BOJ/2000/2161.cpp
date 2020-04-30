// baekjoon 2161 yechan
#include <cstdio>
#include <algorithm>
#include <deque>
using namespace std;

int N;
deque<int> dq;

int main()
{
	scanf("%d", &N);
	for (int i=1; i<=N; i++)
		dq.push_back(i);

	for (int i=1; i<=N-1; i++) {
		printf("%d ", dq[0]);
		dq.pop_front();
		dq.push_back(dq[0]);
		dq.pop_front();
	}
	printf("%d\n", dq[0]);
	return 0;
}
