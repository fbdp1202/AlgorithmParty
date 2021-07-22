2020 ICPC Cheetsheet

---

## 개요

> 히스토그램 문제
> Union Find
> Segment Tree
> 선분교차
> 다익스트라 알고리즘
> 벨만 포드 알고리즘
> SCC 알고리즘
> BCC
> 2-SAT SCC
> Network Flow
> 이분 매칭
> MCMF (SPFA 알고리즘)
> LCA
> Laze Propagation
> Convex Hull
> DP Convex Hull Trick
> KMP
> 삼분탐색
> Segment Tree 금광
> LIS 알고리즘
> BFS

---

## 히스토그램 문제

```c++
ll ret=0;
stack<int> st;
for (int i=0; i<N; i++) {
    while (!st.empty() && H[st.top()] > H[i]) {
        int height = H[st.top()];
        st.pop();
        int width = i;
        if (!st.empty()) width=i-st.top()-1;
        ret=max(ret, 1LL*height*width);
    }
    st.push(i);
}
while (!st.empty()) {
    int height = H[st.top()];
    st.pop();
    int width = N;
    if (!st.empty())
        width = N-st.top()-1;
    ret=max(ret, 1LL*height*width);
}
printf("%lld\n", ret);
```

---

## Union Find

```c++
int find(int n){
    if(p[n] < 0) return n;
    return p[n] = find(p[n]);
}
void merge(int a, int b){
    a = find(a); b = find(b);
    if(a == b) return;
//  p[a] += p[b]; // optional
    p[b] = a;
}
```

---

## Segment Tree

```c++
int sum(int L, int R, int nodeNum, int nodeL, int nodeR){
    if(R < nodeL || nodeR < L) return 0;
    if(L <= nodeL && nodeR <= R) return arr[nodeNum];
    int mid = (nodeL + nodeR) / 2;
    return sum(L, R, nodeNum*2, nodeL, mid) + sum(L, R, nodeNum*2+1, mid+1, nodeR);
}
void update(int i, int val){
    i += size;
    arr[i] = val;
    while(i > 1){
        i /= 2;
        arr[i] = arr[i*2] + arr[i*2+1];
    }
}
void construct(){
    for(int i = MAX_ST/2-1; i > 0; --i)
        arr[i] = arr[i*2] + arr[i*2+1];
}
```

---

## 선분교차

```c++
int getCCW(Point a, Point b, Point c) {
	int res = (a.x*b.y + b.x*c.y + c.x*a.y);
	res -= (a.x*c.y + b.x*a.y + c.x*b.y);
	return (res) ? ((res < 0) ? -1 : 1) : 0;
}
int isISTPoint(Line rline, Line line) {
	Point a = line.pos[0], b = line.pos[1];
	Point c = rline.pos[0], d = rline.pos[1];
	int ccw[4];
	ccw[0] = getCCW(a, b, c), ccw[1] = getCCW(a, b, d);
	ccw[2] = getCCW(c, d, a), ccw[3] = getCCW(c, d, b);

    int ab = ccw[0]*ccw[1];
	int cd = ccw[2]*ccw[3];
	if (ccw[0] == 0 && ccw[0] == ccw[1]) {
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		if (ccw[2] == 0 && ccw[2] == ccw[3]) { // 평행할때
			if (b < c || d < a) return 0; // 평행 하지만 겹치지 않음
			if (b == c || d == a) return 1; // 1점만 겹침
			return -1; // 해가 많음 (4)
		}
		return 1;
	}
	return (ab <= 0 && cd <= 0);
}
```

---

## 다익스트라 알고리즘

```c++
int dist[MAX_V];
fill(dist, dist+MAX_V, INF);
bool visited[MAX_V] = {0};
priority_queue<P, vector<P>, greater<P>> PQ;

dist[K] = 0; // 시작점으로의 거리는 0
PQ.push(P(0, K)); // 시작점만 PQ에 넣고 시작
while(!PQ.empty()){ // PQ가 비면 종료
    int curr;
    do{
        curr = PQ.top().second;
        PQ.pop();
    }while(!PQ.empty() && visited[curr]);
    if(visited[curr]) break;

    visited[curr] = true; // 방문
    for(auto &p: adj[curr]){
        int next = p.first, d = p.second;
        if(dist[next] > dist[curr] + d){
            dist[next] = dist[curr] + d;
            PQ.push(P(dist[next], next));
        }
    }
}
```

