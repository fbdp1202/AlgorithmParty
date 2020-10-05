// baekjoon 5675 yechan
#include <bits/stdc++.h>
using namespace std;

bool dp[361];

int main() {

    for (int i=0; i<60*12; i++) {
        int hDeg = ((i/12)*6)%360;
        int mDeg = (i*6)%360;
        int diff = abs(hDeg - mDeg);
        diff = 180 - abs(diff - 180);
        dp[diff] = 1;
    }

    int x;
    while (!(scanf("%d", &x) == -1)) puts(dp[x] ? "Y":"N");
    return 0;
}