#include <bits/stdc++.h>
using namespace std;

const int MAX_N=3001;

int T, N, K;
int A[MAX_N], B[MAX_N];
bool visited[MAX_N][MAX_N];

int BFS() {
    int ret = 1;
    queue<int> Q;
    Q.push(0);
    memset(visited, 0, sizeof(visited));
    visited[0][0]=true;

    int flag = 0;
    while (!Q.empty()) {
        int qSize = Q.size();
        for (int s=0; s<qSize; s++) {
            int x = Q.front() >> 12;
            int y = Q.front() & ((1<<12)-1);
            Q.pop();

            if (flag == 0) {
                if (x+1 <= N && !visited[x+1][y]) {
                    visited[x+1][y] = true;
                    Q.push(((x+1)<<12)+y);
                }
                if (y+1 <= N && !visited[x][y+1]) {
                    visited[x][y+1] = true;
                    Q.push((x<<12)+y+1);
                }
            } else {
                int sum = 0;
                for (int i=x+1; i<=N; i++) {
                    sum += A[i];
                    if (sum > K) break;
                    if (visited[i][y]) continue;
                    visited[i][y] = true;
                    Q.push((i<<12)+y);
                    ret += flag;
                }

                sum = 0;
                for (int i=y+1; i<=N; i++) {
                    sum += B[i];
                    if (sum > K) break;
                    if (visited[x][i]) continue;
                    visited[x][i] = true;
                    Q.push((x<<12)+i);
                    ret += flag;
                }
            }
        }
        flag ^= 1;
    }
    return ret;
}

int main() {
    setbuf(stdout, NULL);
    scanf("%d", &T);
    for (int t=1; t<=T; t++) {
        printf("Case #%d\n", t);

        scanf("%d%d", &N, &K);
        for (int i=1; i<=N; i++)
            scanf("%d", &A[i]);
        for (int i=1; i<=N; i++)
            scanf("%d", &B[i]);

        int ret = BFS();
        printf("%d %d\n", ret, (N+1)*(N+1)-ret);
    }
    return 0;
}