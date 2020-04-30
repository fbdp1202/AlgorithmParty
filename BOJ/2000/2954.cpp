// baekjoon 2954 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

char str[101];
int alpha[26];

int main()
{
	alpha['a'-'a']++;
	alpha['e'-'a']++;
	alpha['i'-'a']++;
	alpha['o'-'a']++;
	alpha['u'-'a']++;
	fgets(str, 101, stdin);
	for (int i=0; str[i]; i++) {
		printf("%c", str[i]);
		if (alpha[str[i]-'a']) i+=2;
	}
}