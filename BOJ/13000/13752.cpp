// baekjoon 13752 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int N, T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		for (int i=0; i<N; i++)
			printf("=");
		puts("");
	}
	return 0;
}