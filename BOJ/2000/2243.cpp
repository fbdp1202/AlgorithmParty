// baekjoon 2243 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int SIZE = 1<<20;
int n, A, B, C;
int arr[SIZE*2];

int sum(int L, int R, int nodeNum, int nodeL, int nodeR) {
	if (R < nodeL || nodeR < L) return 0;
	if (L <= nodeL && nodeR <= R) return arr[nodeNum];
	int mid = (nodeL + nodeR) / 2;
	return sum(L, R, nodeNum*2, nodeL, mid) + sum(L, R, nodeNum*2+1, mid+1, nodeR);
}
int sum(int L, int R) { return sum(L, R, 1, 0, SIZE-1); }

int findIdx(int num, int nodeNum) {
	// printf("findIdx(%d, %d), arr[nodeNum]: %d\n", num, nodeNum, arr[nodeNum]);
	if (nodeNum >= SIZE) {
		return nodeNum;
	}
	if (arr[nodeNum] == num) {
		while (nodeNum < SIZE) {
			if (arr[nodeNum*2+1] == 0)
				nodeNum = nodeNum*2;
			else
				nodeNum = nodeNum*2+1;
		}
		return nodeNum;
	}
	else {
		if (num <= arr[nodeNum*2]){
			return findIdx(num, nodeNum*2);
		}
		else
			return findIdx(num-arr[nodeNum*2], nodeNum*2+1);
	}
}

void update(int i, int val) {
	i += SIZE;
	arr[i] += val;
	while (i > 1) {
		i /= 2;
		arr[i] = arr[i*2] + arr[i*2+1];
	}
}

int main() {
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &A);
		if (A == 1) {
			scanf("%d", &B);
			int pos = findIdx(B, 1);
			update(pos-SIZE, -1);
			printf("%d\n", pos-SIZE);
		} else {
			scanf("%d%d", &B, &C);
			update(B, C);
		}
	}
	return 0;
}