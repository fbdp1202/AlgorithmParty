// baekjoon 10808 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

char str[101];
int num[26];

int main() {
	scanf("%s", str);
	for (int i=0; str[i]; i++)
		num[str[i]-'a']++;
	for (int i=0; i<26; i++)
		printf("%d ", num[i]);
	return 0;
}