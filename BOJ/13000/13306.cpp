// baekjoon 13306 yechan
#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;

const int MAX_N=200001;

struct Query{
	int cmd, c, d;
	Query():cmd(0),c(0),d(0){}
	Query(int cmd, int c, int d):cmd(cmd),c(c),d(d){}
};

int N, Q, root[MAX_N], ret[MAX_N];
int parent[MAX_N];
Query query[MAX_N*2];

int find(int x) {
	if (root[x] < 0) return x;
	return root[x]=find(root[x]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	root[a] = b;
	return;
}

bool connect(int a, int b) {
	return find(a) == find(b);
}

int main()
{
	memset(root, -1, sizeof(root));
	memset(parent, -1, sizeof(parent));
	scanf("%d%d", &N, &Q);
	for (int i=2; i<=N; i++)
		scanf("%d", &parent[i]);

	for (int i=0; i<(N-1)+Q; i++) {
		int cmd, c, d;
		scanf("%d", &cmd);
		if (cmd) {
			scanf("%d%d", &c, &d);
			query[i]=Query(cmd, c, d);
		} else {
			scanf("%d", &c);
			query[i]=Query(cmd, c, -1);
		}
	}

	int Qpos = Q-1;
	for (int i=N-1+Q-1; i>=0; i--) {
		if (query[i].cmd) ret[Qpos--] = connect(query[i].c, query[i].d);
		else merge(query[i].c, parent[query[i].c]);
	}

	for (int i=0; i<Q; i++)
		puts(ret[i] ? "YES" : "NO");

	return 0;
}