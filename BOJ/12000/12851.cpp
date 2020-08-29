#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;

const int MAX_N=200001;

int S, E;
bool visited[MAX_N];

void BFS() {
    queue<int> Q;
    Q.push(S);

    int t = 0, num = 0;
    bool flag = false;
    while (!Q.empty()) {
        int qSize = Q.size();
        for (int i=0; i<qSize; i++) {
            int curr = Q.front();
            Q.pop();
            visited[curr] = true;
            if (curr == E) flag = true, num++;
            int nx;
            // nx = x - 1
            nx = curr - 1;
            if (nx >= 0 && !visited[nx]) Q.push(nx);
            nx = curr + 1;
            if (nx < MAX_N && !visited[nx]) Q.push(nx);
            nx = curr * 2;
            if (nx < MAX_N && !visited[nx]) Q.push(nx);
        }
        if (flag) break;
        t++;
    }
    printf("%d\n%d\n", t, num);
}

int main() {
    scanf("%d%d", &S, &E);
    BFS();
    return 0;
}