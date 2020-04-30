// baekjoon 6986 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=100001;

int N, K;
long long arr[MAX_N], sum1, sum2;

int main() {
	scanf("%d%d", &N, &K);
	for (int i=0; i<N; i++) {
		int x, y;
		scanf("%d.%d", &x, &y);
		arr[i]=x*1000+y*100;
	}

	sort(arr,arr+N);
	for (int i=K; i<N-K; i++) sum1 += arr[i];
	sum2 = sum1 + arr[K]*K + arr[N-K-1]*K;
	sum1 = sum1/(N-2*K);
	sum2 = sum2/N;
	sum1+=5; sum2+=5;
	sum1/=10; sum2/=10;
	printf("%lld.%02lld\n%lld.%02lld\n", sum1/100, sum1%100, sum2/100, sum2%100);
	return 0;
}