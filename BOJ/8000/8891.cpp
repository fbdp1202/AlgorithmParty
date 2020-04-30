// baekjoon 8891 yechan
#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int,int> P;

P getPos(int a) {
	int here = 0;
	int inc = 1;
	while (here < a) {
		if (here + inc >= a) {
			int tmp = a - here;
			return P(inc-tmp+1, tmp); // (y, x);
		}
		here += inc;
		inc++;
	}
	return P(-1, -1);
}

int getNumber(P x) {
	int here = x.first + x.second - 2;
	int ret = ((here+1)*(here)/2);
	return ret + x.second;
}

int main(){
	int T;
	scanf("%d", &T);
	while (T--) {
		int a, b;
		scanf("%d%d", &a, &b);
		P apos = getPos(a);
		P bpos = getPos(b);
		P cpos = P(apos.first + bpos.first, apos.second + bpos.second);
		printf("%d\n", getNumber(cpos));
	}
	return 0;
}