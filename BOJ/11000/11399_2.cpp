// bakejoon 11399 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 1000
int N, tmp, ans, waitTime[MAX_N];

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%d", &waitTime[i]);
	sort(waitTime, waitTime+N);
	for (int i=0; i<N; i++) {
		tmp += waitTime[i];
		ans += tmp;
	}
	printf("%d\n", ans);
	return 0;
}