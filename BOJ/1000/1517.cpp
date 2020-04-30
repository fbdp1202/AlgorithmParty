// baekjoon 1517 yechan
#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;

const int MAX_N=500001;
const int SIZE=1<<19;
typedef pair<int,int> P;

int arr[SIZE*2];
P data[MAX_N];

int sum(int L, int R, int nodeNum, int nodeL, int nodeR) {
	if (R < nodeL || nodeR < L) return 0;
	if (L <= nodeL && nodeR <= R) return arr[nodeNum];
	int mid = (nodeL + nodeR) / 2;
	return sum(L, R, nodeNum*2, nodeL, mid) + sum(L, R, nodeNum*2+1, mid+1, nodeR);
}

int sum(int L, int R) {
	return sum(L, R, 1, 0, SIZE-1);
}

void update(int i, int val) {
	i += SIZE;
	arr[i] = val;
	while (i > 1) {
		i /= 2;
		arr[i] = arr[i*2] + arr[i*2+1];
	}
}

int main() {
	int N;
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf("%d", &data[i].first);
		data[i].second = i+1;
	}
	sort(data, data+N);
	long long ret = 0;
	for (int i=N-1; i>=0; i--) {
		ret += sum(0, data[i].second-1);
		update(data[i].second, 1);
	}
	printf("%lld\n", ret);
	return 0;
}