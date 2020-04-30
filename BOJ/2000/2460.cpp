// baekjoon 2460 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
int up, down, curr, result;
int main() {
	for (int i=0; i<10; i++) {
		scanf("%d %d", &down, &up);
		curr += (up - down);
		result = max(result, curr);
	}
	printf("%d\n", result);
	return 0;
}