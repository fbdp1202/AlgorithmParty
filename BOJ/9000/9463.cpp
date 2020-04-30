// baekjoon 9463 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int SIZE = 1 << 17;
typedef pair<int,int> P;

int T, N, minarr[SIZE*2], maxarr[SIZE*2];
int data[SIZE], data2[SIZE];
P data1[SIZE];

struct SegTree{
	SegTree(){}
	void update(int *arr, int i, int val) {
		i+=SIZE;
		arr[i]=val;
		while (i > 1) {
			i /= 2;
			arr[i] = arr[i*2] + arr[i*2+1];
		}
	}

	int sum(int *arr, int L, int R, int nodeNum, int nodeL, int nodeR) {
		if (R < nodeL || nodeR < L) return 0;
		if (L <= nodeL && nodeR <= R) return arr[nodeNum];
		int mid = (nodeL + nodeR) / 2;
		return sum(arr, L, R, nodeNum*2, nodeL, mid) + sum(arr, L, R, nodeNum*2+1, mid+1, nodeR);
	}
	int sum(int *arr, int L, int R){ return sum(arr, L, R, 1, 0, SIZE-1);}
};

int main() {
	scanf("%d", &T);
	SegTree sg;

	while (T--){
		scanf("%d", &N);
		fill(minarr, minarr+SIZE*2, 0);
		fill(maxarr, maxarr+SIZE*2, 0);
		for (int i=1; i<=N; i++) sg.update(minarr, i, 1);
		for (int i=0; i<N; i++) scanf("%d", &data[i]);
		for (int i=0; i<N; i++) {
			scanf("%d", &data1[i].first);
			data1[i].second = i+1;
		}
		sort(data1, data1+N);
		for (int i=0; i<N; i++) data2[i] = data1[data[i]-1].second;

		long long cnt = 0;
		for (int i=0; i<N; i++) {
			sg.update(minarr, data2[i], 0);
			cnt += sg.sum(minarr, 1, data2[i]);
			cnt += sg.sum(maxarr, data2[i], N);
			sg.update(maxarr, data2[i], 1);
		}
		printf("%lld\n", cnt/2);
	}
	return 0;
}