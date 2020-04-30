// baekjoon 2981 yechan
#include <cstdio>
#include <cmath>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N=101;

int N, arr[MAX_N], K;
vector<int> v;
set<int> s;

int gcd(int a, int b) {
	if (a < b) swap(a, b);

	if (a % b == 0) return b;
	return gcd(b, a%b);
}

void dfs(int here, int value) {
	if (here == K) {
		if (value != 1) s.insert(value);
		return;
	}
	dfs(here+1, value);
	dfs(here+1, value*v[here]);
}

int main()
{
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr+N);

	int ret = arr[1]-arr[0];
	for (int i=0; i<N-1; i++)
		ret = gcd(ret, arr[i+1]-arr[i]);

	int limit = sqrt(ret);
	for (int i=2; i<=limit; i++) {
		if (ret == 1) break;
		while (ret % i == 0) {
			v.push_back(i);
			ret /= i;
		}
	}
	if (ret != 1) v.push_back(ret);

	K = v.size();
	dfs(0, 1);
	for (set<int>::iterator it=s.begin(); it != s.end(); it++)
		printf("%d ", *it);
	puts("");
	return 0;
}