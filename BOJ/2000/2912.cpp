// baekjoon 2912 yechan
#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

const int MAX_N=300001;
const int MAX_C=10001;
const int MAX_M=10001;

const int MAX_SIZE=1<<20+1;

int N, C, M;
int color[MAX_N];
int seg[MAX_SIZE];
P dwarf[MAX_N];

int getCnt(int c, int a, int b) {
	return (int)(upper_bound(dwarf, dwarf+N, make_pair(c, b)) - lower_bound(dwarf, dwarf+N, make_pair(c, a)));
}

void construct(int nodeNum, int nodeL, int nodeR) {
	if (nodeL == nodeR) {
		seg[nodeNum] = color[nodeL];
		return;
	}
	int mid = (nodeL+nodeR)/2;
	int limit = (nodeR-nodeL+1)/2;

	construct(nodeNum*2, nodeL, mid);
	construct(nodeNum*2+1, mid+1, nodeR);

	int c;
	c = seg[nodeNum*2];
	if (getCnt(c, nodeL, nodeR) > limit) {
		seg[nodeNum] = c;
		return;
	}

	c = seg[nodeNum*2+1];
	if (getCnt(c, nodeL, nodeR) > limit) {
		seg[nodeNum] = c;
		return;
	}
	seg[nodeNum] = -1;
}

int query(int a, int b, int nodeNum, int nodeL, int nodeR) {
	if (a > nodeR or b < nodeL) return -1;
	int limit = (b-a+1)/2;
	if (a <= nodeL and nodeR <= b) {
		int cnt = getCnt(seg[nodeNum], a, b);
		if (cnt > limit) {
			return seg[nodeNum];
		}
		return -1;
	}

	int mid = (nodeL + nodeR) / 2;

	int lc = query(a, b, nodeNum*2, nodeL, mid);
	if (lc != -1) return lc;

	int rc = query(a, b, nodeNum*2+1, mid+1, nodeR);
	if (rc != -1) return rc;

	return -1;
}

int query(int a, int b) {
	return query(a, b, 1, 1, N);
}

int main() {
	scanf("%d%d", &N, &C);
	for (int i=1; i<=N; i++) {
		scanf("%d", &color[i]);
		dwarf[i-1] = make_pair(color[i], i);
	}
	sort(dwarf, dwarf+N);
	construct(1, 1, N);

	scanf("%d", &M);

	for (int i=0; i<M; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		int ret = query(a, b);
		if (ret == -1) puts("no");
		else printf("yes %d\n", ret);
	}
	return 0;
}