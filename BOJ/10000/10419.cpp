// baekjoon 10419 yechan
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int T, d; 
// t^2 + t - d = 0; (-b + sqrt(b^2-4ac))/2a;
// (-1 + sqrt(1+4d))/2

int fun(int distance) {
	return (int)((-1 + sqrt((double)(1+4*distance)))/2.f);
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &d);
		printf("%d\n", fun(d));
	}
	return 0;
}