// baekjoon 1964 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define DIV_NUM 45678LL
#define f(n) ( 3*(n)*(n) + 5*(n) + 2 )/(2LL)
typedef long long ll;
ll N;


int main() {
	scanf("%lld", &N);
	printf("%lld", f(N)%DIV_NUM);
	return 0;
}
