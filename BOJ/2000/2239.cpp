#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;

int board[10][10];
bool check[3][10][10]; // (row, col, 3x3)
char str[20];

P getPos() {
    for (int i=0; i<9; i++)
        for (int j=0; j<9; j++)
            if (board[i][j] == 0) return P(i, j);
    return P(-1,-1);
}

bool DFS(int numBlank) {
    if (numBlank == 0) {
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++)
                printf("%d", board[i][j]);
            puts("");
        }
        return true;
    }

    bool ret = false;
    P pos = getPos();
    int nx = pos.first, ny = pos.second;
    for (int i=1; i<=9; i++) {
        if (check[0][nx][i] || check[1][ny][i] || check[2][(nx/3)*3+ny/3][i]) continue;
        check[0][nx][i] = check[1][ny][i] = check[2][(nx/3)*3+ny/3][i] = true;
        board[nx][ny] = i;
        ret |= DFS(numBlank-1);
        if (ret) return ret;
        board[nx][ny] = 0;
        check[0][nx][i] = check[1][ny][i] = check[2][(nx/3)*3+ny/3][i] = false;
    }
    return ret;
}

int main() {
    int numBlank = 0;
    for (int i=0; i<9; i++) {
        scanf("%s", str);
        for (int j=0; j<9; j++) {
            int num = (int)(str[j] - '0');
            board[i][j] = num;
            if (num == 0) numBlank++;
            else check[0][i][num] = check[1][j][num] = check[2][(i/3)*3+j/3][num] = true;
        }
    }
    DFS(numBlank);
    return 0;
}