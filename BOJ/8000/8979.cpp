// baekjoon 8979 yechan
#include <cstdio>
#include <algorithm>
#include <utility>
#include <functional>
using namespace std;

typedef pair<pair<int, int>, pair<int,int>> P;
const int maxN = 1001;

int N, K, idx;
P data[maxN];

int main() {
	scanf("%d%d", &N, &K);
	data[0] = {{1000001,0},{0,0}};
	for (int i=1; i<=N; i++){
		scanf("%d", &idx);
		scanf("%d%d%d", &data[idx].first.first, &data[idx].first.second, &data[idx].second.first);
		data[idx].second.second = idx;
	}
	sort(data+1, data+N+1, greater<P>());
	int cnt = 1;
	for (int i=1; i<=N; i++) {
		if (data[i-1].first.first == data[i].first.first &&
			data[i-1].first.second == data[i].first.second &&
			data[i-1].second.first == data[i].second.first) {
			if (data[i].second.second == K) break;
			else continue;
		}
		cnt = i;
		if (data[i].second.second == K) break;
	}
	printf("%d\n", cnt);
	return 0;
}