/*
대경권 본선 2번
문제설명
- NxM 크기의 맵이 주어진다. 이 맵은 .과 A-Z 알파벳으로 이루어져 있다.
- 이 맵은 .은 바다, A-Z는 각 나라의 영토를 의미한다.
- 여기서 바다로 끊어진 한 섬을 보았을때, 영토가 가장 많은 나라가 그 섬의 모든 영토를 소유한다.
- 이때, 두 나라가 같은 영토 크기를 가지면 알파벳 순으로 뒤의 나라가 이긴다.
- 이제, 각 나라 중 가장 큰 영토 크기를 가지는 나라의 영토 크기를 출력하여라.

ex)
input:
4 5
AB.CB
AB.CA
..AAB

output:
7

simulation:
BB.AA
BB.AA
..AAA

알고리즘
- 왼쪽 위에서 부터 BFS를 이용하여 각 섬을 확인한다.
- 각 섬의 색깔 별 영토를 확인하여 배열의 저장한다.
- 가장 넓은 영토를 찾는다.
- 찾았다면 전체 섬의 크기만큼 가장 넓은 영토를 가진 왕국에 더해준다.
- 모든 섬을 확인한 뒤에, 각 왕국중 가장 넓은 영토 값을 출력한다.

*/
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <queue>
using namespace std;
const int MAX_N = 1001;
typedef pair<int, int> P;

int n, m, alpha[26], ans[26];
char board[MAX_N][MAX_N];
bool visit[MAX_N][MAX_N], check[MAX_N][MAX_N];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};


void bfs(int y, int x){
    queue<P> q;
    q.push(make_pair(y, x));
    for(int i = 0; i < 26; i++){
        alpha[i] = 0;
    }

    int size = 0;
    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        int cur = board[cy][cx];
        alpha[cur-65]++;
        visit[cy][cx] = true;
        size++;

        for(int i = 0; i < 4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if(!visit[ny][nx]) {
                q.push(make_pair(ny, nx));
                visit[ny][nx] = true;
            }
        }
    }

    int maxi = 0;
    int pos = 0;
    for(int i = 0; i < 26; i++){
        if(alpha[i] >= maxi){
            maxi = alpha[i];
            pos = i;
        }
    }

    int land = 0;
    for(int i = 0; i < 26; i++){
        if(alpha[i] < maxi){
            land += alpha[i];
            alpha[i] = 0;
        }
    }

    alpha[pos] += land;

    for(int i = 0; i < 26; i++){
        ans[i] += alpha[i];
    }

}

int main(){
    scanf("%d %d", &n, &m);
    char ch;
    for(int i = 0; i < n; i++){
        scanf("%c", &ch);
        for(int j = 0; j < m; j++){
            scanf("%c", &board[i][j]);
            if(board[i][j] == '.') {
                visit[i][j] = true;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visit[i][j]){
                bfs(i, j);
            }
        }
    }

    int maxi = 0;
    for(int i = 0; i < 26; i++){
        maxi = max(maxi, ans[i]);
    }

    printf("%d", maxi);

	return 0;
}