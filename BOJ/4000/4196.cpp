// baekjoon 4196 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

const int MAX=100001;

int N, M, SN, sn[MAX], dfsn[MAX], cnt, sOutdegree[MAX];
bool finished[MAX];
vector<vector<int> > adj;
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

	if (result == dfsn[here]) {
		vector<int> currSCC;
		while (1) {
			int t = st.top();
			st.pop();
			finished[t] = true;
			sn[t] = SN;
			if (t == here) break;
		}
		SN++;
		sort(currSCC.begin(), currSCC.end());
		SCC.push_back(currSCC);
	}
	return result;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &N, &M);
		adj = vector<vector<int> >(N);
		for (int i=0; i<M; i++) {
			int A, B;
			scanf("%d%d", &A, &B);
			adj[A-1].push_back(B-1);
		}
		cnt = SN = 0;
		SCC.clear();
		while (!st.empty()) st.pop();
		memset(finished, 0, sizeof(finished));
		memset(sn, 0, sizeof(sn));
		memset(dfsn, 0, sizeof(dfsn));
		for (int i=0; i<N; i++)
			if (dfsn[i] == 0)
				DFS(i);

		memset(sOutdegree, 0, sizeof(sOutdegree));
		for (int i=0; i<N; i++)
			for (int next: adj[i])
				if (sn[i] != sn[next])
					sOutdegree[sn[next]]++;

		int result = 0;
		for (int i=0; i<SN; i++)
			if (sOutdegree[i] == 0)
				result++;
		printf("%d\n", result);
	}

	return 0;
}