// baekjoon 1671 yechan
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 51
typedef struct _TAG_SHARK{
	int x, y, z;
}__SHARK;

__SHARK shark[MAX_N];
int N, eaten;
int A[MAX_N*2], B[MAX_N]; // A eater, B food
vector<int> adj[MAX_N*2];
bool visit[MAX_N*2];

static inline bool isEqual(int i, int j){
	return (shark[i].x == shark[j].x && 
			shark[i].y == shark[j].y && 
			shark[i].z == shark[j].z);
}

static inline bool isEqualbigger(int i, int j){
	return (shark[i].x >= shark[j].x && 
			shark[i].y >= shark[j].y && 
			shark[i].z >= shark[j].z);
}

static int isEater(int i, int j) {
	if (isEqual(i, j)){
		if (i < j) 	return 1;
		else 		return 0;
	}
	else if (isEqualbigger(i, j))
		return 1;
	return 0;
}

static void getFoods() {
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			if (isEater(i,j))
				adj[i*2].push_back(j), adj[i*2+1].push_back(j);
}

static bool dfs(int a) {
	visit[a] = true;
	for (int b: adj[a]) {
		if (B[b]==-1 || !visit[B[b]] && dfs(B[b])) {
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%d %d %d", &shark[i].x, &shark[i].y, &shark[i].z);
	getFoods();
	fill(A, A+MAX_N*2, -1);
	fill(B, B+MAX_N, -1);
	for (int i=0; i<N*2; i++) {
		fill(visit, visit+MAX_N*2, false);
		if (dfs(i)) eaten++;
	}
	printf("%d", N-eaten);
	return 0;
}