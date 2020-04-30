// baekjoon 1967 yechan
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxN = 10001;

struct Vertex{
	int v, w;
	Vertex(){}
	Vertex(int v, int w):v(v), w(w){}
};

struct Node{
	vector<Vertex> child;
};

int N, u, v, w, ans;
Node node[maxN];

int checkTree(int curr) {
	int rst = 0, maxV=0, secondV=0;
	for (Vertex nv : node[curr].child) {
		rst = checkTree(nv.v) + nv.w;
		if (rst > maxV){ secondV=maxV; maxV = rst; }
		else if (rst > secondV){ secondV = rst; }
	}
	ans = max(ans, maxV + secondV);
	return maxV;
}

int main() {
	scanf("%d", &N);
	for (int i=0; i<N-1; i++) {
		scanf("%d%d%d", &u, &v, &w);
		node[u].child.push_back(Vertex(v,w));
	}
	checkTree(1);
	printf("%d\n", ans);
	return 0;
}