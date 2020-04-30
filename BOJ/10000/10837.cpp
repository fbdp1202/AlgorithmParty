// baekjoon 10837 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int K, C, M, N;
	scanf("%d%d", &K, &C);
	for (int i=0; i<C; i++) {
		scanf("%d%d", &M, &N);
		int cur_K = min(M, N);
		int diff = abs(M-N); // 점수 차이
		int remain = K - cur_K - diff; // 남은 경기수
		bool check = true;
		if (M > N && diff-1 > remain+1) check=false; // 한경기 더 가능
		if (M < N && diff-1 > remain) check=false;
		puts(check ? "1" : "0");
	}
	return 0;
}