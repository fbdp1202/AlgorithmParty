// baekjoon 11000 yechan
#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;

const int MAX_N=200001;
int N, S[MAX_N], E[MAX_N], ret, Spos, Epos;

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%d%d", &S[i], &E[i]);
	sort(S, S+N);
	sort(E, E+N);
	
	while (Spos < N && Epos < N) {
		while (Spos < N && S[Spos] < E[Epos]) Spos++;
		ret = max(ret, Spos - Epos);
		Epos++;
	}
	printf("%d\n", ret);
	return 0;
}