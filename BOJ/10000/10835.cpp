// baekjoon 10835 yechan
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX_N = 2000;

int N, A[MAX_N], B[MAX_N], score[MAX_N][MAX_N];

int game(int Apos, int Bpos) {
	if (Apos >= N || Bpos >= N) return 0;
	if (score[Apos][Bpos] != -1) return score[Apos][Bpos];
	int &ret = score[Apos][Bpos];
	ret=0;
	if (A[Apos] > B[Bpos]) ret = game(Apos, Bpos+1) + B[Bpos];
	ret = max(ret, game(Apos+1, Bpos+1));
	ret = max(ret, game(Apos+1, Bpos));
	return ret;
}

int main() {
	memset(score, -1, sizeof(score));

	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%d", &A[i]);
	for (int i=0; i<N; i++) 
		scanf("%d", &B[i]);

	printf("%d\n", game(0, 0));
	return 0;
}