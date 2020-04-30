// baekjoon 2109 yechan
#include <cstdio>
#include <queue>
#include <algorithm>
#include <utility>
#include <functional>
using namespace std;

const int MAX_N=10001;

int N, ret;
pair<int,int> data[MAX_N];

int main()
{
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf("%d%d", &data[i].second, &data[i].first);
	}

	sort(data, data+N);
	priority_queue<int> PQ;
	int now = data[N-1].first; // 마지막 날짜.
	int here = N-1;
	while (now)
	{
		while (here >= 0 && data[here].first == now) {
			PQ.push(data[here].second);
			here--;
		}
		if (!PQ.empty()) {
			ret += PQ.top();
			PQ.pop();
		}
		now--;
	}
	printf("%d\n", ret);
	return 0;
}