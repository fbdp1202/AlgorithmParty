// baekjoon 15649 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N, M, seq[9], data[9];
bool visited[9];

void dfs(int here, int count) {
	if (count == M) {
		for (int i=0; i<count; i++)
			printf("%d ", data[seq[i]]);
		puts("");
		return;
	}
	for (int i=here; i<N; i++) {
		seq[count]=i;
		dfs(i, count+1);
	}
}

int main()
{
	scanf("%d%d", &N, &M);
	for (int i=0; i<N; i++) scanf("%d", &data[i]);
	sort(data, data+N);
	dfs(0, 0);
	return 0;
}