// baekjoon 11068 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int T, N;
int ans[20];

bool check(int n, int b) {
	int pos = 0;
	while (n) {
		ans[pos++] = n%b;
		n /= b;
	}
	pos--;
	for (int i=0; i<(pos+1)/2; i++)
		if (ans[i] != ans[pos-i])
			return false;
	return true;
}

bool ispossible(int n) {
	for (int b=2; b<=64; b++)
		if (check(n,b))
			return true;

	return false;
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		puts(ispossible(N)? "1" : "0");
	}
	return 0;
}