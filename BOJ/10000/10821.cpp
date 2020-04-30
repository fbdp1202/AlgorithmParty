// baekjoon 10821 yechan
#include <bits/stdc++.h>
using namespace std;

char S[111];

int main() {
	fgets(S, 111, stdin);
	int ret=1;
	for (int i=0; S[i]; i++)
		if (S[i] == ',') ret++;
	printf("%d\n", ret);
	return 0;
}