// baekjoon 3566 yechan
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAX_N 100
#define INF 1e9

struct monitor{
	int data[5];
	monitor(){fill(data, data+5, 0);}
	monitor(int rh, int rv, int sh, int sv, int p){
		data[0] = rh;
		data[1] = rv;
		data[2] = sh;
		data[3] = sv;
		data[4] = p;
	}
	int price(monitor a) {
		int h = max(ceil((float)data[0]/a.data[0]), ceil((float)data[2]/a.data[2]));
		int w = max(ceil((float)data[1]/a.data[1]), ceil((float)data[3]/a.data[3]));
		int rh = max(ceil((float)data[1]/a.data[0]), ceil((float)data[3]/a.data[2]));
		int rw = max(ceil((float)data[0]/a.data[1]), ceil((float)data[2]/a.data[3]));
		return a.data[4]*min(h*w, rh*rw);;
	}
};

int N, price, rst=INF;
monitor dst, now, monitors[MAX_N];

int main() {
	int rh, rv, sh, sv, p;
	scanf("%d%d%d%d", &rh, &rv, &sh, &sv);
	dst = monitor(rh,rv,sh,sv, 0);
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf("%d%d%d%d%d", &rh, &rv, &sh, &sv, &p);
		monitors[i] = monitor(rh, rv, sh, sv, p);
	}

	for (int i=0; i<N; i++)
		rst = min(rst, dst.price(monitors[i]));

	printf("%d\n",rst);
	return 0;
}