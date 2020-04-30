// baekjoon 8982 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int MAX_N=2501;

int N, K, a, b, c, d;
int height[MAX_N];
ll ret;
P point[MAX_N], hole[MAX_N];

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		if (i%2==0) point[i/2]={u,v};
	}
	N/=2;
	for (int i=1; i<N; i++)
		ret += point[i].second*(point[i].first - point[i-1].first);

	scanf("%d", &K);
	for (int i=0; i<K; i++) {
		scanf("%d%d%d%d", &a,&b,&c,&d);
		hole[i]={a,b};
	}
	sort(hole, hole+K);

	for (int i=0; i<K; i++) {
		int j=1;
		while (!(point[j].second == hole[i].second && point[j-1].first <= hole[i].first && hole[i].first <= point[j].first)) j++;
		if (height[j] == point[j].second) continue;

		ret -= 1LL*(hole[i].second - height[j])*(point[j].first - point[j-1].first);
		height[j] = hole[i].second;

		int lh = hole[i].second;
		int lj = j-1;
		//left
		while (lj>=1) {
			lh = min(lh, point[lj].second);
			if (!lh || height[lj] == lh) break;
			ret -= 1LL*(lh - height[lj])*(point[lj].first - point[lj-1].first);
			height[lj] = lh;
			lj--;
		}

		int rh = hole[i].second; 
		int rj = j+1;
		while (rj < N) {
			rh = min(rh, point[rj].second);
			if (!rh || height[rj] == rh) break;
			ret -= 1LL*(rh - height[rj])*(point[rj].first - point[rj-1].first);
			height[rj] = rh;
			rj++;
		}
	}
	printf("%lld\n", ret);
	return 0;
}