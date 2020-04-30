// baekjoon 9517 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=101;
const int BOOM_T=210;
const int DIV=8;

int K, N;
int T[MAX_N];
char Z[MAX_N];

int main() {
	scanf("%d%d", &K, &N);
	for (int i=0; i<N; i++)
		scanf("%d %c", &T[i], &Z[i]);

	int cur_t = 0;
	int cur_p = K - 1;
	for (int i=0; i<N; i++) {
		cur_t += T[i];
		if (cur_t >= BOOM_T) break;
		if (Z[i] == 'T') cur_p = (cur_p+1)%DIV;
	}
	printf("%d\n", cur_p+1);
	return 0;
}