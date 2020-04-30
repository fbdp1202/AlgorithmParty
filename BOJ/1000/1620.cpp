// baekjoon 1620 yechan
#include <cstdio>
#include <unordered_map>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX_N 100001

int N, M, num;
char data[MAX_N][22];
unordered_map<string, int> umap;

int main() {
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++) {
		scanf("%s", data[i]);
		umap[data[i]]=i;
	}
	for(int i=0; i<M; i++) {
		char f1[22];
		scanf("%s", f1);
		if('0' <= f1[0] && f1[0] <= '9'){
			num = 0;
			for(int j=0; j<strlen(f1); j++) {
				num *=10;
				num += f1[j] - '0';
			}
			printf("%s\n", data[num]);
		}
		else {
			printf("%d\n", umap[f1]);
		}
	}
	return 0;
}