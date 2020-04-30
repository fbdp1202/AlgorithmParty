// baekjoon 1197 yechan
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

const int MAX_V=10001;
const int MAX_E=100001;

int V, E;
int root[MAX_V];
pair<int,pair<int,int> > node[MAX_E];

int find(int x) {
	if (!root[x]) return x;
	return root[x] = find(root[x]);
}

bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;
	root[b] = a;
	return true;
}

int main()
{
	scanf("%d%d", &V, &E);
	for (int i=0; i<E; i++) {
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		node[i] = make_pair(c, make_pair(u, v));
	}
	sort(node, node+E);

	long long sum = 0;
	for (int i=0; i<E; i++) {
		int a, b, c;
		a = node[i].second.first;
		b = node[i].second.second;
		c = node[i].first;
		if (merge(a, b)) sum += c;
	}
	printf("%lld\n", sum);
	return 0;
}