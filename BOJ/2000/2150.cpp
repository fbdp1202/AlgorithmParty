// baekjoon 2150 yechan
#include <cstdio>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

const int MAX=10001;

int V, E, sn[MAX], SN, cnt, dfsn[MAX];
vector<int> adj[MAX];
bool finished[MAX];
vector<vector<int> > SCC;
stack<int> st;

int DFS(int here) {
	dfsn[here] = ++cnt;
	st.push(here);

	int result = dfsn[here];

	for (int next: adj[here]) {
		if (dfsn[next] == 0) result = min(result, DFS(next));
		else if (!finished[next]) result = min(result, dfsn[next]);
	}

	if (dfsn[here] == result) {
		vector<int> currSCC;
		while (1) {
			int t = st.top();
			st.pop();
			sn[t] = SN;
			finished[t] = true;
			currSCC.push_back(t);
			if (t == here) break;
		}
		sort(currSCC.begin(), currSCC.end());
		SCC.push_back(currSCC);
		SN++;
	}
	return result;
}


int main() {
	scanf("%d%d", &V, &E);
	for (int i=0; i<E; i++) {
		int A, B;
		scanf("%d%d", &A, &B);
		adj[A-1].push_back(B-1);
	}
	for (int i=0; i<V; i++)
		if (dfsn[i] == 0)
			DFS(i);

	sort(SCC.begin(), SCC.end());

	printf("%d\n", SN);

	for (auto& currSCC: SCC) {
		for (int curr: currSCC) {
			printf("%d ", curr+1);
		}
		puts("-1");
	}
	return 0;
}
