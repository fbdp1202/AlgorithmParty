// baekjoon 9426 yechan
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
#define MAX_N 65536
typedef long long ll;

void update(vector<int> &tree, int node, int start, int end, int index, int val) {
	if (index < start || index > end ) return;

	if (start == end) {
		tree[node] += val; return;
	}

	int mid = (start + end) / 2;
	update(tree, node * 2, start, mid, index, val);
	update(tree, node * 2 + 1, mid+1, end, index, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int kth(vector<int> &tree, int node, int start, int end, int k) {
	if (start == end) return start;
	int mid = (start + end) / 2;
	if (k <= tree[node*2]) return kth(tree, node * 2, start, mid, k);
	else return kth(tree, node * 2 + 1, mid + 1, end, k - tree[node * 2]);
}

int main() {
	int N, K;
	scanf(" %d %d", &N, &K);
	int h = ceil(log2(MAX_N+1));
	int tree_size = (1 << (h+1));
	int cnt = (K + 1) / 2;
	vector<int> tree(tree_size, 0);
	vector<int> a(N + 1, 0);

	ll ans = 0;
	for (int i=0; i<K-1; i++) {
		scanf(" %d", &a[i]);
		update(tree, 1, 0, MAX_N, a[i], 1);
	}
	for (int i=K-1; i<N; i++) {
		scanf(" %d", &a[i]);
		update(tree, 1, 0, MAX_N, a[i], 1);
		ans += (ll)kth(tree, 1, 0, MAX_N, cnt);
		update(tree, 1, 0, MAX_N, a[i - (K - 1)], -1);
	}
	printf("%lld\n", ans);
	return 0;
}