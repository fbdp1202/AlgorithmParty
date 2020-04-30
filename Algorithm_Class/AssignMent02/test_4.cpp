// algo Assginment #2 	4.cpp
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX_N=5001;
const int MAX_M=200001;
const ll MAX_K=0x7FFFFFFFFFFFFFFF;

int T, N, M;
ll A[MAX_N], B[MAX_M];
ll C[MAX_M];
ll K, result;

int main() {
	scanf("%d %d", &N, &M);
	for (int i=0; i<N; i++) scanf("%lld", &A[i]);
	for (int i=0; i<M; i++) scanf("%lld", &B[i]);
	for (int i=0; i<N; i++)
		for (int j=0; j<M; j++)
			C[i*M+j]=A[i]*B[j];
	sort(C, C+N*M);
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++)
			printf("%lld ", C[i*M+j]);
		puts("");
	}
	puts("");
	B[M]=MAX_K;
	sort(A, A+N);
	sort(B, B+M+1);
	bool flag=true;
	while (1) {
		K++;
		if (K > N*M) break;
		ll left=0, right=MAX_K;
		result=0;
		while (left <= right) {
			ll cnt=0;
			ll mid = (left+right)/2;
			for (int i=0; i<N; i++) {
				if (A[i]) cnt += lower_bound(B, B+M+1, mid/A[i]+1)-B;
				else cnt += M;
			}
			if (cnt < K) left=mid+1;
			else result=mid, right=mid-1;
		}
		printf("%lld ", result);
		if (C[K-1] != result) flag=false;
		if (K%M == 0) puts("");
	}
	if (!flag) printf("\nERROR\n");
	else printf("\nCORRECT\n");
	return 0;
}