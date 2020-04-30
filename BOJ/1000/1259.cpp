// baekjoon 1259 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

char S[7];
int slen;

bool check() {
	for (int i=0; i<slen/2; i++)
		if (S[i] != S[slen-1-i])
			return false;

	return true;
}

int main() {
	while (1) {
		scanf("%s", S);
		if (S[0] == '0') break;
		for (slen=0; S[slen]; slen++);
		puts(check() ? "yes" : "no");
	}
	return 0;
}