---

## 벨만 포드 알고리즘

```c++
bool minusCycle = false;
fill(dist, dist+N, INF);
dist[0] = 0;
for(int i=0; i<N; i++){ // (N-1) + 1번의 루프. 마지막은 음의 싸이클 존재 여부 확인용
    for(int j=0; j<N; j++){
        for(auto &p: adj[j]){
            int next = p.first, d = p.second;
            if(dist[j] != INF && dist[next] > dist[j] + d){
                dist[next] = dist[j] + d;
                // N번째 루프에 값이 갱신되면 음의 싸이클이 존재한다.
                if(i == N-1) minusCycle = true;
            }
        }
    }
}
if(minusCycle) puts("-1");
```

---

## SCC 알고리즘

```c++
// SN: SCC 개수, sn[i]: i가 속한 SCC의 번호
int V, E, cnt, dfsn[MAX], SN, sn[MAX];
vector<int> adj[MAX];
bool finished[MAX]; // SCC 분리가 끝난 정점만 true
stack<int> S;
vector<vector<int>> SCC;

int GetSCCsByDFS(int curr){
    dfsn[curr] = ++cnt; // dfsn 결정
    S.push(curr); // 스택에 자신을 push
 
    // 자신의 dfsn, 자식들의 결과나 dfsn 중 가장 작은 번호를 result에 저장
    int result = dfsn[curr];
    for(int next: adj[curr]){
        // 아직 방문하지 않은 이웃
        if(dfsn[next] == 0) result = min(result, GetSCCsByDFS(next));
        // 방문은 했으나 아직 SCC로 추출되지는 않은 이웃
        else if(!finished[next]) result = min(result, dfsn[next]);
    }
 
    // 자신, 자신의 자손들이 도달 가능한 제일 높은 정점이 자신일 경우 SCC 추출
    if(result == dfsn[curr]){
        vector<int> currSCC;
        // 스택에서 자신이 나올 때까지 pop
        while(1){
            int t = S.top();
            S.pop();
            currSCC.push_back(t);
            finished[t] = true;
            sn[t] = SN;
            if(t == curr) break;
        }
        sort(currSCC.begin(), currSCC.end());
        SCC.push_back(currSCC);
        SN++;
    }
    return result;
}

int main() {
    for(int i=0; i<V; i++)
        if(dfsn[i] == 0) GetSCCsByDFS(i);
}
```

---

## BCC

```c++
int V, E, dcnt, dfsn[MAX];
vector<int> adj[MAX];
stack<P> S;
vector<vector<P>> bcc;
 
int DFS(int curr, int prev = -1){
    // 이 정점에 dfsn 부여
    // result는 DFS 트리상에서 트리, 역방향 간선으로 도달 가능한 최소의 dfsn
    int result = dfsn[curr] = ++dcnt;
 
    // 인접한 정점 순회
    for(int next: adj[curr]){
        // DFS 트리상에서 자신의 부모면 스킵
        if(next == prev) continue;
 
        // 아직 방문하지 않은 간선이면 스택에 간선 (curr, next)을 넣음
        if(dfsn[curr] > dfsn[next]) S.push(P(curr, next));
        // 역방향 간선
        if(dfsn[next] > 0) result = min(result, dfsn[next]);
        // 트리 간선
        else{
            // DFS로 이어서 탐색
            int temp = DFS(next, curr);
            result = min(result, temp);
            // next가 DFS 트리상에서 curr의 조상 노드로 갈 수 없음: 새 BCC 발견
            if(temp >= dfsn[curr]){
                // 여태 스택에 쌓여있던 간선을 빼서 BCC 구성
                // 이때, 간선 (curr, next)까지만 빼내야 함
                vector<P> currBCC;
                while(!S.empty() && S.top() != P(curr, next)){
                    currBCC.push_back(S.top());
                    S.pop();
                }
                currBCC.push_back(S.top());
                S.pop();
                bcc.push_back(currBCC);
            }
        }
    }
    return result;
}
```

