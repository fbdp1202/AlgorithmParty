// Codeforce B yechan
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct menu{
	int idx, c;
	menu():menu(0, 0){}
	menu(int idx, int c): idx(idx), c(c){}
	bool operator<(const menu& O) {
		if (c == O.c) {
			return idx < O.idx;
		} else {
			return c < O.c;
		}
	}
};

const int MAX_N = 100001;

int N, M, dishNum[MAX_N], dishCost[MAX_N];
menu data[MAX_N];

int main() {
	scanf("%d%d", &N, &M);
	for (int i=0; i<N; i++) {
		scanf("%d", &dishNum[i]);
	}
	for (int i=0; i<N; i++) {
		scanf("%d", &data[i].c);
		dishCost[i] = data[i].c;
		data[i].idx=i;
	}
	sort(data, data+N);
	int startPos = 0;
	while (M--) {
		int t, d, minidx;
		scanf("%d%d", &t, &d);
		long long ret = 0;
		if (dishNum[t-1] > d) {
			ret = 1LL*dishCost[t-1]*d;
			dishNum[t-1] -= d;
			d = 0;
		} else {
			if (dishNum[t-1]) {
				ret = 1LL*dishCost[t-1]*dishNum[t-1];
				d -= dishNum[t-1];
				dishNum[t-1] = 0;
			}
			for (int i=startPos; i<N; i++) {
				minidx = data[i].idx;
				if (dishNum[minidx] > d) {
					ret += 1LL*dishCost[minidx]*d;
					dishNum[minidx] -= d;
					d = 0;
					break;
				} else {
					if (dishNum[minidx]) {
						ret += 1LL*dishCost[minidx]*dishNum[minidx];
						d -= dishNum[minidx];
						dishNum[minidx] = 0;
					}
				}
				if (!dishNum[minidx]) startPos++;
			}
		}
		if (d) printf("0\n");
		else printf("%lld\n", ret);
	}

	return 0;
}
