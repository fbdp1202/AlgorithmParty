// baekjoon 2484 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int N, ret = 0;
	scanf("%d", &N);
	while (N--) {
		pair<int,int> dice[6];
		for (int i=0; i<6; i++) {
			dice[i].first = 0;
			dice[i].second = i+1;
		}
		for (int i=0; i<4; i++) {
			int x;
			scanf("%d", &x);
			dice[x-1].first++;
		}
		sort(dice, dice+6);
		int ans = 0;
		if (dice[5].first == 4) {
			ans = 50000 + 5000*dice[5].second;
		} else if (dice[5].first == 3) {
			ans = 10000 + 1000*dice[5].second;
		} else if (dice[5].first == 2 && dice[4].first == 2) {
			ans = 2000 + 500*(dice[5].second + dice[4].second);
		} else if (dice[5].first == 2) {
			ans = 1000 + 100*dice[5].second;
		} else {
			ans = 100*dice[5].second;
		}
		ret = max(ret, ans);
	}
	printf("%d\n", ret);
	return 0;
}