// baekjoon 4386 yechan
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

#define SQ(x) ((x)*(x))
const int MAX_N=1001;

typedef pair<double, double> P;

int N, M, root[MAX_N];
P star[MAX_N];

inline double dist(P &A, P &B) {
	return sqrt(SQ(A.first-B.first)+SQ(A.second-B.second));
}

int find(int x) {
	if (!root[x]) return x;
	return root[x]=find(root[x]);
}

bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;
	root[b] = a;
	return true;
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i=1; i<=N; i++)
		scanf("%lf %lf", &star[i].first, &star[i].second);
	while (M--) {
		int a, b;
		scanf("%d%d", &a, &b);
		merge(a,b);
	}

	vector<pair<double,pair<int,int> > > node;

	for (int i=1; i<N; i++) {
		for (int j=i+1; j<=N; j++) {
			node.push_back(make_pair(dist(star[i],star[j]), make_pair(i, j)));
		}
	}
	sort(node.begin(), node.end());

	double ret = 0;
	for (int i=0; i<node.size(); i++) {
		double w = node[i].first;
		int x = node[i].second.first;
		int y = node[i].second.second;
		if (merge(x, y)) {
			ret += w;
		}
	}
	printf("%.2lf\n", ret);
	return 0;
}