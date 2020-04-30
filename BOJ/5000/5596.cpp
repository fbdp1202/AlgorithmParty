// baekjoon 5596 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
int result1, result2, tmp;

int main() {
	for (int i=0; i<4; i++)
		scanf("%d", &tmp), result1+=tmp;
	for (int i=0; i<4; i++)
		scanf("%d", &tmp), result2+=tmp;
	printf("%d", max(result1, result2));
	return 0;
}