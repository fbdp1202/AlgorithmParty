// baekjoon 2526 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N, P, visited[98];
int main() {
	scanf("%d%d", &N,&P);
	int curr = N;
	int result = 0;
	while (1){
		curr = (curr*N)%P;
		visited[curr]++;
		if (visited[curr] == 3) break;
		if (visited[curr] == 2) result++;
	}
	printf("%d\n", result);
	return 0;
}