---

## 2-SAT SCC

```c++
int N, M, cnt, scc, dfsn[MAX*2], sn[MAX*2];
vector<int> adj[MAX*2];
bool finished[MAX*2];
stack<int> S;
 
inline int oppo(int n){ return n%2 ? n-1 : n+1; }
 
int main(){
    scanf("%d %d", &N, &M);
    for(int i=0; i<M; i++){
        int A, B;
        scanf("%d %d", &A, &B);
        // x_k: (k-1)*2, not x_k: (k-1)*2-1
        A = (A<0 ? -(A+1)*2 : A*2-1);
        B = (B<0 ? -(B+1)*2 : B*2-1);
        adj[oppo(A)].push_back(B); // not A -> B
        adj[oppo(B)].push_back(A); // not B -> A
    }
 
    for(int i=0; i<N*2; i++)
        if(dfsn[i] == 0) GetSCCsByDFS(i);
 
    for(int i=0; i<N; i++)
        if(sn[i*2] == sn[i*2+1])
            puts("0");
}
```

---

## Network Flow

```c++
struct Edge{
	int to, c, f;
	Edge *dual;
	Edge(): Edge(-1, 0){}
	Edge(int to1, int c1): to(to1), c(c1), f(0), dual(nullptr){}

    int spare() {
		return c - f;
	}
	void addFlow(int f1) {
		f += f1;
		dual->f -= f1;
	}
};

int N, M;
int pv[MAX_N];
vector<Edge*> adj[MAX_N];
Edge *path[MAX_N];

int main() {
	scanf("%d%d", &N, &M);
	for (int i=0; i<M; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		Edge *e1 = new Edge(v, 1), *e2 = new Edge(u, 0);
		e1->dual = e2;
		e2->dual = e1;
		adj[u].push_back(e1);
		adj[v].push_back(e2);
	}

	int total=0, S=1, E=2;
	while (1) {
		memset(pv, -1, sizeof(pv));
		memset(path, 0, sizeof(path));
		queue<int> Q;
		Q.push(S);
		while (!Q.empty() && pv[E] == -1) {
			int curr = Q.front();
			Q.pop();
			for (Edge *e: adj[curr]) {
				int next = e->to;
				if (e->spare() > 0 && pv[next] == -1) {
					Q.push(next);
					pv[next] = curr;
					path[next] = e;
					if (next == E) break;
				}
			}
		}
		if (pv[E] == -1) break;

		int flow = MAX_INF;
		for (int i=E; i!=S; i=pv[i]) flow = min(flow, path[i]->spare());
		for (int i=E; i!=S; i=pv[i]) path[i]->addFlow(flow);
		total += flow;
	}
	return 0;
}
```

---

## 이분 매칭

```c++
// A[i], B[i]: 각 정점이 매칭된 반대편 정점 번호
int N, M, A[MAX], B[MAX];
vector<int> adj[MAX];
bool visited[MAX];
 
bool dfs(int a){
    visited[a] = true;
    for(int b: adj[a]){
        // 반대편이 매칭되지 않았거나
        // 매칭되어 있었지만 원래 매칭되어 있던 정점을 다른 정점과 매칭시킬 수 있으면 성공
        if(B[b] == -1 || !visited[B[b]] && dfs(B[b])){
            A[a] = b;
            B[b] = a;
            return true;
        }
    }
    return false;
}
 
int main(){
    int match = 0;
    // 초기값: -1
    fill(A, A+N, -1);
    fill(B, B+M, -1);
    for(int i=0; i<N; i++){
        if(A[i] == -1){
            fill(visited, visited+N, false);
            if(dfs(i)) match++;
        }
    }
    printf("%d\n", match);
}
```

---

## MCMF (SPFA 알고리즘)

