// baekjoon 10448 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=1001;

int T, N;
bool triple[4][MAX_N];

int main() {
	triple[0][0]=true;
	for (int i=0; i<3; i++) {
		for (int j=1; j<46; j++) {
			int tri = (j*(j+1))/2;
			for (int k=0; k<=1000; k++) {
				if (tri + k > 1000) break;
				triple[i+1][tri+k] |= triple[i][k];
			}
		}
	}
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		printf("%d\n", triple[3][N]);
	}
	return 0;
}