// baekjoon 2840 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=101;

int N, K, pos;
char str[MAX_N];

int main() {
	scanf("%d%d", &N, &K);
	for (int i=0; i<N; i++) str[i] = '?';
	for (int i=0; i<K; i++) {
		int x; char c;
		scanf("%d %c", &x, &c);
		x %= N;
		pos = (pos - x + N)%N;
		if (str[pos] == '?') str[pos] = c;
		else if (str[pos] != c) return !printf("!\n");
	}
	for (int i=0; i<N; i++)
		for (int j=i+1; j<N; j++)
			if (str[i] != '?' && str[i] == str[j])
				return !printf("!\n");

	for (int i=0; i<N; i++)
		printf("%c", str[(pos+i)%N]);
	puts("");
	return 0;
}