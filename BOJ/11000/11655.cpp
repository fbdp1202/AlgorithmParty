// baekjoon 11655 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

char S[111];

int main() {
	fgets(S, sizeof(S), stdin);
	for (int i=0; S[i]; i++) {
		if ('A' <= S[i] && S[i] <= 'Z') {
			char c = 'A' + (S[i]-'A'+13)%26;
			printf("%c", c);
		} else if ('a' <= S[i] & S[i] <= 'z') {
			char c = 'a' + (S[i]-'a'+13)%26;
			printf("%c", c);
		} else {
			printf("%c", S[i]);
		}
	}
	return 0;
}
