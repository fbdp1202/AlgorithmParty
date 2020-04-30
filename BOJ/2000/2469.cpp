// baekjoon 2469 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_K=27;
const int MAX_N=1001;

int K, N, unknown, uppos, downpos;
int up[MAX_K], down[MAX_K];
char ladder[MAX_N][MAX_K];
char bottom[MAX_K];
char ans[MAX_K];
bool visited[MAX_K];

int main() {
	scanf("%d%d", &K, &N);
	scanf("%s", bottom);
	for (int i=0; i<N; i++) {
		scanf("%s", ladder[i]);
		if (ladder[i][0] == '?') unknown = i;
	}
	for (int i=0; i<K; i++) {
		up[i] = i;
		down[i] = bottom[i]-'A';
	}

	while (uppos < unknown) {
		memset(visited, 0, sizeof(visited));
		for (int i=0; i<K-1; i++) {
			if (!visited[up[i]] && ladder[uppos][i] != '*') {
				visited[up[i]]=visited[up[i+1]]=true;
				swap(up[i], up[i+1]);
			}
		}
		uppos++;
	}
	downpos=N-1;
	while (downpos > unknown) {
		memset(visited, 0, sizeof(visited));
		for (int i=0; i<K-1; i++) {
			if (!visited[down[i]] && ladder[downpos][i] != '*') {
				visited[down[i]]=visited[down[i+1]]=true;
				swap(down[i], down[i+1]);
			}
		}
		downpos--;
	}

	for (int i=0; i<K-1; i++) {
		if (up[i] == down[i]) ans[i]='*';
		else {
			if ((up[i] == down[i+1]) && (down[i] == up[i+1])) {
				ans[i]='-';
				ans[i+1]='*';
				i++;
			}
			else {
				for (int i=0; i<K-1; i++) {
					printf("x");
				}
				puts("");
				return 0;
			}
		}
	}

	ans[K-1]='\0';
	puts(ans);
	return 0;
}