#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int,int> P;
const int MAX_N=101;
const int dir[4][2] = { {0,1}, {0,-1}, {1, 0}, {-1, 0} };
const int MAX_INF=1e9;

int N, M, dist[MAX_N*MAX_N];
char board[MAX_N][MAX_N];
bool visited[MAX_N*MAX_N];
vector<P> adj[MAX_N*MAX_N];

inline int encode(int x, int y) {
	return x*N+y;
}

inline void decode(int code, int &x, int &y) {
	x = code/N;
	y = code%N;
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i=0; i<M; i++)
		scanf("%s", board[i]);

	for (int i=0; i<M; i++) {
		for (int j=0; j<N; j++) {
			for (int d=0; d<4; d++) {
				int ni = i + dir[d][0];
				int nj = j + dir[d][1];
				if (ni < 0 || ni >= M || nj < 0 || nj >=N) continue;
				adj[encode(i,j)].push_back(P(encode(ni,nj), board[ni][nj]-'0'));
			}
		}
	}

	priority_queue<P, vector<P>, greater<P> > PQ;
	fill(dist, dist+N*M, MAX_INF);

	dist[0]=0;
	PQ.push(P(0, 0));

	while (!PQ.empty()) {
		int cur_x, cur_y, cur_code;
		do {
			cur_code = PQ.top().second;
			PQ.pop();
		} while (!PQ.empty() && visited[cur_code]);
		if (visited[cur_code]) break;
		visited[cur_code]=true;
		for (int i=0; i<adj[cur_code].size(); i++) {
			int ncode = adj[cur_code][i].first;
			int nw = adj[cur_code][i].second;
			if (dist[ncode] > dist[cur_code] + nw) {
				dist[ncode] = dist[cur_code] + nw;
				PQ.push(P(dist[ncode],ncode));
			}
		}
	}

	printf("%d\n", dist[encode(M-1, N-1)]);
	return 0;
}