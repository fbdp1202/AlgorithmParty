// baekjoon 4179 yechan
#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;
const int MAX_N=1001;
const int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0} };

int N, M, sx, sy;
bool visited[MAX_N][MAX_N];
char tmp[MAX_N];
vector<P> fire;

int BFS() {
    queue<P> qFire;
    for (int i=0; i<fire.size(); i++)
        qFire.push(fire[i]);

    queue<P> qPos;
    qPos.push(P(sx, sy));

    int t = 1;
    while (!qPos.empty()) {
        // propgate fire
        int qFireSize = qFire.size();
        for (int i=0; i<qFireSize; i++) {
            P curr_P = qFire.front();
            qFire.pop();
            int curr_x = curr_P.first;
            int curr_y = curr_P.second;
            for (int d=0; d<4; d++) {
                int nx = curr_x + dir[d][0];
                int ny = curr_y + dir[d][1];
                if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                if (visited[nx][ny]) continue;
                visited[nx][ny] = true;
                qFire.push(P(nx,ny));
            }
        }

        // propgate me
        int qPosSize = qPos.size();
        for (int i=0; i<qPosSize; i++) {
            P curr_P = qPos.front();
            qPos.pop();
            int curr_x = curr_P.first;
            int curr_y = curr_P.second;
            for (int d=0; d<4; d++) {
                int nx = curr_x + dir[d][0];
                int ny = curr_y + dir[d][1];
                if (nx < 0 || nx >= N || ny < 0 || ny >= M) return t;
                if (visited[nx][ny]) continue;
                visited[nx][ny] = true;
                qPos.push(P(nx,ny));
            }
        }
        t++;
    }
    return -1;
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i=0; i<N; i++) {
        scanf("%s", tmp);
        for (int j=0; j<M; j++) {
            char c = tmp[j];
            if (c == '#') visited[i][j] = true;
            else if (c == 'F') visited[i][j] = true, fire.push_back(P(i,j));
            else if (c == 'J') visited[i][j] = true, sx = i, sy = j;
        }
    }
    int ret = BFS();
    if (ret == -1) puts("IMPOSSIBLE");
    else printf("%d\n", ret);
    return 0;
}