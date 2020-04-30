// baekjoon 5014 yechan
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int F, S, G, U, D, cnt;
bool visited[1000001];
queue<int> q;

int main() {
	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
	bool flag = false;
	visited[S]=true;
	q.push(S);
	while (!q.empty()) {
		int sz = q.size();
		while (sz--) {
			int pos = q.front(); q.pop();
			if (pos == G) {
				flag = G;
				break;
			}
			int nPos[2] = {pos - D, pos + U};

			for (int i=0; i<2; i++) {
				if (i==0 && nPos[0] < 1) continue;
				if (i==1 && nPos[1] > F) continue;
				if (visited[nPos[i]]) continue;
				visited[nPos[i]] = true;
				q.push(nPos[i]);
			}
		}
		if(flag) break;
		cnt++;
	}
	flag ? printf("%d\n",cnt) : printf("use the stairs\n");
	return 0;
}