// baekjoon 9085 yechan
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
		int ret = 0;
		for (int i=0; i<N; i++) {
			int x; scanf("%d", &x);
			ret += x;
		}
		printf("%d\n", ret);
	}
	return 0;
}