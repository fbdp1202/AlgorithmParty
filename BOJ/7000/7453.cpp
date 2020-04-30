// baekjoon 7453 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=4000;
typedef long long ll;

int N;
ll ret, board[4][4000], twoSum0[16000001], twoSum1[16000001];
ll Acnt, Bcnt, Aval, Bval, Tval;

int main() {
	scanf("%d", &N);
	int NN = N*N;
	for (int i=0; i<N; i++)
		for (int j=0; j<4; j++)
			scanf("%lld", &board[j][i]);

	for (int i=0, z=0; i<N; i++) {
		for (int j=0; j<N; j++, z++) {
			twoSum0[z] = board[0][i] + board[1][j];
			twoSum1[z] = board[2][i] + board[3][j];
		}
	}

	sort(twoSum0, twoSum0+NN);
	sort(twoSum1, twoSum1+NN);

	for (int i=0; i<NN; i++) {
		ll target = twoSum0[i];
		ll lo = lower_bound(twoSum1, twoSum1+NN, -target)-twoSum1;
		ll hi = upper_bound(twoSum1, twoSum1+NN, -target)-twoSum1;
		ret += hi - lo;
	}
	printf("%lld\n", ret);
	return 0;
}