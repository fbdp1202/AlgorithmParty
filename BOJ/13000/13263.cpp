#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000;

struct LinearFunc{
	long long a, b;
	double s;
	LinearFunc(): LinearFunc(1, 0){}
	LinearFunc(long long a1, long long b1):a(a1),b(b1),s(0){}
};

inline double cross(LinearFunc &f, LinearFunc &g) {
	return (g.b-f.b)/(f.a-g.a);
}

int N, A[MAX], B[MAX];
long long dp[MAX];
LinearFunc f[MAX];

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%d", A+i);
	for (int i=0; i<N; i++)
		scanf("%d", B+i);

	// dp[0] = 0, dp 테이블을 채우면서 "f(.)=B[i]*x + dp[i]"를 스택에 쌓음
	int top = 0;
	for (int i=1; i<N; i++) {
		// i-1 번에 해당하는 새로운 직선을 스택의 top에 쌓음
		LinearFunc g(B[i-1], dp[i-1]);
		while (top > 0) {
			g.s = cross(f[top-1], g);
			if (f[top-1].s < g.s) break;
			// 쌓기 전에, top과 교점을 구해서 top의 시작점보다 교점이 앞이면 pop
			--top; 
		}
		f[top++] = g;

		long long x = A[i];
		int fpos = top-1;
		if (x < f[top-1].s) {
			int lo = 0, hi = top-1;
			while (lo+1 < hi) {
				int mid = (lo+hi)/2;
				(x < f[mid].s ? hi : lo) = mid;
			}
			fpos = lo;
		}
		// i번째 dp 값 계산
		dp[i] = f[fpos].a * x + f[fpos].b;
	}
	printf("%lld\n", dp[N-1]);

	return 0;
}
