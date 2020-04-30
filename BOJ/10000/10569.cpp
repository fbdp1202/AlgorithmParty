// baekjoon 10569 yechan
#include <cstdio>
using namespace std;

int main() {
	int T, V, E;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &V, &E);
		printf("%d\n", 2-(V-E));
	}
	return 0;
}