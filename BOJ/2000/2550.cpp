// baekjoon 2550 yechan
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX_N=10002;
const int SIZE=1<<14;

typedef pair<int, int> P;

int main() {
	int N, val;
	scanf("%d", &N);

	vector<int> idx(N+1);
	vector<int> rev(N+1);
	vector<int> arr(N+1);

	for (int i=1; i<=N; i++) {
		scanf("%d", &val);
		idx[val] = i;
		rev[i] = val;
	}
	for (int i=1; i<=N; i++) {
		scanf("%d", &val);
		arr[i] = idx[val];
	}

	vector<int> lis(N+1, MAX_N);
	vector<pair<int,int> > trace;

	for (int i=1; i<=N; i++) {
		auto it = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
		lis[it] = arr[i];
		trace.push_back({it, arr[i]});
	}

	int plis=0;
	for (int i=0; i<N; i++) {
		if (lis[i] == MAX_N) break;
		plis++;
	}
	plis--;

	int len = trace.size();

	vector<int> ansIdx;
	for (int i=len-1; i>=0; i--) {
		if (trace[i].first != plis) continue;

		ansIdx.push_back(trace[i].second);
		plis--;
	}

	vector<int> ans;
	for (int i=0; i<ansIdx.size(); i++) {
		ans.push_back(rev[ansIdx[i]]);
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (int i=0; i<ans.size(); i++)
		printf("%d ", ans[i]);
	puts("");

	return 0;
}