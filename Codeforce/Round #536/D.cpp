// codeforce D yechan
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX_N = 10001;

int N, M, u, v;
vector<int> data[MAX_N];
bool visited[MAX_N];

void backtracking(int i) {
	printf("%d ", i);
	visited[i]=true;
	for (int &next : data[i]) {
		if (visited[next]) continue;
		backtracking(next);
	}
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i=0; i<M; i++) {
		scanf("%d%d", &u, &v);
		data[u].push_back(v);
		data[v].push_back(u);
	}
	for (int i=1; i<=N; i++) {
		sort(data[i].begin(), data[i].end());
	}

	backtracking(1);
	return 0;
}