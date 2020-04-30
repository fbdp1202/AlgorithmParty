//BOJ1600 yongju
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX_H 201
#define MAX_K 32
struct Pos{
   int x, y, c;
   Pos(){}
   Pos(int x, int y, int c):x(x), y(y), c(c){}
};
int k, w, h, board[MAX_H][MAX_H];
bool visited[MAX_K][MAX_H][MAX_H];
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int ox[4] = {0, 1, 0, -1};
int oy[4] = {1, 0, -1, 0};

int bfs(){
   queue<Pos> q;
   q.push(Pos(0, 0, 0));
   int depth = 0;
   visited[0][0][0] = true;
   while(!q.empty()) {
      int qSize = q.size();
      while (qSize--) {
         int curx = q.front().x;
         int cury = q.front().y;
         int curk = q.front().c;
         q.pop();
         if(curx == h-1 && cury == w-1) return depth;

         if(curk < k) {
            for(int j = 0; j < 8; j++) {
               int nx = curx + dx[j];
               int ny = cury + dy[j];
               int nk = curk + 1;
               if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
               if (board[nx][ny]) continue;
               if (visited[nk][nx][ny]) continue;
               q.push(Pos(nx, ny, nk));
               visited[nk][nx][ny] = true;
            }
         }
         for(int j = 0; j < 4; j++){
            int nx = curx + ox[j];
            int ny = cury + oy[j];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (board[nx][ny]) continue;
            if (visited[curk][nx][ny]) continue;
            q.push(Pos(nx, ny, curk));
            visited[curk][nx][ny] = true;
         }
      }
      depth++;
   }
   return -1;
}

int main(){
   scanf("%d %d %d", &k, &w, &h);
   for(int i = 0; i < h; i++)
      for(int j = 0; j < w; j++)
         scanf("%d", &board[i][j]);

   printf("%d\n", bfs());
   return 0;
}