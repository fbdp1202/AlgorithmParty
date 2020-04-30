#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int MAX_N = 200001;

int N;
int data[MAX_N];
ll ret, tmp;

int main()
{
	scanf("%d", &N);
	tmp = (1LL*N*(N+1))/2;

	for (int i=1; i<=N; i++)
		scanf("%d", &data[i]);

	ll ans[2] = {0};
	int cnt = 0;
	int current = 0;
	for (int i=1; i<=N; i++) {
		if (data[i] > 0) cnt++;
		if (data[i] < 0) {
			ans[current] += 1 + cnt;
			cnt = 0;
			current ^= 1;
			ret += ans[current^1];
		} else {
			ret += ans[current^1];
		}
	}
	printf("%lld %lld\n", ret, tmp-ret);
	
	return 0;
}