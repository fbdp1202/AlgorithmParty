// baekjoon 15649 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N, M;
bool visited[9];
int seq[9];

void dfs(int here, int count) {
	if (count == M) {
		for (int i=0; i<count; i++)
			printf("%d ", seq[i]);
		puts("");
		return;
	}
	for (int i=here+1; i<=N; i++) {
		if (visited[i]) continue;
		visited[i]=true;
		seq[count]=i;
		dfs(i, count+1);
		visited[i]=false;
	}
}

int main()
{
	scanf("%d%d", &N, &M);
	dfs(0, 0);
	return 0;
}