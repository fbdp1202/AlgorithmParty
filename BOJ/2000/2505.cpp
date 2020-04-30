// baekjoon 2505 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=10002;

int N, step[MAX_N], s, e, ans[2][2];

int main() {
	scanf("%d", &N);
	for (int i=1; i<=N; ++i)
		scanf("%d", &step[i]);

	s=1;
	while (s <= N && step[s] == s) s++;
	if (s == N+1) return !printf("1 1\n1 1\n");

	e=s;
	while (step[e] != s) e++;
	ans[0][0] = s, ans[0][1] = e;
	reverse(step+s, step+e+1);

	s=1;
	while (s <= N && step[s] == s) s++;
	if (s == N+1) return !printf("%d %d\n1 1\n", ans[0][0], ans[0][1]);

	e=s;
	while (step[e] != s) e++;
	ans[1][0] = s, ans[1][1] = e;
	reverse(step+s, step+e+1);

	s=1;
	while (s <= N && step[s] == s) s++;
	if (s == N+1) return !printf("%d %d\n%d %d\n",ans[0][0],ans[0][1],ans[1][0],ans[1][1]);
	reverse(step+ans[1][0],step+ans[1][1]+1);
	reverse(step+ans[0][0],step+ans[0][1]+1);

	e=N;
	while (e >= 1 && step[e] == e) e--;
	s=e;
	while (s >= 1 && step[s] != e) s--;
	printf("%d %d\n", s, e);
	reverse(step+s, step+e+1);

	while (e >= 1 && step[e] == e) e--;
	if (e == 0) return !printf("1 1\n");

	s=e;
	while (s >= 1 && step[s] != e) s--;
	printf("%d %d\n", s, e);

	return 0;
}