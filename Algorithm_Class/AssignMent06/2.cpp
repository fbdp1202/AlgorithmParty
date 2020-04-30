// AssignMent 06 - 2.cpp
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
long long t;

int n, m, l, u, v;
vector<vector<int> > adj;
vector<int> A;
vector<int> B;
vector<bool> visited;

bool bimatch(int here) {
	visited[here]=true;
	for (int i=0; i<adj[here].size(); i++) {
		int nx = adj[here][i];
		if (!B[nx] || !visited[B[nx]] && bimatch(B[nx])) {
			A[here] = nx;
			B[nx] = here;
			return true;
		}
	}
	return false;
}

int main() {
	scanf("%lld", &t);
	while (t-- > 0) {
		scanf("%d%d%d", &n, &m, &l);

		adj = vector<vector<int> >(n+m+1);
		A = vector<int>(n+m+1, 0);
		B = vector<int>(n+m+1, 0);
		visited = vector<bool>(n+m+1, false);

		for (int i=0; i<l; i++) {
			scanf("%d%d", &u, &v);
			adj[v+1].push_back(u+1);
		}

		int cnt=0;
		for (int i=1; i<=n; i++) {
			fill(visited.begin(), visited.end(), false);
			if (bimatch(i)) cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}