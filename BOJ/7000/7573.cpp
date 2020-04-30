// baekjoon 7573 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_M=101; 
typedef pair<int, int> P;

int N, I, M, ans, x, y, i, j, a, b, bias, cur_x, cur_y, bottom_x, bottom_y, ret;
P fish[MAX_M];

int main() {
	scanf("%d%d%d", &N, &I, &M);
	for (int i=0; i<M; i++)
		scanf("%d%d", &fish[i].first, &fish[i].second);
	sort(fish, fish+M);
	I/=2;
	for (i=0; i<M; i++) {
		x = fish[i].first;
		y = fish[i].second;
		for (a=1; a<I; a++) {
			for (bias=0; bias<=I-a; bias++) {
				b = I-a;
				cur_x = x;
				cur_y = y - bias;
				bottom_x = cur_x + a;
				bottom_y = cur_y + b;
				ret = 0;
				for (j=i; j<M; j++) {
					if (bottom_x < fish[j].first) break;
					if (cur_y <= fish[j].second && fish[j].second <= bottom_y) ret++;
				}
				ans = max(ret, ans);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}