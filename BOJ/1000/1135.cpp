#include <bits/stdc++.h>
using namespace std;

const int MAX_N=51;

int N;
int arr[MAX_N];
vector<int> adj[MAX_N];

int dfs(int here) {
	int limit = adj[here].size();
	if (limit == 0) return 0;

	vector<int> v;
	for (int nx : adj[here]) v.push_back(dfs(nx));
	sort(v.begin(), v.end());

	int ret = 0;
	for (int i=0; i<limit; i++)
		ret = max(ret, v[i] + limit - i);
	return ret;
}

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] == -1) continue;
		adj[arr[i]].push_back(i);
	}
	printf("%d\n", dfs(0));
	return 0;
}