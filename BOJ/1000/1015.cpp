// baekjoon 1015 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N=1001;

int N;
pair<int,int> data[MAX_N];
int ans[MAX_N];

int main()
{
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf("%d", &data[i].first);
		data[i].second = i;
	}

	sort(data, data+N);
	for (int i=0; i<N; i++) {
		ans[data[i].second] = i;
	}

	for (int i=0; i<N; i++)
		printf("%d ", ans[i]);
	puts("");

	return 0;
}