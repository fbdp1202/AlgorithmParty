// baekjoon 1002 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int T, x1, y1, r1, x2, y2, r2;
int long_r, short_r, dis, outer, dis_len, inner;


int main()
{
	scanf("%d", &T);
	for(int i=0; i<T; i++){
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		long_r = max(r1, r2);
		short_r = min(r1, r2);
		dis = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
		outer = (long_r+short_r)*(long_r+short_r);
		inner = (long_r-short_r)*(long_r-short_r);
		if(dis == 0){
			if(r1==r2) printf("-1\n");
			else printf("0\n");
		}
		else if(dis > outer) printf("0\n");
		else if(dis == outer ) printf("1\n");
		else{
			if(inner < dis) printf("2\n");
			else if(inner == dis) printf("1\n");
			else printf("0\n");
		}
	}
}