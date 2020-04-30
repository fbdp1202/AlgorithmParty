// baekjoon 1327 yechan
#include <cstdio>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

int N, K, start, dst, data[10];

void fillData(int &src, int pos, int d) {
	src |= d<<(pos*3);
}

void eraseData(int &src, int pos) {
	src = src & ~(7<<(pos*3));
}

int getData(int src, int pos) {
	return (src & (7<<(pos*3)))>>(pos*3);
}

void swapData(int &src, int s, int k) {
	for (int i=0; i<k/2; i++) {
		int a = getData(src, s+i);
		int b = getData(src, s+k-i-1);
		eraseData(src, s+i);
		eraseData(src, s+k-i-1);
		fillData(src, s+k-i-1, a);
		fillData(src, s+i, b);
	}
}

void BinaryPrint(int src) {
	for (int i=0; i<3*N; i++){
		printf("%d", src%2);
		if (i%3 == 2) printf(" ");
		src >>= 1;
	}
	puts("");
}

int main() {
	set<int> s;

	scanf("%d %d", &N, &K);
	for (int i=0; i<N; i++){
		scanf("%d", &data[i]);
		data[i]--;
	}

	for (int i=0; i<N; i++) {
		fillData(start, i, data[i]);
	}

	sort(data, data+N);
	for (int i=0; i<N; i++) {
		fillData(dst, i, data[i]);
	}

	queue<int> q;
	q.push(start);
	s.insert(start);

	int depth=0, result=-1;

	while(!q.empty()) {
		int qSize = q.size();
		while (qSize--) {
			int curr = q.front(); q.pop();
			if (curr == dst) {
				result = depth;
				break;
			}
			for (int i=0; i<N-K+1; i++) {
				int next = curr;
				swapData(next, i, K);
				if (!s.count(next)) {
					s.insert(next);
					q.push(next);
				}
			}
		}
		if (~result) {
			break;
		}
		depth++;
	}

	printf("%d\n", result);
	return 0;
}