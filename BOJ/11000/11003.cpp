// baekjoon 11003 yechan
#include <cstdio>
#include <algorithm>
#include <deque>
using namespace std;
typedef pair<int,int> P;

int N, L, x, dsize;
deque<P> dq;

int main()
{
	scanf("%d%d", &N, &L);
	for (int i=1; i<=N; i++)
	{
		while (dsize && dq.front().second <= i-L) {
			dq.pop_front();
			dsize--;
		}
		scanf("%d", &x);
		while (dsize && dq.back().first >= x) {
			dq.pop_back();
			dsize--;
		}
		dsize++;
		dq.push_back({x, i});
		printf("%d ", dq.front().first);
	}
	return 0;
}