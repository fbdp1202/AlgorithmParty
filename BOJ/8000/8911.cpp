// baekjoon 8911 yechan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N=501;
const int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

int T;
char cmd[MAX_N];

void forward(int &x, int &y, int d) {
    x += dir[d][0]; y += dir[d][1];
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%s", cmd);
        int x = 0, y = 0, d = 0;
        int minX = 0, minY = 0, maxX = 0, maxY = 0;
        for (int i=0; cmd[i]; i++) {
            char c = cmd[i];
            switch(c) {
                case 'F': forward(x, y, d); break;
                case 'B': forward(x, y, (d+2)%4); break;
                case 'L': d = (d+3)%4; break;
                case 'R': d = (d+1)%4; break;
            }
            minX = min(minX, x);
            maxX = max(maxX, x);
            minY = min(minY, y);
            maxY = max(maxY, y);
        }
        ll ret = 1LL*(maxX-minX)*(maxY-minY);
        printf("%lld\n", ret);
    }
    return 0;
}