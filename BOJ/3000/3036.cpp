// baekjoon 3036 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 1001

int data[MAX_N];

int gcd(int a, int b) {
	while (b != 0) {
		int r = a%b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	int N;
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf("%d", &data[i]);
	}

	for (int i=1; i<N; i++) {
		int g = gcd(data[0], data[i]);
		printf("%d/%d\n",data[0]/g, data[i]/g);
	}
	return 0;
}