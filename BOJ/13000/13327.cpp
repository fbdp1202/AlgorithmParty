// baekjoon 13327 yechan
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
#define SQ(x) ((x)*(x))
typedef pair<int,int> P;
const int MAX_INF=2e9;
const int MAX_N=10006;

struct Tree{
	int x1, y1, x2, y2;
	Tree():x1(0),y1(0),x2(0),y2(0){}
	Tree(int x1, int y1, int x2, int y2):x1(x1),y1(y1),x2(x2),y2(y2){}
	Tree(const P &a, const P &b):x1(a.first),y1(a.second),x2(b.first),y2(b.second){}
};

int getDistance(int x1, int y1, int x2, int y2) {
	return SQ(x1-x2)+SQ(y1-y2);
}

int checkAll(const Tree &a, const Tree &b) {
	int ret = MAX_INF;
	ret = min(ret, getDistance(a.x1, a.y1, b.x1, b.y1));
	ret = min(ret, getDistance(a.x1, a.y1, b.x2, b.y2));

	ret = min(ret, getDistance(a.x2, a.y2, b.x1, b.y1));
	ret = min(ret, getDistance(a.x2, a.y2, b.x2, b.y2));
	return ret;
}

int getDist(const Tree &a, const Tree &b) {
	int aminx = min(a.x1, a.x2);
	int amaxx = max(a.x1, a.x2);
	int bminx = min(b.x1, b.x2);
	int bmaxx = max(b.x1, b.x2);
	if ((aminx <= b.x1 && b.x1 <= amaxx) || (aminx <= b.x2 && b.x2 <= amaxx) ||
		(bminx <= a.x1 && a.x1 <= bmaxx) || (bminx <= a.x2 && a.x2 <= bmaxx)) { // x값이 곂칠때
		return min(min(SQ(a.y1-b.y1),SQ(a.y1-b.y2)),min(SQ(a.y2-b.y1),SQ(a.y2-b.y2)));
	}
	int aminy = min(a.y1, a.y2);
	int amaxy = max(a.y1, a.y2);
	int bminy = min(b.y1, b.y2);
	int bmaxy = max(b.y1, b.y2);
	if ((aminy <= b.y1 && b.y1 <= amaxy) || (aminy <= b.y2 && b.y2 <= amaxy) ||
		(bminy <= a.y1 && a.y1 <= bmaxy) || (bminy <= a.y2 && a.y2 <= bmaxy)) { // y값이 곂칠때
		return min(min(SQ(a.x1-b.x1),SQ(a.x1-b.x2)),min(SQ(a.x2-b.x1),SQ(a.x2-b.x2)));
	}
	return checkAll(a, b);
}

int N, M;
int u, v, w, l;
P downland[MAX_N], upland[MAX_N]; // downland 0, upland W+1
Tree tree[MAX_N];

int dist[MAX_N];
bool visited[MAX_N];

int main()
{
	scanf("%d%d", &N, &M);
	scanf("%d%d%d%d", &u, &v, &w, &l);

	for (int i=0; i<u; i++)
		scanf("%d%d", &downland[i].first, &downland[i].second);
	for (int i=0; i<v; i++)
		scanf("%d%d", &upland[i].first, &upland[i].second);

	int x1, x2, y1, y2;
	for (int i=1; i<=w; i++) {
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		tree[i] = Tree(x1, y1, x2, y2);
	}

	fill(dist, dist+MAX_N, MAX_INF);
	for (int i=0; i<u; i++) {
		for (int j=1; j<=w; j++) {
			int value = getDist(Tree(downland[i], downland[(i+1)%u]), tree[j]);
			if (value <= l && dist[j] > value) dist[j] = value;
		}
	}

	for (int i=1; i<=w; i++) {
		int t = 0;
		for (int j=1; j<=w; j++)
			if (!visited[j] && dist[t] > dist[j])
				t = j;
		if (t == 0) break;
		visited[t] = true;
		for (int j=1; j<=w; j++) {
			if (!visited[j]) {
				int value = getDist(tree[t], tree[j]);
				if (value <= l && dist[j] > dist[t] + value) dist[j] = dist[t] + value;
			}
		}
	}


	int ans = 2e9;
	for (int i=0; i<u; i++) {
		for (int j=0; j<v; j++) {
			int value = getDist(Tree(downland[i], downland[(i+1)%u]), Tree(upland[j], upland[(j+1)%v]));
			if (value <= l && ans > value) ans = value;
		}
	}

	for (int i=1; i<=w; i++) {
		if (dist[i] == MAX_INF) continue;
		for (int j=0; j<v; j++) {
			int value = getDist(tree[i], Tree(upland[j], upland[(j+1)%v]));
			if (value <= l && ans > dist[i] + value) ans = dist[i] + value;
		}
	}
	printf("%d\n", ans == MAX_INF ? -1 : ans);
	return 0;
}