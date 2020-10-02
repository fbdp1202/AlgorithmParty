// baekjoon 1114 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_K=10001;

int L, K, C;
int pos[MAX_K];

bool search(int start, int idx, int maxL, int num, int maxBlock) {
    int curr = start;
    for (int i=idx; i<num; i++) {
        if (maxBlock == 0) break;
        if (i+1 < num && pos[i+1] - curr <= maxL) continue;
        if (pos[i] - curr > maxL) return false;
        maxBlock--;
        curr = pos[i];
    }
    return L - curr <= maxL;
}

int findStartPos(int maxL, int num, int maxBlock) {
    for (int i=0; i<num; i++)
        if (pos[i] <= maxL && search(pos[i], i+1, maxL, num, maxBlock-1))
            return pos[i];
    return -1;
}

int main() {
    scanf("%d%d%d", &L, &K, &C);
    for (int i=0; i<K; i++)
        scanf("%d", &pos[i]);

    sort(pos, pos+K);

    int lo=1, hi=L;
    int ret=L;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (search(0, 0, mid, K, C)) ret = min(ret, mid), hi = mid - 1;
        else lo = mid + 1;
    }
    printf("%d %d\n", ret, findStartPos(ret, K, C));
    return 0;
}
