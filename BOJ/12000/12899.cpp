// baekjoon 12899 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N=2000001;
const int SIZE=1<<21;

int N;
int arr[SIZE*2];

void update(int i, int val) {
	i += SIZE-1;
	if (val) arr[i]++;
	else arr[i]--;
	while (i > 1) {
		i/=2;
		arr[i] = arr[i*2] + arr[i*2+1];
	}
}

int Kth(int node, int start, int end, int k) {
	if (start == end) return start;
	else {
		int mid = (start+end)/2;
		if (k <= arr[node*2]) return Kth(node*2, start, mid, k);
		else return Kth(node*2+1, mid+1, end, k-arr[node*2]);
	}
}

int Kth(int k) {
	return Kth(1, 1, SIZE-1, k);
}

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		int T, X;
		scanf("%d%d", &T, &X);
		if (T == 1) update(X, 1);
		else {
			int ret = Kth(X);
			update(ret, 0);
			printf("%d\n", ret);
		}
	}
	return 0;
}