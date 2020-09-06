#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;

const int MAX_N=200001;
const int MAX_V=500002;

int T, N, K, Q;
int cost[MAX_N];
int data[MAX_N];
int arr[MAX_N];
bool visited[MAX_V];
int idx[MAX_N];
int pos[MAX_V];
int cnt;
int min_heap_size;
int max_heap_size;

priority_queue<P,vector<P>,greater<P>> min_heap;
priority_queue<P> max_heap;

void removeVisited() {
    while (!min_heap.empty() && visited[min_heap.top().second]) min_heap.pop();
    while (!max_heap.empty() && visited[max_heap.top().second]) max_heap.pop();
}

void insertToHeap(int value) {
    int max_heap_top = -2e9;
    if (!max_heap.empty()) max_heap_top = max_heap.top().first;

    if (value < max_heap_top) max_heap.push(P(value, cnt)), max_heap_size++;
    else min_heap.push(P(value, cnt)), min_heap_size++;
}

void balanceHeap() {
    if (min_heap_size == max_heap_size) return;
    if (min_heap_size == max_heap_size + 1) return;

    if (max_heap_size < min_heap_size) {
        int moveNum = (min_heap_size - max_heap_size) / 2;
        for (int i=0; i<moveNum; i++) {
            removeVisited();
            min_heap_size--;
            max_heap_size++;
            P min_heap_top = min_heap.top();
            min_heap.pop();
            pos[min_heap_top.second] = 1;
            max_heap.push(min_heap_top);
        }
    } else {
        int moveNum = (max_heap_size - min_heap_size + 1) / 2;
        for (int i=0; i<moveNum; i++) {
            removeVisited();
            max_heap_size--;
            min_heap_size++;
            P max_heap_top = max_heap.top();
            max_heap.pop();
            pos[max_heap_top.second] = 2;
            min_heap.push(max_heap_top);
        }
    }
}

void insertData(int value, int here) {
    // is in max_heap
    if (pos[idx[here]] == 1) {
        pos[idx[here]] = 0;
        visited[idx[here]] = true;
        max_heap_size--;
    }
    // is in min_heap
    if (pos[idx[here]] == 2) {
        pos[idx[here]] = 0;
        visited[idx[here]] = true;
        min_heap_size--;
    }
    idx[here] = cnt;

    removeVisited();
    insertToHeap(value);
    balanceHeap();
}

int main() {
    setbuf(stdout, NULL);
    scanf("%d", &T);
    for (int t=1; t<=T; t++) {
        memset(visited, 0, sizeof(visited));
        memset(pos, 0, sizeof(pos));
        memset(idx, 0, sizeof(idx));
        cnt = 0;

        printf("Case #%d\n", t);
        scanf("%d%d%d", &N, &K, &Q);
        for (int i=0; i<N; i++)
            scanf("%d", &cost[i]);

        min_heap = priority_queue<P, vector<P>, greater<P> >();
        max_heap = priority_queue<P>();
        min_heap_size = 0;
        max_heap_size = 0;

        int tmp = 0;
        for (int i=0; i<K-1; i++)
            tmp += cost[i];
        for (int i=K-1; i<N; i++) {
            tmp += cost[i];
            data[i-K+1] = tmp;
            insertData(data[i-K+1], i-K+1);
            cnt++;
            tmp -= cost[i-K+1];
        }
        printf("%d ", min_heap.top().first);

        for (int q=0; q<Q; q++) {
            int x, y;
            scanf("%d%d", &x, &y);
            x--;
            int diff = y - cost[x];
            cost[x] = y;
            for (int i=max(0,x-K+1); i<=min(x, N-K); i++) {
                data[i] += diff;
                insertData(data[i], i);
                cnt++;
            }

            printf("%d ", min_heap.top().first);
        }
        puts("");
    }
    return 0;
}