// baekjoon 3062 yechan
#include <bits/stdc++.h>
using namespace std;

int T, N;

int getReverse(int n) {
	int ret = 0;
	while (n) {
		ret *= 10;
		ret += n%10;
		n/=10;
	}
	return ret;
}

bool check(int n) {
	int str[100] = {0,};
	int pos = 0;
	while (n) {
		str[pos] += n%10;
		pos++;
		n/=10;
	}

	for (int i=0; i<pos/2; i++)
		if (str[i] != str[pos-i-1])
			return false;

	return true;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		printf("%s\n", check(N+getReverse(N)) ? "YES" : "NO");
	}
	return 0;
}