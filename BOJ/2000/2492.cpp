// baekjoon 2492 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_T=101;

int N, M, T, K;
pair<int, int> stone[MAX_T];
int y[MAX_T], ret, ret_x, ret_y;

int main() {
	scanf("%d%d%d%d", &N, &M, &T, &K);
	for (int i=0; i<T; i++)
		scanf("%d%d", &stone[i].first, &stone[i].second);
	sort(stone, stone+T);
	for (int i=0, j=0; i<T; i++) {
		while (j<T && stone[j].first - stone[i].first <= K) j++;
		for (int k=0; k<j-i; k++) y[k] = stone[k+i].second;
		sort(y, y+j-i);
		for (int I=0, J=0; I<j-i; I++) {
			while (J<j-i && y[J] - y[I] <= K) J++;
			if (ret < J-I) {
				ret = J-I;
				ret_x = min(N, stone[i].first+K)-K;
				ret_y = min(M, y[I]+K);
			}
		}
	}
	printf("%d %d\n", ret_x, ret_y);
	printf("%d\n", ret);
	return 0;
}