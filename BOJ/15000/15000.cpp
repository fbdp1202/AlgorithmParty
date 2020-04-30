// baekjoon 15000 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

char str[1000001];
int main()
{
	scanf("%s", str);
	for (int i=0; str[i]; i++) {
		printf("%c", str[i]-'a'+'A');
	}
	puts("");
	return 0;
}