```c++
const int MAX_N = 100; // 최대 N, M
const int MAX_V = 2*(MAX_N+1); // 최대 정점 개수
const int S = MAX_V-2; // 소스 정점 번호
const int E = MAX_V-1; // 싱크 정점 번호
const int INF = 1000000000;
 
int main(){
    // 정점 번호: 0~MAX_N: 서점, MAX_N~MAX_N*2: 사람
    int N, M;
    int c[MAX_V][MAX_V] = {0}; // 각 간선의 용량
    int d[MAX_V][MAX_V] = {0}; // 각 간선의 비용
    int f[MAX_V][MAX_V] = {0}; // 각 간선에 흐르는 중인 유량
    vector<int> adj[MAX_V]; // 각 정점의 인접 리스트
 
    scanf("%d %d", &N, &M);
    // 각 사람 정점과 싱크 정점 사이 간선 추가 (비용 0)
    for(int i=MAX_N; i<MAX_N+N; i++){
        scanf("%d", &c[i][E]);
        adj[E].push_back(i);
        adj[i].push_back(E);
    }
    // 소스 정점과 각 서점 정점 사이 간선 추가 (비용 0)
    for(int i=0; i<M; i++){
        scanf("%d", &c[S][i]);
        adj[S].push_back(i);
        adj[i].push_back(S);
    }
    // 서점과 사람 사이 간선 추가 (비용 C_ij)
    for(int i=0; i<M; i++){
        for(int j=MAX_N; j<MAX_N+N; j++){
            scanf("%d", &d[i][j]);
            d[j][i] = -d[i][j]; // 역방향 간선의 비용: 순방향의 -1배
            c[i][j] = INF; // 순방향 간선만 용량이 1 이상
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
    }
 
    int result = 0; // 최소 비용
    while(1){
        int prev[MAX_V], dist[MAX_V];
        bool inQ[MAX_V] = {0}; // 해당 정점이 큐 안에 있는가?
        queue<int> Q;
        fill(prev, prev+MAX_V, -1);
        fill(dist, dist+MAX_V, INF);
        dist[S] = 0;
        inQ[S] = true;
        Q.push(S);
 
        while(!Q.empty()){
            int curr = Q.front();
            Q.pop();
            inQ[curr] = false; // 큐에서 꺼냄
            for(int next: adj[curr]){
                // 최단 경로를 찾는 중이지만, 여전히 여유 용량 있어야 함
                if(c[curr][next]-f[curr][next] > 0 && dist[next] > dist[curr]+d[curr][next]){
                    dist[next] = dist[curr] + d[curr][next];
                    prev[next] = curr;
                    // 큐에 들어있지 않다면 큐에 넣음
                    if(!inQ[next]){
                        Q.push(next);
                        inQ[next] = true;
                    }
                }
            }
        }
        // 더 이상 경로가 없다면 루프 탈출
        if(prev[E] == -1) break;
 
        // 경로상에서 가장 residual이 작은 간선을 찾아 최대 흘릴 수 있는 flow 찾음
        int flow = INF;
        for(int i=E; i!=S; i=prev[i])
            flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
 
        // 경로상의 모든 간선에 flow만큼의 유량을 흘림
        for(int i=E; i!=S; i=prev[i]){
            result += flow * d[prev[i]][i]; // 총 비용이 각 간선 비용만큼 증가
            f[prev[i]][i] += flow;
            f[i][prev[i]] -= flow;
        }
    }
    // 정답 출력
    printf("%d\n", result);
}
```

---

## LCA

