// baekjoon 3595 yechan
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAX_N=1000001;

int N, ret = 1e9;

int A, B, C;

int getSize(int a, int b, int c) {
	return (a*b + a*c + b*c);
}

int main()
{
	scanf("%d", &N);

	for (int i=1; i<=sqrt(N); i++) {
		if (N % i == 0) {
			int M = N/i;
			for (int j=1; j<=sqrt(M); j++) {
				if (M % j == 0) {
					if (getSize(i, j, M/j) < ret) {
						ret = getSize(i, j, M/j);
						A = i, B = j, C = M/j;
					}
				}
			}
		}
	}
	printf("%d %d %d\n", A, B, C);
	return 0;
}