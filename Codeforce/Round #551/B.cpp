#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=101;

int N, M, H;
int A[MAX_N], B[MAX_N], C[MAX_N][MAX_N];

int main() {
	scanf("%d%d%d", &N, &M, &H);
	for (int i=0; i<M; i++)
		scanf("%d", &A[i]);

	for (int i=0; i<N; i++)
		scanf("%d", &B[i]);

	for (int i=0; i<N; i++)
		for (int j=0; j<M; j++)
			scanf("%d", &C[i][j]);

	for (int i=0; i<N; i++)
		for (int j=0; j<M; j++)
			if (C[i][j]) C[i][j]=min(A[j],B[i]);

	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			printf("%d ",C[i][j]);
		}
		puts("");
	}
	return 0;
}