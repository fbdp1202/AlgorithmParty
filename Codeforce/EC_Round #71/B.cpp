#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;

const int MAX_N=51;

int N, M, A[MAX_N][MAX_N], B[MAX_N][MAX_N];
stack<pair<int,int> > st;

bool check() {
	for (int i=0; i<N; i++)
		for (int j=0; j<M; j++)
			if (A[i][j] != B[i][j]) return false;

	return true;
}

void paint(int x, int y) {
	int cnt = 0;
	for (int i=x; i<x+2; i++) {
		for (int j=y; j<y+2; j++) {
			if (A[i][j]) {
				cnt++;
			}
		}
	}

	if (cnt == 4) {
		st.push({x,y});
		for (int i=x; i<x+2; i++) {
			for (int j=y; j<y+2; j++) {
				B[i][j] = 1;
			}
		}
	}
}

int main()
{
	scanf("%d%d", &N, &M);
	for (int i=0; i<N; i++)
		for (int j=0; j<M; j++)
			scanf("%d", &A[i][j]);

	for (int i=0; i<N-1; i++) {
		for (int j=0; j<M-1; j++) {
			paint(i, j);
		}
	}

	if (check()) {
		printf("%d\n", st.size());
		while (!st.empty()) {
			printf("%d %d\n", st.top().first+1, st.top().second+1);
			st.pop();
		}
	}
	else {
		printf("-1\n");
	}
	return 0;
}