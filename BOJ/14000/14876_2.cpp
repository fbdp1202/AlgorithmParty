// baekjoon 14876 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N, M, a, b, wa, wb, ret, total;

int main() {
	scanf("%d%d%d%d", &N, &M, &a, &b);

	if (a > N || b > M) return !printf("-1\n");
	if (a == N && b == M) return !printf("2\n");
	if (a == 0 && b == 0) return !printf("0\n");

	while (!(wa == N && wb == M)) {
		if (wa == 0) wa = N; // fill A
		else if (wb == M) wb = 0; // empty B
		else {
			if (wa > M - wb) { // A -> B
				wa = wa - (M - wb);
				wb = M;
			}
			else { // A <- B
				wb += wa;
				wa = 0;
			}
		}
		total++;
		if (wa == a && wb == b) ret = total;
	}
	if (!ret) return !printf("-1\n");

	printf("%d\n", min(ret, total-ret)); // reverse case
	return 0;
}