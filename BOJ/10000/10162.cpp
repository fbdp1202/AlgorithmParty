// baekjoon 10162 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int T;
int A, B, C;
int button[3] ={300, 60, 10};

int main() {
	scanf("%d", &T);
	if (T%10 != 0) {
		printf("-1\n");
	} else {
		A = T/button[0];
		T -= button[0]*A;
		B = T/button[1];
		T -= button[1]*B;
		C = T/button[2];
		T -= button[2]*C;
		printf("%d %d %d\n", A, B, C);
	}
	return 0;
}