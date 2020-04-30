// baekjoon 10829 yechan
#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;

long long N;
stack<int> s;

int main()
{
	scanf("%lld", &N);
	while (N) {
		s.push(N & 1);
		N >>= 1;
	}
	while (!s.empty()) {
		printf("%d", s.top());
		s.pop();
	}
}