#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_N=300001;

int N, x, num, arr[MAX_N];
vector<int> adj_min[MAX_N];
vector<int> adj_max[MAX_N];
bool visited[MAX_N];

int dfs(int here) {
	int ret = 1e9;
	if (adj_max[here].size()) {
		for (int i=0; i<adj_max[here].size(); i++) {
			int nx = adj_max[here][i];
			if (!visited[nx]) return 1;
			else ret = min(ret, dfs(nx));
		}
	} else {
		int count = 0;
		for (int i=0; i<adj_min[here].size(); i++) {
			int nx = adj_min[here][i];
			if (!visited[nx]) count++;
			else count += dfs(nx);
		}
		ret = count;
	}
	return ret;
}

int main() {
	scanf("%d", &N);
	for (int i=1; i<=N; i++)
		scanf("%d", &arr[i]);
	for (int i=2; i<=N; i++) {
		scanf("%d", &x);
		visited[x]=true;
		if (arr[x]) adj_max[x].push_back(i);
		else adj_min[x].push_back(i);
	}
	
	for (int i=1; i<=N; i++)
		if (!visited[i])
			num++;

	int ret = dfs(1);
	printf("%d\n", num+1-ret);
	return 0;
}