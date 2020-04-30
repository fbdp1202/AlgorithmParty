// baekjoon 3111 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_L=300001;

int n, m, p;
char T[MAX_L], boom[26], ans[MAX_L];

bool isMatching(int h) {
	for (int i=h; i<h+m; i++) {
		if (ans[h] != boom[i-h]) return false;
	}
	return true;
}

int main() {
	scanf("%s%s", boom, T);
	n = (int)strlen(T);
	m = (int)strlen(boom);
	for (int i=0; i<n; i++) {
		ans[p++] = ans[i];
		if (p >= m && isMatching(p-m)) p-=m;
	}
	ans[p]='\0';
	puts(ans);
	return 0;
}