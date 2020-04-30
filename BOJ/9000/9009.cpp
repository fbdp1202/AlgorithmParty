// baekjoon 9009 yechan
#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;

int T, N;
long long fibo[45];

int main()
{
	scanf("%d", &T);
	fibo[0] = 0;
	fibo[1] = 1;
	for (int i=2; i<45; i++)
		fibo[i] = fibo[i-1] + fibo[i-2];

	while (T--) {
		scanf("%d", &N);
		stack<int> s;
		for (int i=44; i>=0; i--) {
			if (N == 0) break;
			if (fibo[i] <= N) {
				N -= fibo[i];
				s.push(fibo[i]);
			}
		}
		while (!s.empty()) {
			printf("%d ", s.top());
			s.pop();
		}
		puts("");
	}
	return 0;
}