```c++
const int MAX = 18; // roundup log(2, 100000)
 
int N, M;
int parent[100000][MAX]; // parent[i][k]: i의 2^k번째 부모
int depth[100000]; // 정점의 깊이 (루트의 깊이: 0)
vector<int> adj[100000]; // 인접 리스트
 
void makeTreeByDFS(int curr){
    for(int next: adj[curr]){
        if(depth[next] == -1){
            parent[next][0] = curr;
            depth[next] = depth[curr] + 1;
            makeTreeByDFS(next);
        }
    }
}
 
int main(){
    memset(parent, -1, sizeof(parent));
    fill(depth, depth+N, -1);
    depth[0] = 0;

    makeTreeByDFS(0);
 
    for(int j=0; j<MAX-1; j++)
        for(int i=1; i<N; i++)
            if(parent[i][j] != -1)
                parent[i][j+1] = parent[parent[i][j]][j];
 
    scanf("%d", &M);
    for(int i=0; i<M; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
 
        if(depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
 
        for(int j=0; diff; j++){
            if(diff % 2) u = parent[u][j];
            diff /= 2;
        }
 
        if(u != v){
            for(int j=MAX-1; j>=0; j--)
                if(parent[u][j] != -1 && parent[u][j] != parent[v][j])
                    u = parent[u][j], v = parent[v][j];
            u = parent[u][0];
        }
    }
}
```

---

## Laze Propagation
```c++
const int ST_MAX = 1<<21;
 
struct SegTree{
    int start;
    long long arr[ST_MAX], lazy[ST_MAX];
 
    SegTree(){
        start = ST_MAX/2;
        fill(arr, arr+ST_MAX, 0);
        fill(lazy, lazy+ST_MAX, 0);
    }
 
    void construct(){
        for(int i=start-1; i>0; i--)
            arr[i] = arr[i*2] + arr[i*2+1];
    }
 
    // 구간 [ns, ne)인 node의 lazy 값을 propagate
    void propagate(int node, int ns, int ne){
        // lazy 값이 존재하면 실행
        if(lazy[node] != 0){
            // 리프 노드가 아니면 자식들에게 lazy 미룸
            if(node < start){
                lazy[node*2] += lazy[node];
                lazy[node*2+1] += lazy[node];
            }
            // 자신에 해당하는 만큼의 값을 더함
            arr[node] += lazy[node] * (ne-ns);
            lazy[node] = 0;
        }
    }
 
    // 구간 [s, e)에 k를 더하라
    void add(int s, int e, int k){ add(s, e, k, 1, 0, start); }
    void add(int s, int e, int k, int node, int ns, int ne){
        // 일단 propagate
        propagate(node, ns, ne);
 
        if(e <= ns || ne <= s) return;
        if(s <= ns && ne <= e){
            // 이 노드가 구간에 완전히 포함되면 lazy 부여 후 propagate
            lazy[node] += k;
            propagate(node, ns, ne);
            return;
        }
        int mid = (ns+ne)/2;
        add(s, e, k, node*2, ns, mid);
        add(s, e, k, node*2+1, mid, ne);
        // 마지막에 자식들의 값을 사용해 다시 자신의 값 갱신
        arr[node] = arr[node*2] + arr[node*2+1];
    }
 
    // 구간 [s, e)의 합을 구하라
    long long sum(int s, int e){ return sum(s, e, 1, 0, start); }
    long long sum(int s, int e, int node, int ns, int ne){
        // 일단 propagate
        propagate(node, ns, ne);
 
        if(e <= ns || ne <= s) return 0;
        if(s <= ns && ne <= e) return arr[node];
        int mid = (ns+ne)/2;
        return sum(s, e, node*2, ns, mid) + sum(s, e, node*2+1, mid, ne);
    }
};
 
int main(){
    // 초기 세그먼트 트리 입력받기
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    SegTree ST;
    for(int i=0; i<N; i++)
        scanf("%lld", ST.arr+ST.start+i);
    ST.construct();
 
    // 쿼리 처리
    for(int i=0; i<M+K; i++){
        int a, b, c, d;
        scanf("%d", &a);
        if(a == 1){
            scanf("%d %d %d", &b, &c, &d);
            ST.add(b-1, c, d);
        }
        else{
            scanf("%d %d", &b, &c);
            printf("%lld\n", ST.sum(b-1, c));
        }
    }
}
```

---

## Convex Hull

