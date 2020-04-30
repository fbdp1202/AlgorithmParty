// baekjoon 7576 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int ret;
char pv, s[51];

int main() {
	scanf("%s", s);
	char pv=0;
	for (int i=0; s[i]; i++) {
		if (pv != s[i]) ret+= 10;
		else ret+= 5;
		pv = s[i];
	}
	printf("%d\n", ret);
	return 0;	
}