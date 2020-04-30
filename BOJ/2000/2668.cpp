// baekjoon 2668 yechan
#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;
const int MAX_N=101;

int N, data[MAX_N], visited[MAX_N], ret;
set<int> s;

void dfs(int here, int count) {
	if (visited[here]) {
		for (int i=1; i<=N; i++) {
			if (visited[here] <= visited[i] && visited[i] <= count-1) {
				s.insert(i);
				ret++;
			}
		}
	}
	visited[here]=count;
	if (!s.count(data[here])) {
		dfs(data[here], count+1);
	}
}

int main() {
	scanf("%d", &N);
	for (int i=1; i<=N; i++)
		scanf("%d", &data[i]);

	for (int i=1; i<=N; i++) {
		memset(visited, 0, sizeof(visited));
		if (!s.count(i)) dfs(i, 1);
	}
	printf("%d\n", ret);
	for (set<int>::iterator it=s.begin(); it!=s.end(); it++) {
		printf("%d\n", *it);
	}

	return 0;
}