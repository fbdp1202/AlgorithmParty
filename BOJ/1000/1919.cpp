// baekjoon 1919 yechan
#include <cstdio>
#include <cmath>
using namespace std;

char buf[1001];
int i, result, alpha[26];

int main() {
	scanf(" %s", &buf);
	for (i=0; buf[i]; i++) alpha[buf[i]-'a']++;

	scanf(" %s", &buf);
	for (i=0; buf[i]; i++) alpha[buf[i]-'a']--;

	for (i=0; i<26; i++)
		result += abs(alpha[i]);

	printf("%d\n", result);
	return 0;
}