// baekjoon 2336 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int SIZE = 1<<19;
const int MAX_N = 500000;
const int INF = 1e9;

struct TestSet {
	int A, B, C;
	bool operator < (const TestSet &o) const {
		return A < o.A;
	}
};

int N, cnt, x, arr[SIZE*2];
TestSet data[MAX_N];

int sum(int L, int R, int nodeNum, int nodeL, int nodeR) {
	if (R < nodeL || nodeR < L) return INF;
	if (L <= nodeL && nodeR <= R) return arr[nodeNum];
	int mid = (nodeL + nodeR) / 2;
	return min(sum(L, R, nodeNum*2, nodeL, mid), sum(L, R, nodeNum*2+1, mid+1, nodeR));
}
int sum(int L, int R) { return sum(L, R, 1, 0, SIZE-1); }

void update(int i, int val) {
	i+=SIZE;
	arr[i]=val;
	while (i > 1) {
		i /= 2;
		arr[i] = min(arr[i*2], arr[i*2+1]);
	}
}

int main() {
	fill(arr, arr+SIZE*2, INF);
	scanf("%d", &N);
	for (int i=0; i<N; i++) { scanf("%d", &x); data[x-1].A = i; };
	for (int i=0; i<N; i++) { scanf("%d", &x); data[x-1].B = i; };
	for (int i=0; i<N; i++) { scanf("%d", &x); data[x-1].C = i; };

	sort(data, data+N);

	for (int i=0; i<N; i++) {
		int tmp = sum(0, data[i].B);
		if (tmp > data[i].C) cnt++;
		update(data[i].B, data[i].C);
	}
	printf("%d\n", cnt);
	return 0;
}