// baekjoon 9713 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int N;
		scanf("%d", &N);
		int tmp = (N+1)/2;
		printf("%d\n", tmp*tmp);
	}
}