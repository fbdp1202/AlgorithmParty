// baekjoon 5612 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int n, cars, s, maxS;

int main() {
	scanf("%d%d", &n, &s);
	for (int i=0; i<n; i++) {
		int x, y; scanf("%d%d",&x,&y);
		s+=x-y;
		maxS = max(maxS, s);
		if (s<0) return !printf("0");
	}
	return !printf("%d\n", maxS);
}