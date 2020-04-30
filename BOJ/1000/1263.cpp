// baekjoon 1263 yechan
#include <cstdio>
#include <algorithm>
#include <functional>
#include <utility>
using namespace std;

const int MAX_N=1001;
typedef pair<int,int> P;

int N;
P data[MAX_N];

int main()
{
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%d%d", &data[i].second, &data[i].first);

	sort(data, data+N);

	int ret = data[N-1].first;
	for (int i=N-1; i>=0; i--) {
		ret = min(data[i].first, ret);
		ret -= data[i].second;
	}

	printf("%d\n", (ret < 0) ? -1 : ret);
	return 0;
}