// baekjoon 17359 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

struct Light{
	int s, e, cnt;
	Light():s(0),e(0),cnt(0){}
	Light(int s, int e, int c):s(s),e(e),cnt(c){}
};

int N;
Light light[10];
int seq[10];
int ret = 2e9;
bool visited[10];
char str[101];

void dfs(int here) {
	if (here == N) {
		int cnt = 0;
		for (int i=0; i<N-1; i++) {
			cnt += light[seq[i]].cnt;
			if (light[seq[i]].e != light[seq[i+1]].s) cnt++;
		}
		cnt += light[seq[N-1]].cnt;
		ret = min(ret, cnt);
		return;
	}
	for (int i=0; i<N; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		seq[here] = i;
		dfs(here + 1);
		visited[i] = false;
	}
}

int main()
{
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf("%s", str);
		int start = str[0]-'0';

		int cnt = 0;
		int j = 0;
		char prev = str[0];
		for (j=1; str[j]; j++) {
			if (prev == str[j]) continue;
			cnt++;
			prev = str[j];
		}
		light[i] = Light(start, str[j-1]-'0', cnt);
	}
	dfs(0);
	printf("%d\n", ret);
	return 0;
}