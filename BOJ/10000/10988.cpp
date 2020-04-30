// baekjoon 10988 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N=101;

int slen;
char str[MAX_N];

bool check() {

	for (int i=0; i<=slen/2; i++)
		if (str[i] != str[slen-i])
			return false;

	return true;
}

int main() {
	scanf("%s", str);
	slen = (int)strlen(str); slen--;
	printf("%d\n", check());
}