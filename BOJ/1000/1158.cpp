// baekjoon 1158 yechan
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXN = 5001;

int N, M, cnt;
bool visited[MAXN];

int main() {
	scanf("%d%d", &N, &M);
	queue<int> q;
	for (int i=1; i<=N; i++) 
		q.push(i);

	cnt = N;
	printf("<");
	while (cnt) {
		for (int i=0; i<M-1; i++) {
			q.push(q.front()); q.pop();
		}
		printf("%d", q.front()); q.pop();
		cnt--;
		if (cnt) printf(", ");
	}
	printf(">");
	return 0;
}