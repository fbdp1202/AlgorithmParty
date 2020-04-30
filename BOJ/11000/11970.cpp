// baekjoon 11970 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int a, b, c, d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if (a > c) swap(a,c), swap(b,d);
	if (b < c) printf("%d", b-a+d-c);
	else printf("%d", max(b,d)-a);

	return 0;
}