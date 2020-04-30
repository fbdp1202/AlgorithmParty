// baekjoon 2661 yechan
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAX_N=81;

int N;
int str[MAX_N];

void dfs(int here) {
	for (int i=1; i<=here/2; i++) {
		bool check = true;
		for (int j=0; j<i; j++)
			if (str[here-j-1] != str[here-i-j-1])
				check=false;
		if (check) return;
	}
	if (here == N) {
		for (int i=0; i<N; i++)
			printf("%d", str[i]);
		puts("");
		exit(0);
	}

	str[here] = 1;
	dfs(here+1);
	str[here] = 2;
	dfs(here+1);
	str[here] = 3;
	dfs(here+1);
}

int main() {
	scanf("%d", &N);
	dfs(0);
	return 0;
}