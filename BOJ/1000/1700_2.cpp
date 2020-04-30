// baekjoon 1700_2 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=101;

int N, K, ret, seq[MAX_N], plug[MAX_N];

int main() {
	scanf("%d%d", &K, &N);
	for (int i=0; i<N; i++)
		scanf("%d", &seq[i]);

	for (int i=0; i<N; i++) {
		bool flag = false;
		for (int j=0; j<K; j++) {
			if (plug[j] == seq[i] || plug[j] == 0) {
				flag = true;
				plug[j] = seq[i];
				break;
			}
		}
		if (flag) continue;

		int maxV = 0;
		int maxIdx = 0;
		for (int j=0; j<K; j++) {
			int tmp = N;
			for (int k=i+1; k<N; k++) {
				if (plug[j] == seq[k]) {
					tmp = k;
					break;
				}
			}
			if (maxV < tmp) {
				maxV = tmp;
				maxIdx = j;
			}
		}
		plug[maxIdx]=seq[i];
		ret++;
	}
	printf("%d\n", ret);
	return 0;
}