// baekjoon 4158 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N=1000001;

int N, M;
int A[MAX_N], B[MAX_N];

int main()
{
	while (1) {
		scanf("%d%d", &N, &M);
		if (N + M == 0) break;

		for (int i=0; i<N; i++)
			scanf("%d", &A[i]);

		for (int i=0; i<M; i++)
			scanf("%d", &B[i]);

		int ret = 0;
		int Apos=0, Bpos=0;
		while (Apos < N && Bpos < M) {
			if (A[Apos] == B[Bpos]) ret++, Apos++, Bpos++;
			else if (A[Apos] < B[Bpos]) Apos++;
			else Bpos++;
		}
		printf("%d\n", ret);
	}

}