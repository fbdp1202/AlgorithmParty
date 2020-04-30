// baekjoon 6064 yechan
#include <cstdio>
using namespace std;

int T, N, M, x, y, rst, curr_y;

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d %d", &M, &N, &x, &y);
		rst = x; curr_y = (x)%N; y%=N;
		while (curr_y != y && rst <= M*N) {
			curr_y = (curr_y+M)%N;
			rst+=M;
		}
		if(rst > M*N) 	printf("-1\n");
		else 			printf("%d\n", rst);
	}
	return 0;
}