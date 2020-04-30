// baekjoon 7572 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int a=9,b=7, N;
	scanf("%d", &N);
	for (int i=1; i<N; i++) {
		a = (a+1)%12;
		b = (b+1)%10;
	}
	printf("%c%d",a+'A',b);
	return 0;
}