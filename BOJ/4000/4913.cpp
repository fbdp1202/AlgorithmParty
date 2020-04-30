#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 1000000
typedef long long ll;
ll i, j;
int L, U, cnt, square_cnt=1;
int localSum[MAX_N], squareSum[MAX_N];
bool prime[MAX_N];

int main() {
	for(i=2; i<MAX_N; i++) {
		if(!prime[i]){
			++cnt;
			if(i%4 == 1) ++square_cnt;
			for(j=i*i; j<MAX_N; j+=i) prime[j] = true;
		}
		localSum[i]=cnt;
		squareSum[i]=square_cnt;
	}
	while (1) {
		scanf("%d%d", &L, &U);
		if(L==-1 && U==-1) break;
		printf("%d %d ", L, U);L--;
		L = max(L,0); U=max(U,0);
		printf("%d %d\n", localSum[U]-localSum[L], squareSum[U]-squareSum[L]);
	}
}