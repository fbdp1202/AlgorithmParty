// baekjoon 2162 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 3001
#define px first
#define py second
typedef pair<int, int> P;
typedef pair<P, P> PP;

int N;
PP line[MAX_N];

int Q_front_flag, Q_rear_flag;
int Queue[MAX_N*MAX_N];

#define ENQUEUE(x, Q_pos)	do { Queue[Q_pos] = x; Q_pos++; } while(0)
#define DEQUEUE(x, Q_pos)	do { x = Queue[Q_pos]; Q_pos++; } while(0)

bool visit[MAX_N][MAX_N], party[MAX_N];

int comp, max_size, comp_size, data;

static inline int getCCW(P a, P b, P c) {
	int op = a.px*b.py + b.px*c.py + c.px*a.py;
	op -= (a.py*b.px + b.py*c.px + c.py*a.px);
	if 		(op > 0) 	return 1;
	else if (op == 0) 	return 0;
	else 				return -1;
}

int checkOverlapLine(int first, int second){
	P a = line[first].first;
	P b = line[first].second;
	P c = line[second].first;
	P d = line[second].second;
	int ab = getCCW(a,b,c)*getCCW(a,b,d);
	int cd = getCCW(c,d,a)*getCCW(c,d,b);
	if (ab == 0 && cd == 0) {
		if (a > b) swap(a,b);
		if (c > d) swap(c,d);
		return  c <= b && a <= d;
	}
	return ab <= 0 && cd <= 0;
}

static void CheckUnvisitedNode(int y, int x) {
	if (!visit[y][x] && !party[x]) {
		if (CheckOverlapLine(y, x)) {
			comp--;
			comp_size++;
			max_size = max(max_size, comp_size);
			party[x] = true;
			ENQUEUE(x, Q_rear_flag);
		}
		visit[x][y] = true;
		visit[y][x] = true;
	}
}

static void BFS(int y) {
	party[y] = true;
	for (int i=0; i<N; i++) {
		CheckUnvisitedNode(y, i);
	}
}

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf("%d %d %d %d", &line[i].px.px, &line[i].px.py,
			   				 &line[i].py.px, &line[i].py.py );
		visit[i][i] = true;
	}
	comp = N; max_size = 1;
	for (int i=0; i<N; i++) {
		comp_size = 1;
		ENQUEUE(i, Q_rear_flag);
		do {
			DEQUEUE(data, Q_front_flag);
			BFS(data);
		} while (Q_front_flag != Q_rear_flag);
	}
	printf("%d\n%d", comp, max_size);
	return 0;
}