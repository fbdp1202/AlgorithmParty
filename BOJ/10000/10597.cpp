// baekjoon 10597 yechan
#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;

const int MAX_N=92;

int N, slen;
char str[MAX_N];
bool visited[MAX_N];
vector<P> ret;

bool dfs(int here) {
	if (here == 0) return true;

	if (here >= 10) {
		int f = here/10;
		int s = here%10;
		for (int i=0; i<slen-1; i++) {
			if ((str[i] == '0' + f) && !visited[i] &&
				(str[i+1] == '0' + s) && !visited[i+1]) {
				visited[i] = visited[i+1] = true;
				bool ans = dfs(here - 1);
				if (ans) {
					ret.push_back(P(i, here));
					return true;
				}
				visited[i] = visited[i+1] = false;
			}
		}
	} else {
		for (int i=0; i<slen; i++) {
			if ((str[i] == '0' + here) && !visited[i]) {
				visited[i] = true;
				bool ans = dfs(here - 1);
				if (ans) {
					ret.push_back(P(i, here));
					return true;
				}
				visited[i] = false;
			}
		}
	}
	return false;
}

int main() {
	scanf("%s", str);
	slen = strlen(str);
	if (slen >= 10) N = 9 + (slen-9)/2;
	else N = slen;
	dfs(N);
	sort(ret.begin(), ret.end());
	for (auto ans: ret)
		printf("%d ", ans.second);
	puts("");
	return 0;
}