```c++
struct Point{
    int x, y; // 실제 위치
    int p, q; // 기준점으로부터의 상대 위치
    Point(): Point(0, 0, 1, 0){}
    Point(int x1, int y1): Point(x1, y1, 1, 0){}
    Point(int x1, int y1, int p1, int q1): x(x1), y(y1), p(p1), q(q1){}
    // p, q 값을 기준으로 정렬하기 위한 관계연산자
    bool operator <(const Point& O){
        if(1LL*q*O.p != 1LL*p*O.q) return 1LL*q*O.p < 1LL*p*O.q;
        if(y != O.y) return y < O.y;
        return x < O.x;
    }
};
 
long long ccw(const Point& A, const Point& B, const Point& C){
    return 1LL*(B.x-A.x)*(C.y-A.y) - 1LL*(B.y-A.y)*(C.x-A.x);
}
 
int main(){
    int N;
    scanf("%d", &N);
    Point p[MAX];
    for(int i=0; i<N; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        p[i] = Point(x, y);
    }
    // 점들을 y좌표 -> x좌표 순으로 정렬: 0번 점이 제일 아래 제일 왼쪽
    sort(p, p+N);
 
    for(int i=1; i<N; i++){
        p[i].p = p[i].x - p[0].x;
        p[i].q = p[i].y - p[0].y;
    }
    // 0번을 제외한 점들을 반시계 방향으로 정렬
    sort(p+1, p+N);
 
    stack<int> S;
    // 스택에 처음 2개의 점을 넣음
    S.push(0);
    S.push(1);
    int next = 2;
    while(next < N){
        // 스택에 2개 이상의 점이 남아있는 한...
        while(S.size() >= 2){
            int first, second;
            first = S.top();
            S.pop();
            second = S.top();
            // 스택 최상단 점 2개와 다음 점의 관계가 CCW일 때까지 스택 pop
            if(ccw(p[second], p[first], p[next]) > 0){
                S.push(first);
                break;
            }
        }
        S.push(next++);
    }
}
```

---

## DP Convex Hull Trick

```c++
const int MAX = 100000;

struct LinearFunc{
	long long a, b;
	double s;
	LinearFunc(): LinearFunc(1, 0){}
	LinearFunc(long long a1, long long b1):a(a1),b(b1),s(0){}
};

inline double cross(LinearFunc &f, LinearFunc &g) {
	return (g.b-f.b)/(f.a-g.a);
}

int N, A[MAX], B[MAX];
long long dp[MAX];
LinearFunc f[MAX];

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%d", A+i);
	for (int i=0; i<N; i++)
		scanf("%d", B+i);

	// dp[0] = 0, dp 테이블을 채우면서 "f(.)=B[i]*x + dp[i]"를 스택에 쌓음
	int top = 0;
	for (int i=1; i<N; i++) {
		// i-1 번에 해당하는 새로운 직선을 스택의 top에 쌓음
		LinearFunc g(B[i-1], dp[i-1]);
		while (top > 0) {
			g.s = cross(f[top-1], g);
			if (f[top-1].s < g.s) break;
			// 쌓기 전에, top과 교점을 구해서 top의 시작점보다 교점이 앞이면 pop
			--top; 
		}
		f[top++] = g;

		long long x = A[i];
		int fpos = top-1;
		if (x < f[top-1].s) {
			int lo = 0, hi = top-1;
			while (lo+1 < hi) {
				int mid = (lo+hi)/2;
				(x < f[mid].s ? hi : lo) = mid;
			}
			fpos = lo;
		}
		// i번째 dp 값 계산
		dp[i] = f[fpos].a * x + f[fpos].b;
	}
	printf("%lld\n", dp[N-1]);

	return 0;
}
```

---

## KMP

```c++
int fail[MAX] = {0};
for(int i=1, j=0; i<M; i++){
    while(j > 0 && W[i] != W[j]) j = fail[j-1];
    if(W[i] == W[j]) fail[i] = ++j;
}
```

---

## 삼분탐색

