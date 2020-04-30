// baekjoon 1969 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N, M, dist, data[51][26];
char buf[51];
int main() {
	scanf("%d %d", &N, &M);
	for (int i=0; i<N; i++) {
		scanf("%s", buf);
		for (int j=0; j<M; j++) {
			data[j][buf[j]-'A']++;
		}
	}

	for (int i=0; i<M; i++) {
		int max_value=0;
		for (int j=0; j<26; j++) {
			if (max_value < data[i][j]) {
				max_value = data[i][j];
				buf[i]='A'+j;
			}
		}
		dist += N-max_value;
	}
	printf("%s\n", buf);
	printf("%d", dist);
	return 0;
}