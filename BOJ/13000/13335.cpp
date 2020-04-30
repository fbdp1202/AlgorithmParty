// baekjoon 13335 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N=1001;
const int MAX_W=101;

int N, W, L, pos;
int track[MAX_N];
int bridge[MAX_W];

int main()
{
	scanf("%d%d%d", &N, &W, &L);
	for (int i=0; i<N; i++)
		scanf("%d", &track[i]);

	int t;
	int sum = 0;
	int i = 0; // track pos
	pos = 0;
	for (t=1; ; t++) {
		sum -= bridge[pos];
		bridge[pos] = 0;
		if ((sum == 0) && (i == N)) break;

		if (i < N && (sum + track[i] <= L)) {
			sum += track[i];
			bridge[pos] = track[i];
			i++;
		}
		pos = (pos+1)%W;
	}
	printf("%d\n", t);
	return 0;
}