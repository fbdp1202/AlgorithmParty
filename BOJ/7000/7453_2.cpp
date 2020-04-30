// baekjoon 7453_2 yechan Two-pointer
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=4000;
typedef long long ll;

int N;
ll ret=0, board[4][4000], twoSum0[16000001], twoSum1[16000001];
ll Acnt=0, Bcnt=0, Aval, Bval, Tval;

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

	int Apos = 0, Bpos = NN-1;
	while ((Apos < NN) && (Bpos >= 0)) {
		Aval = twoSum0[Apos];
		Bval = twoSum1[Bpos];
		Tval = Aval + Bval;
		if (Acnt == 0) {
			while ((Apos < NN) && (Aval == twoSum0[Apos])) Apos++, Acnt++;
			Apos--;
		}
		if (Bcnt == 0) {
			while ((Bpos >= 0) && (Bval == twoSum1[Bpos])) Bpos--, Bcnt++;
			Bpos++;
		}
		if (Tval == 0) {
			Apos++, Bpos--, ret += Acnt*Bcnt;
			Acnt = Bcnt = 0;
		}
		else if (Tval > 0) Bcnt=0, Bpos--;
		else Acnt=0, Apos++;
	}
	printf("%lld\n", ret);
	return 0;
}