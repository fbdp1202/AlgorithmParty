#include <bits/stdc++.h>
using namespace std;

const int MAX_N=100001;

int N, M;
bool dest[MAX_N], start[MAX_N], go[MAX_N];
vector<int> adj[MAX_N];

int main() {
	scanf("%d%d", &N, &M);
	for (int i=0; i<M; i++) {
		int num; scanf("%d", &num);
		while (num--) {
			int x; scanf("%d", &x);
			adj[i].push_back(x-1);
		}
	}

	for (int i=0; i<N; i++) {
		int x; scanf("%d", &x);
		if (x == 1) dest[i] = start[i] = true;
	}

	for (int i=M-1; i>=0; i--) {
		bool check = true;
		for (int v : adj[i]) check &= start[v];
		if (!check)
			for (int v : adj[i])
				start[v] = false;
	}

	for (int i=0; i<N; i++) go[i] = start[i];

	for (int i=0; i<M; i++) {
		bool check = false;
		for (int v : adj[i]) check |= go[v];
		if (check)
			for (int v : adj[i])
				go[v] = true;
	}

	bool flag = true;
	for (int i=0; i<N; i++)
		flag &= !(go[i] ^ dest[i]);

	puts(flag ? "YES":"NO");
	if (flag) {
		for (int i=0; i<N; i++)
			printf("%d ", start[i]);
		puts("");
	}

	return 0;
}