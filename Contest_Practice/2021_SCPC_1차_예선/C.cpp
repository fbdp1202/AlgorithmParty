#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;

const int MAX_N=501;
const int MAX_K=2001;

int T, N, M, K;
int adj[MAX_N][MAX_N];

int read_int() {
    int x;
    scanf("%d", &x);
    return x;
}

int main () {
    setbuf(stdout, NULL);

    T = read_int();
    for (int t=1; t<=T; t++) {
        memset(adj, 0, sizeof(adj));
        printf("Case #%d\n", t);

        N = read_int();
        M = read_int();
        K = read_int();
        for (int i=0; i<M; i++) {
            int x, y;
            x = read_int() - 1;
            y = read_int() - 1;
            board[x][y] = 1;
        }

        vector<P> v(K);
        vector<int> idx(K, -1);
        for (int i=0; i<M; i++) {
            int x, y;
            x = read_int() - 1;
            y = read_int() - 1;
            v[i] = P(x, y);
            if (board[x][y] == 1) {
                idx[i] = 0;
            }
            else if (board[y][x] == 1) {
                idx[i] = 1;
            } else {
                board[x][y] = -1;
            }
        }

        // case 1
        for (int i=0; i<M; i++) {
            if (idx[i] != -1) continue;

            int flag = true;
            int x, y;
            x = v[i].first;
            y = v[i].second;
            for (int j=0; j<M; j++) {
                if (board[y][j] != 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                board[x][y] = 1;
            }
        }

        // group 1
        if (3 <= N && N <=10 && 0 <= M && M <= 20 && 1 <= K && K <= 10) {
            backtracking();
            continue;
        }



    }
    return 0;
}