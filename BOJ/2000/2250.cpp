// baekjoon 2250 yechan
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAX_N 10001

typedef struct node{
	int left, right, parent;
	int pos, depth;
}Node;

int N, p, l, r, position[MAX_N][2];
int maxH, maxV, pos=1;
Node node[MAX_N];

void dfs(int root, int depth) {
	if (node[root].left) dfs(node[root].left, depth+1);

	position[depth][0] = min(position[depth][0], pos);
	position[depth][1] = max(position[depth][1], pos);

	int diff = position[depth][1]-position[depth][0]+1;
	if (maxV == diff && maxH > depth)
		maxH = depth;
	else if (maxV < diff)
		maxV = diff, maxH = depth;
	pos++;

	if (node[root].right) dfs(node[root].right, depth+1);
}

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf("%d %d %d", &p, &l, &r);
		if (l != -1) { 
			node[p].left = l;
			node[l].parent = p;
		}
		if (r != -1) {
			node[p].right = r;
			node[r].parent = p;
		}
	}

	for (int i=0; i<MAX_N; i++) {
		position[i][0] = 987654321;
	}

	int root = 0;
	for (int i=1; i<=N; i++) {
		if (!node[i].parent) {
			root=i;
			break;
		}
	}

	dfs(root, 1);
	printf("%d %d\n", maxH, maxV);
	return 0;
}