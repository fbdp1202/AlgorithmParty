// baekjoon 2231 yechan
#include <bits/stdc++.h>
using namespace std;

int N;

bool isDivSum(int n) {
	int sum = n;
	while (n) {
		sum += n%10;
		n/=10;
	}
	return sum == N;
}

int main() {
	scanf("%d", &N);
	for (int i=1; i<N; i++)
		if (isDivSum(i))
			return !printf("%d\n", i);

	printf("%d\n", 0);
	return 0;
}