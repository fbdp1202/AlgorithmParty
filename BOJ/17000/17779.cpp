// baekjoon 17779 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=21;
const int MAX_INF=1e9;

int N;
int A[MAX_N][MAX_N];

int read_int() {
    int x;
    scanf("%d", &x);
    return x;
}

void read_input() {
    N = read_int();
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            A[i][j] = read_int();
}

int getLocation(int i, int j, int x, int y, int d1, int d2) {
    if (x <= i && i <= x + d1 + d2) {
        int inc = i - x;

        int up_y = -1;
        if (inc <= d1)  up_y = y - inc;
        else            up_y = (y - d1) + (inc - d1);

        int bottom_y = -1;
        if (inc <= d2)  bottom_y = y + inc;
        else            bottom_y = (y + d2) - (inc - d2);

        if (up_y <= j && j <= bottom_y) return 5;
    }
    if (i < x + d1 && j <= y) return 1;
    if (i <= x + d2 && y < j) return 2;
    if (x + d1 <= i && j < y - d1 + d2) return 3;
    if (x + d2 < i && y - d1 + d2 <= j) return 4;
    return 0;
}

int divide(int x, int y, int d1, int d2) {
    int arr[6] = {0,};

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            int idx = getLocation(i, j, x, y, d1, d2);
            arr[idx] += A[i][j];
        }
    }

    int maxV = arr[1], minV = arr[1];

    for (int i=2; i<=5; i++) {
        maxV = max(maxV, arr[i]);
        minV = min(minV, arr[i]);
    }

    int ret = maxV - minV;

    return ret;
}

int run() {
    int ret = MAX_INF;

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            for (int d1=1; d1<N; d1++) {
                for (int d2=1; d2<N; d2++) {
                    if (i +  d1 + d2 >= N) continue;
                    if (j - d1 < 0) continue;
                    if (j + d2 >= N) continue;
                    ret = min(ret, divide(i, j, d1, d2));
                }
            }
        }
    }

    return ret;
}

int main() {

    read_input();

    printf("%d\n", run());

    return 0;
}