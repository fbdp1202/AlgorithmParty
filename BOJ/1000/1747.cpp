// baekjoon 1747 yechan
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int N;
int pos;
int str[11];

void int_to_char(int x) {
	pos = 0;
	while (x) {
		str[pos++]=(x%10);
		x/=10;
	}
}

bool isprime(int x) {
	if (x <= 1) return false;
	int limit = sqrt(x);
	for (int i=2; i <= limit; i++)
		if (x % i == 0)
			return false;
	return true;
}

bool checkPtm() {
	int limit = pos/2;
	for (int i=0; i<=limit; i++)
		if (str[i] != str[pos-i-1])
			return false;
	return true;
}

int main()
{
	scanf("%d", &N);
	while (1)
	{
		if (!isprime(N)) {
			N++; continue;
		}
		int_to_char(N);
		if (checkPtm()) {
			break;
		}
		N++;
	}
	printf("%d\n", N);
	return 0;
}