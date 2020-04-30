// baekjoon 9339 yechan
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
// 기록 = 60*x + y, index, 번호
#define MAX_N 1001
typedef pair<pair<int, int>, int> P;

int T, K, N;
P runner[MAX_N];
int data[101];

int main() {
	scanf("%d", &T);
	while (T--) {
		set<int> s;
		scanf("%d", &K);
		for (int i=0; i<K; i++) {
			int x; scanf("%d", &x);
			s.insert(x);
			data[i]=x;
		}
		scanf("%d", &N);
		int idx, m, sec;
		int pos;
		int cnt = 0;
		for (int i=0; i<N; i++) {
			scanf("%d%d%d", &idx, &m, &sec); pos=0;
			if (s.count(idx) && m != -1 && m*60+sec <= 360) {
				while (data[pos]!=idx) { pos++; }
				runner[cnt].first.first = 60*m + sec;
				runner[cnt].first.second = pos;
				runner[cnt].second = idx;
				cnt++;
			}
		}
		sort(runner, runner+cnt);
		printf("%d %d\n", runner[0].second, cnt);
	}
	return 0;
}