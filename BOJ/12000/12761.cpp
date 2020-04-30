// baekjoon 12761 yechan
#include <cstdio>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

typedef pair<int,int> P;
const int MAX_N=100001;
int N, M;
int A, B;
bool visited[MAX_N];
vector<int> dir;

int BFS() {
	queue<int> q;
	q.push(N);
	dir.push_back(-1);
	dir.push_back(1);
	dir.push_back(A);
	dir.push_back(-A);
	dir.push_back(B);
	dir.push_back(-B);
	int t = 0;
	visited[N] = true;
	while (!q.empty()) {
		int qSize = q.size();
		while (qSize--) {
			int cur = q.front();
			if (cur == M) return t;
			q.pop();
			for (int i=0; i<dir.size(); i++) {
				int nx = cur + dir[i];
				if (nx < 0 || nx >= MAX_N) continue;
				if (visited[nx]) continue;
				visited[nx] = true;
				q.push(nx);
			}
			int nx = cur * A;
			if (!(nx < 0 || nx >= MAX_N)) {
				if (!visited[nx]) {
					visited[nx] = true;
					q.push(nx);
				}
			}
			nx = cur * B;
			if (!(nx < 0 || nx >= MAX_N)) {
				if (!visited[nx]) {
					visited[nx] = true;
					q.push(nx);
				}
			}
		}
		t++;
	}
	return -1;
}

int main()
{
	scanf("%d%d", &A, &B);
	scanf("%d%d", &N, &M);
	printf("%d\n", BFS());
	return 0;
}