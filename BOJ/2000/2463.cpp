// baekjoon 2463 yechan
#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;
using PP = pair<int,P>;
using ll = long long;

const int MAX_N=100001;
const ll DIV_NUM=1e9;

int N, M;
PP node[MAX_N];
int root[MAX_N];

int find(int x) {
	if (root[x] < 0) return x;
	return root[x] = find(root[x]);
}

ll merge(int a, int b, int c) {
	a = find(a);
	b = find(b);
	if (a == b) return 0;
	ll ret = 1LL*c*root[a]*root[b];
	root[a] += root[b];
	root[b]	= a;
	return ret;
}

int main() {
	memset(root, -1, sizeof(root));
	scanf("%d%d", &N, &M);
	ll sum = 0;
	for (int i=0; i<M; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		u--,v--;
		sum += w;
		node[i] = PP(-w, P(u,v));
	}
	sum %= DIV_NUM;
	sort(node, node+M);

	ll ret = 0;
	for (int i=0; i<M; i++) {
		int u = node[i].second.first;
		int v = node[i].second.second;
		int w = -node[i].first;
		ll ans = merge(u,v,sum);
		ret = (ret + ans)%DIV_NUM;
		sum = (DIV_NUM + sum - w)%DIV_NUM;
	}
	printf("%lld\n", ret);
	return 0;
}