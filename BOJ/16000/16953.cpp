#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const LL MAX_V = 1e9;
const int MAX_INF = 1e9;
LL A, B;

int DFS(LL x) {
    if (x == B) return 1;
    if (x > MAX_V) return MAX_INF;
    int ret = MAX_INF;
    return min(ret, min(DFS(x*10+1)+1, DFS(x*2)+1));
}

int main() {
    scanf("%lld%lld", &A, &B);
    int answer = DFS(A);
    printf("%d\n", answer == MAX_INF ? -1 : answer);
    return 0;
}