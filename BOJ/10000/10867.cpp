// baekjoon 10867 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

const int BIAS=4000;

int N;
int ans[8001];

int main()
{
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		int x;
		scanf("%d", &x);
		ans[x+BIAS]++;
	}

	for (int i=0; i<8001; i++)
		if (ans[i]) printf("%d ", i - BIAS);
	return 0;
}