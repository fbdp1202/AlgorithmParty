// baekjoon 1439 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=1000001;
char str[MAX_N];

int main() {
	scanf("%s", str);
	int black = 0, white = 0;
	if (str[0] == '1') black++;
	else white++;

	for (int i=1; str[i]; i++) {
		if (str[i-1] == '0' && str[i] == '1') black++;
		if (str[i-1] == '1' && str[i] == '0') white++;
	}
	printf("%d\n", min(black, white));
	return 0;
}