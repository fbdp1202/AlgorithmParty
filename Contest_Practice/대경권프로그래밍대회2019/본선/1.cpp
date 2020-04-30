// 대경권 1.cpp
// 문제 설명
// 롤러코스터 문제
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N=1001;

int N, M, board[MAX_N][MAX_N];

int main() {
	scanf("%d%d", &N, &M);

	int ret = 0, minV = 1e9;

	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			scanf("%d", &board[i][j]);
			ret += board[i][j];
		}
	}

	if (N%2 == 0 && M%2 == 0) {
		for (int i=0; i<N; i++)
			for (int j=0; j<M; j++)
				if ( (i+j)%2 == 1)
					minV = min(minV, board[i][j]);
	}
	else minV = 0;

	printf("%d\n", ret-minV);
	return 0;
}