```c++
int N, x[100000];
 
inline long long f(int x0){
    long long result = 0;
    for(int i = 1; i < N; ++i)
        result += abs(1LL*x0*i - x[i]);
    return result;
}
 
int main(){ 
    // 삼분 탐색
    int lo = 0, hi = x[N-1];
    while(hi-lo >= 3){
        int p = (lo*2 + hi)/3, q = (lo + hi*2)/3;
        if(f(p) <= f(q)) hi = q;
        else lo = p;
    }

    long long result = INF;
    for(int i = lo; i <= hi; ++i)
        result = min(f(i), result);
}
```

---


## Segment Tree 금광

```c++
typedef long long ll;
ll n, x, y, z, res;
vector<ll> ypos;
ll max(ll a, ll b, ll c, ll d,ll e) {
    return max(max(a, b), max(c, max(d, e)));
}
struct element {
    ll x, y, z;
    bool operator<(const element &A)const {
        return x < A.x;
    }
};
struct mseg {    //왼쪽 끝부터 최대 연속 합,오른쪽 끝부터 최대 연속 합,구간 합, 구간의 최대 연속 합
    ll lsum, rsum, tsum, msum;
};
mseg seg[4 * MAX_N];
element ele[MAX_N];
ll get_ypos(ll pos) {
    return lower_bound(ypos.begin(), ypos.end(), pos) - ypos.begin();
}
void update(ll pos, ll val, ll node, ll x, ll y) {
    if (y < pos || pos < x)
        return;
    if (x == y) {
        seg[node].tsum += val;
        seg[node].lsum += val;
        seg[node].rsum += val;
        seg[node].msum += val;
        return;
    }
    ll mid = (x + y) >> 1;
    update(pos, val, node * 2, x, mid);
    update(pos, val, node * 2 + 1, mid + 1, y);
    seg[node].lsum = max(seg[node * 2].lsum, seg[node * 2].tsum + seg[node * 2 + 1].lsum);
    seg[node].rsum = max(seg[node * 2 + 1].rsum, seg[node * 2 + 1].tsum + seg[node * 2].rsum);
    seg[node].tsum = seg[node * 2].tsum + seg[node * 2 + 1].tsum;
    seg[node].msum = max(seg[node * 2].rsum + seg[node * 2 + 1].lsum, seg[node * 2].msum, seg[node * 2 + 1].msum, seg[node].lsum, seg[node].rsum);
}
ll query(ll lo, ll hi, ll node, ll x, ll y) {
    if (y < lo || hi < x)
        return 0;
    if (lo <= x&&y <= hi)
        return seg[node].msum;
    ll mid = (x + y) >> 1;
    return max(query(lo, hi, node * 2, x, mid), query(lo, hi, node * 2 + 1, mid + 1, y));
}
int main() {
    scanf("%lld", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld%lld", &x, &y, &z);
        ele[i] = { x,y,z };
        ypos.push_back(y);
    }
    sort(ele, ele + n);
    sort(ypos.begin(), ypos.end());
    ypos.erase(unique(ypos.begin(), ypos.end()), ypos.end());
    const ll MAX_Y = ypos.size();
    for (int i = 0; i < n; i++) {
        memset(seg, 0, sizeof(seg));
        if (i&&ele[i].x == ele[i - 1].x)
            continue;
        for (int j = i; j < n; j++) {
            ll pos = get_ypos(ele[j].y);
            update(pos, ele[j].z, 1, 0, MAX_Y - 1);
            if (j != n - 1 && ele[j].x == ele[j + 1].x)
                continue;
            ll q = query(0, MAX_Y - 1, 1, 0, MAX_Y - 1);
            res = max(q, res);
        }
    }
    printf("%lld\n", res);
    return 0;
}
```

---

## LIS 알고리즘

