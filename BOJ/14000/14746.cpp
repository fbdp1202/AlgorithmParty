// baekjoon 14746 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N=500001;
int N, M;
int c1, c2;
int pline[MAX_N];
int qline[MAX_N];

int main()
{
	scanf("%d%d", &N, &M);
	scanf("%d%d", &c1, &c2);
	for (int i=0; i<N; i++)
		scanf("%d", &pline[i]);
	for (int i=0; i<M; i++)
		scanf("%d", &qline[i]);

	sort(pline, pline+N);
	sort(qline, qline+M);

	int ppos = 0;
	int qpos = 0;

	int ret = 2e9;
	int cnt = 0;
	while (1) {
		int diff = abs(pline[ppos]-qline[qpos]);
		if (ret > diff) {
			ret = diff;
			cnt = 1;
		} else if (ret == diff) {
			cnt++;
		}

		if (ppos == N-1 && qpos == M-1) break;

		if (ppos != N-1 && pline[ppos] <= qline[qpos]) {
			ppos++;
		} else if (qpos != M-1 && pline[ppos] >= qline[qpos]) {
			qpos++;
		} else {
			break;
		}
	}
	printf("%d %d\n", ret + abs(c1-c2), cnt);
	return 0;
}