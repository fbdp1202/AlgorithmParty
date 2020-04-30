// baekjoon 16287 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N=5001;
int W, N, A[MAX_N];
bool B[800001];

int main()
{
	scanf("%d%d", &W, &N);
	for (int i=0; i<N; i++)
		scanf("%d", &A[i]);

	sort(A, A+N);

	for (int i=0; i<N; i++) {
		for (int j=i+1; j<N; j++) {
			int ret = A[i] + A[j];
			if (ret > W) break;
			if (B[W-ret]) {
				return !printf("YES\n");
			}
		}
		for (int j=0; j<i; j++) {
			B[A[j]+A[i]]=true;
		}
	}
	printf("NO\n");
	return 0;
}