```c++
// i번째 위치의 스위치 번호는 top(i)
// 스위치 번호 j의 위치는 idx(j)
for (int i=0; i<N; i++) {
    scanf("%d", &top[i]);
    idx[top[i]]=i;
}

// i번째 전구의 스위치 위치는 bottom(i)
for (int i=0; i<N; i++) {
    int x;
    scanf("%d", &x);
    bottom[i]=idx[x];
}

vector<int> lis(N+1, MAX_N);
vector<pair<int,int>> trace;
for (int i=0; i<N; i++) {
    // lis 배열의 증가 수열 형태를 지키면서 적을 수 있는 lis의 위치 index
    int index = lower_bound(lis.begin(),lis.end(), bottom[i]) - lis.begin();
    // lis에 스위치 위치 저장
    lis[index] = bottom[i];
    // 나중에 tracking하기 위해 trace배열에 저장
    trace.push_back({index, bottom[i]});
}

// lis 배열의 길이 cnt 찾기
int cnt=0;
for (int i=0; i<N; i++) {
    if (lis[i] == MAX_N) break;
    cnt++;
}
printf("%d\n", cnt);

// 배열은 0부터 시작하기 때문에 cnt 값을 1 빼줌
cnt--;
int tlen = trace.size();
vector<int> ansIdx;
for (int i=tlen; i>=0; i--) {
    // trace 뒤에서부터 각 위치에 들어간 스위치 위치 번호 찾기
    if (trace[i].first != cnt) continue;
    ansIdx.push_back(trace[i].second);
    cnt--;
}

// 스위치 위치를 스위치의 번호로 변경하여 ans에 저장
vector<int> ans;
for (int i=0; i<ansIdx.size(); i++)
    ans.push_back(top[ansIdx[i]]);

// 결과 출력을 위해 정렬
sort(ans.begin(), ans.end());

// 결과 출력
for (int i=0; i<ans.size(); i++) {
    printf("%d", ans[i]);
    if (i != ans.size()) printf(" ");
    else printf("\n");
}
```

---

## BFS

```c++
vector<bool> visited(N, false); // 방문 여부를 저장하는 배열
queue<int> Q;
Q.push(0);
visited[0] = true;
while(!Q.empty()){
    int curr = Q.front();
    Q.pop();
    cout << "node " << curr << " visited" << endl;
    for(int next: adj[curr]){
        if(!visited[next]){
            visited[next] = true;
            Q.push(next);
        }
    }
}
```









- BitMasking

```c++
#include <bits/stdc++.h> 
using namespace std; 
#define endl '\n' 
typedef long long ll; 
typedef pair<int, int> pii; 
string field[15]; 
int dp[15][1025];

bool seat_check(string& seats, int bit) {
    for (size_t i = 0; i < seats.length(); i++) { 
        if (seats[i] == 'x' && (bit & (1 << i))) return false; 
    } 
    return true; 
}

bool adj_check(int bit, int width) { 
    for (int i = 0; i < width - 1; i++) { 
        int val = (3 << i); 
        if ((bit & val) == val) 
            return false; 
    } 
    return true; 
}

bool bits_check(int bit, int fbit, int width) {
    for (int i = 0; i < width; i++) {
        if ((1 << i) & fbit) {
            if (i > 0 && ((1 << (i - 1)) & bit)) return false; 
            if ((1 << (i + 1) & bit)) return false; 
        } 
    } 
    return true; 
}

void solve() { 
    int ans = 0;
    memset(dp, 0, sizeof(dp));
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) { 
        cin >> field[i]; 
    }
    vector<pii> bits_set; 
    //인접한 자리가 아닌 비트 마스크들을 미리 만들어놓음. 
    for (int bit = 0; bit < (1 << m); bit++) { 
        if (adj_check(bit, m)) { 
            int cnt = 0;
            for (int i = 0; i < m; i++) {
                if ((1 << i) & bit) cnt++;
            }
            bits_set.push_back(make_pair(bit, cnt));
        }
    }
    for (int i = 1; i <= n; i++) {
        for (pii bit : bits_set) { 
            if (!seat_check(field[i], bit.first)) continue; 
            for (pii fbit : bits_set) { 
                if (bits_check(bit.first, fbit.first, m)) { 
                    dp[i][bit.first] = max(dp[i][bit.first], dp[i - 1][fbit.first] + bit.second); 
                    ans = max(ans, dp[i][bit.first]); 
                } 
            } 
        } 
    } 
    cout << ans << endl; 
    return; 
}

int main() {
    int tc; 
    cin >> tc; 
    while (tc--) solve(); 
}
```



