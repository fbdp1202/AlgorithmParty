// baekjoon 13334 yechan
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <functional>
#include <utility>
using namespace std;
typedef pair<int,int> P;

const int MAX_N=100001;

int N, h, o, d;
pair<int,int> data[MAX_N];

int main()
{
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf("%d%d", &h, &o);
		if (h < o) swap(h, o);
		data[i] = {h, o};
	}
	sort(data, data+N);

	scanf("%d", &d);

	int ret = 0;
	priority_queue<int, vector<int>, greater<int> > PQ;
	for (int i=0; i<N; i++) {
		PQ.push(data[i].second);
		while (!PQ.empty() && data[i].first - d > PQ.top()) PQ.pop();
		ret = max(ret, (int)PQ.size());
	}
	printf("%d\n", ret);
	return 0;
}