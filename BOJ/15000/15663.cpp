// baekjoon 15663 yechan
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef pair<int, int> P;

int N, M;
P data[10];
map<P, int> visited;
map<vector<int>, int> m;
vector<int> v;

void backtracking() {
	if (v.size() == M && !m.count(v)) {
		m[v] = 1;
		return;
	}

	for (int i=0; i<N; i++) {
		if (v.size() < M) {
			if (!visited[data[i]]) {
				visited[data[i]] = 1;
				v.push_back(data[i].first);
				backtracking();
				v.pop_back();
				visited[data[i]] = 0;
			}
		}
	}
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i=0; i<N; i++) {
		int x; scanf("%d", &x);
		data[i].first = x;
		data[i].second = i;
	}
	sort(data, data+N);
	backtracking();
	for (auto ptrm = m.begin(); ptrm != m.end(); ptrm++) {
		for (auto i : ptrm->first)
			printf("%d ", i);
		puts("");
	}
	return 0;
}
