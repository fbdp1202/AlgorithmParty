// baekjoon 16673 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int C, K, P;

inline int funN(int n) { return (n*(n+1))/2; }
inline int funNN(int n) { return (n*(n+1)*(2*n+1))/6; }

int main() {
	scanf("%d%d%d", &C, &K, &P);
	printf("%d\n", funN(C)*K + funNN(C)*P);
	return 0;
}