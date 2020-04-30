#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX_N = 100001;
const ll DIV_NUM = 1000000007;

int N, K, root[MAX_N];

ll pow(int N, int K) {
	if (K == 0) return 1;
	ll tmp=pow(N, K/2);
	tmp = (tmp * tmp)%DIV_NUM;
	if (K%2) tmp= (tmp * N)%DIV_NUM;
	return tmp;
}

int find(int x) {
	if (root[x] < 0) return x;
	return root[x]=find(root[x]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (a > b) swap(a, b);
	root[a]+=root[b];
	root[b]=a;
}

int main() {
	memset(root, -1, sizeof(root));
	scanf("%d%d", &N, &K);
	ll ret = pow(N, K);
	for (int i=0; i<N; i++) {
		int u, v, x;
		scanf("%d%d%d", &u, &v, &x);
		if (!x) merge(u, v);
	}
	ll sret=0;
	for (int i=1; i<=N; i++)
		if (i == find(i))
			sret = (sret + pow(-root[i], K))%DIV_NUM;
	ret = (DIV_NUM + ret - sret)%DIV_NUM;
	printf("%lld\n", ret);
	return 0;
}