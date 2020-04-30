// baekjoon 14867 yechan
#include <cstdio>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int MAX_INF=1e9;

int a, b, c, d;

inline ll encode(int x, int y) { return 1LL*y*100000 + 1LL*x; }
inline P decode(ll code){ return P(code%100000LL, code/100000LL); }

int bfs() {
	set<ll> visited;
	queue<ll> Q;

	Q.push(encode(0,0));
	visited.insert(encode(0,0));

	int t = 0;
	while (!Q.empty()) {
		int qSize = Q.size();
		for (int i=0; i<qSize; i++) {
			P p = decode(Q.front());
			Q.pop();
			int x = p.first, y = p.second;
			if (x == c && y == d) return t;

			int nx, ny, mv;
			ll next;
			nx = a; ny = y; next = encode(nx, ny);
			if (!visited.count(next)) { visited.insert(next); Q.push(next); }

			nx = x; ny = b; next = encode(nx, ny);
			if (!visited.count(next)) { visited.insert(next); Q.push(next); }

			nx = 0; ny = y; next = encode(nx, ny);
			if (!visited.count(next)) { visited.insert(next); Q.push(next); }

			nx = x; ny = 0; next = encode(nx, ny);
			if (!visited.count(next)) { visited.insert(next); Q.push(next); }

			mv = min(b-y, x); nx = x-mv; ny = y+mv; next = encode(nx, ny);
			if (!visited.count(next)) { visited.insert(next); Q.push(next); }

			mv = min(a-x, y); nx = x+mv; ny = y-mv; next = encode(nx, ny);
			if (!visited.count(next)) { visited.insert(next); Q.push(next); }
		}
		t++;
	}
	return MAX_INF;
}

int main() {
	scanf("%d%d%d%d", &a, &b, &c, &d);
	int ret = bfs();
	printf("%d\n", ret == MAX_INF ? -1 : ret);
	return 0;
}