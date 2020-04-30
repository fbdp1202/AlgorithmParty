// baekjoon 2774 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

bool visited[10];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int N;
		scanf("%d", &N);
		fill(visited, visited+10, false);
		int cnt = 0;
		while (N) {
			if (!visited[N%10]) {
				visited[N%10]=true;
				cnt++;
			}
			N /= 10;
		}
		printf("%d\n", cnt);
	}
	return 0;
}