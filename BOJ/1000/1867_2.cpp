// baekjoon 1867_2 yechan
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_N=101;

int N, K;
int board[MAX_N][MAX_N];
int check[MAX_N][MAX_N];
int n, match, step;
vector<vector<int> > G;
vector<int> A, B, visit;
vector<pair<int,int> > vertex;
vector<pair<int,int> > lines;

bool drawLine(int here, int count) {
	if (K == count) return true;
	if (here >= match) return false;
	bool ret = false;
	int x = vertex[here].first;
	int y = vertex[here].second;
	// column line
	for (int i=1; i<=N; i++) {
		if (board[x][i]) continue;
		if (check[x][i]) continue;
		count++;
		check[x][i]=here+1;
	}
	lines[here] = {x, 0};
	ret = drawLine(here+1, count);
	if (ret) return ret;
	for (int i=1; i<=N; i++) {
		if (board[x][i]) continue;
		if (check[x][i] == here + 1) {
			count--;
			check[x][i]=0;
		}
	}
	// row line
	for (int i=1; i<=N; i++) {
		if (board[i][y]) continue;
		if (check[i][y]) continue;
		count++;
		check[i][y]=here+1;
	}
	lines[here] = {y, 1};
	ret = drawLine(here+1, count);
	if (ret) return ret;
	for (int i=1; i<=N; i++) {
		if (board[i][y]) continue;
		if (check[i][y] == here + 1) {
			count--;
			check[i][y]=0;
		}
	}
	lines[here] = {0, 0};
	return ret;
}

void findLines() {
	drawLine(0, 0);
}

bool dfs(int a) {
	visit[a] = step;
	for(auto b: G[a]) {
		if (B[b]==-1 || (visit[B[b]]!=step && dfs(B[b]))) {
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}

int main() {
	scanf("%d", &N);
	G = vector<vector<int> >(N+1);
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=N; j++) {
			int x;
			scanf("%d", &x);
			board[i][j] = x;
			if (!x) {
				K++;
				G[i].push_back(j);
			}
		}
	}

	A = vector<int>(N+1, -1);
	visit = vector<int>(N+1, 0);
	B = vector<int>(N+1, -1);

	// bipartile match
	step=1, match=0;
	for (int i=1; i<=N; i++) {
		if (A[i] == -1 && dfs(i)) match++;
		step++;
	}

	// matching Vertexs
	for (int i=1; i<=N; i++) {
		if (A[i] == -1) continue;
		vertex.push_back(make_pair(i, A[i]));
	}
	printf("num Match: %d\n", match);

	// find lines
	lines = vector<pair<int,int> >(match);
	findLines();
	printf("row is 0 --, col is 1 | \n");
	for (int i=0; i<match; i++) {
		printf("lines[%d]: %d %d\n", i, lines[i].first, lines[i].second);
	}
	return 0;
}