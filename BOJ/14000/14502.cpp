// baekjoon 14502 yechan
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX_N 8
#define p1 first
#define p2 second
typedef pair<int, int> P;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int tmpMap[MAX_N][MAX_N], realMap[MAX_N][MAX_N];
int N, M, cnt, result;
bool visited[MAX_N][MAX_N];

vector<P> virus, space;

static void Copy_Map( void ) {
	for (int i=0; i<N; i++)
		for (int j=0; j<M; j++)
			tmpMap[i][j] = realMap[i][j];
}

static void FillVisited( void ) {
	for (int i=0; i<N; i++)
		for (int j=0; j<M; j++)
			visited[i][j]=false;
}

static void SetInputBuffer( void ) {
	scanf("%d %d", &N, &M);
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			scanf("%d", &realMap[i][j]);
			if (realMap[i][j] == 0)
				space.push_back(P(i, j));
			if (realMap[i][j] == 2)
				virus.push_back(P(i, j));
		}
	}
}

static void dfs(int x, int y) {
	if (x < 0 || y < 0 || x >= M || y >= N) return;

	if (visited[y][x] || tmpMap[y][x] == 1) return;

	visited[y][x]=true;
	tmpMap[y][x]=2;

	for (int d=0; d<4; d++) {
		int nx = dx[d] + x;
		int ny = dy[d] + y;
		dfs(nx, ny);
	}
}

static void InfectVirus( void ) {
	for (int v=0; v<virus.size(); v++) {
		int x = virus[v].p2;
		int y = virus[v].p1;
		dfs(x, y);
	}
}

static void AddWall(int a, int b, int c) {
	int x1 = space[a].p2, 	y1 = space[a].p1;
	int x2 = space[b].p2, 	y2 = space[b].p1;
	int x3 = space[c].p2, 	y3 = space[c].p1;
	tmpMap[y1][x1]=1;
	tmpMap[y2][x2]=1;
	tmpMap[y3][x3]=1;
}

static int getNumSpace() {
	cnt=0;
	for (int i=0; i<N; i++)
		for (int j=0; j<M; j++)
			if (!tmpMap[i][j])
				cnt++;
	return cnt;
}

static void FindMaxSize() {
	for (int i=0; i<space.size(); i++) {
		for (int j=i+1; j<space.size(); j++) {
			for (int z=j+1; z<space.size(); z++) {
				Copy_Map();
				FillVisited();
				AddWall(i, j, z);
				InfectVirus();
				result=max(result,getNumSpace());
			}
		}
	}
}

int main() {
	SetInputBuffer();
	Copy_Map();
	FindMaxSize();
	printf("%d", result);
}