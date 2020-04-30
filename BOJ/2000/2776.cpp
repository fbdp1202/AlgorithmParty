// baekjoon 2776 yechan
#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;

const int MAX_N=1000001;

int T, N, M;
int A[MAX_N];
P B[MAX_N];
bool ans[MAX_N];

int main() {
	scanf("%d", &T);
	while (T--) {
		memset(ans, 0, sizeof(ans));

		scanf("%d", &N);
		for (int i=0; i<N; i++)
			scanf("%d", &A[i]);
		sort(A, A+N);

		scanf("%d", &M);
		for (int i=0; i<M; i++)
			scanf("%d", &B[i].first), B[i].second=i;
		sort(B, B+M);

		int Apos = 0, Bpos = 0;
		while (Apos < N && Bpos < M) {
			if (A[Apos] == B[Bpos].first) ans[B[Bpos].second]=true, Bpos++;
			else if (A[Apos] < B[Bpos].first) Apos++;
			else Bpos++;
		}
		for (int i=0; i<M; i++)
			puts(ans[i] ? "1":"0");
	}
	return 0;
}