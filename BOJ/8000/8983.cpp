// baekjoon 8983 yechan
#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

const int MAX_N=100001;

int M, N, L;
int pos[MAX_N];
pair<int,int> animals[MAX_N];

int getDistance(int x, int a, int b) {
	return abs(x-a) + b;
}

int main()
{
	scanf("%d%d%d", &M, &N, &L);
	for (int i=0; i<M; i++)
		scanf("%d", &pos[i]);

	sort(pos, pos+M);
	pos[M]=2e9+1000;

	int ret=0;
	for (int i=0; i<N; i++) {
		scanf("%d%d", &animals[i].first, &animals[i].second);
		if (animals[i].second > L) continue;

		int diff = L - animals[i].second;
		int up = animals[i].first - diff;
		int down = animals[i].first + diff;

		int idx = lower_bound(pos, pos+M+1, up) - pos;
		if (pos[idx] <= down) ret++;
	}

	printf("%d\n", ret);
	return 0;
}