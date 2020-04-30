// baekjoon 2594 yechan
#include <bits/stdc++.h>
using namespace std;

bool t[1440];

int N;

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		int x1, y1, x2, y2;
		int S, E;
		scanf("%02d%02d %02d%02d", &x1, &y1, &x2, &y2);
		S = x1*60 + y1 - 10;
		E = x2*60 + y2 + 10;
		for (int i=S; i<E; i++)
			t[i]=true;
	}

	int ret=0;
	int ans=0;
	for (int i=10*60; i<22*60; i++) {
		if (!t[i]) ans++, ret=max(ret, ans);
		else ans=0;
	}
	printf("%d\n", ret);
	return 0;
}