// baekjoon 10826 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;

const int MAX_N=100001;

int N;
char fibo[3][MAX_N];

void adder(int here) {
	int sum = 0;
	for (int i=0; i<MAX_N; i++) {
		if (!sum && !fibo[(here-1)%3][i] && !fibo[(here-2)%3][i]) break;

		if (fibo[(here-1)%3][i]) sum += fibo[(here-1)%3][i]-'0';
		if (fibo[(here-2)%3][i]) sum += fibo[(here-2)%3][i]-'0';
		fibo[here%3][i] = (sum % 10) + '0';
		sum /= 10;
	}
}

int main() {
	scanf("%d", &N);
	fibo[0][0]='0';
	fibo[1][0]=fibo[2][0]='1';

	for (int i=3; i<=N; i++) {
		adder(i);
	}
	int idx = N%3;
	int slen = strlen(fibo[idx]);
	for (int i=slen-1; i>=0; i--)
		printf("%c", fibo[idx][i]);
	puts("");
	return 0;
}