// baekjoon 2851 yechan
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int result = 0, x;
	for (int i=0; i<10; i++) {
		scanf("%d", &x);
		if ( abs(result-100) < abs(result+x-100)) break;
		result+=x;
	}
	printf("%d\n", result);
	return 0;
}