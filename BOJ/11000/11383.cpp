// baekjoon 11383 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N, M;
char data[11][11];
char cdata[22];

int main() {
	scanf("%d%d", &N, &M);
	for (int i=0; i<N; i++)
		scanf("%s", data[i]);
	for (int i=0; i<N; i++) {
		scanf("%s", cdata);
		for (int j=0; j<M; j++) {
			for (int k=0; k<2; k++) {
				if (data[i][j] == cdata[j*2+k]) continue;
				return !printf("Not Eyfa\n");
			}
		}
	}
	puts("Eyfa");
	return 0;
}