// baekjoon 2503 yechan
#include <bits/stdc++.h>
using namespace std;

int N;
bool ball[1001];

bool check(int a, int b, int strike, int ball) {
	int a1 = a/100, a2 = (a/10)%10, a3 = a%10;
	int b1 = b/100, b2 = (b/10)%10, b3 = b%10;
	int snum = (a1==b1) + (a2==b2) + (a3==b3);
	int bnum = (a1==b2) + (a1==b3) + (a2==b1) + (a2==b3) + (a3==b1) + (a3==b2);
	return (strike == snum) && (ball == bnum);
}

int main() {
	for (int i=1; i<10; i++)
		for (int j=1; j<10; j++)
			for (int k=1; k<10; k++) {
				if (i == j || j == k || i == k) continue;
				ball[i*100+j*10+k]=true;
			}

	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		int Q, S, B;
		scanf("%d%d%d", &Q, &S, &B);
		for (int j=0; j<1000; j++) {
			if (!ball[j]) continue;
			if (!check(Q, j, S, B)) ball[j]=false;
		}
	}

	int ret = 0;
	for (int i=0; i<1000; i++)
		if (ball[i])
			ret++;
	printf("%d\n", ret);
	return 0;
}