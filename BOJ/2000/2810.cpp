// baekjoon 2810 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N;
char sit[51];

int main() {
	scanf("%d", &N);
	scanf("%s", sit);
	int result = 1;
	for (int i=0; i<N; i++) {
		if (sit[i] == 'S') result++;
		else result++, i++;
	}
	printf("%d\n", min(result, N));
	return 0;
}