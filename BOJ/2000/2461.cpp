// baekjoon 2461 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=1001;

int N, M;
int data[MAX_N][MAX_N];

int main() {
	scnaf("%d%d", &N,&M);
	for (int i=0; i<N; i++)
		for (int j=0; j<M; j++)
			scanf("%d", &data[i][j]);

	for (int i=0; i<N; i++)
		sort(data[i], data[i]+M);

	
	return 0;
}