// baekjoon 1758 yechan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N=100001;

int N, arr[MAX_N];

int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++)
        scanf("%d", &arr[i]);

    sort(arr, arr + N, greater<int>() );

    ll ret = 0;
    for (int i=0; i<N; i++)
        ret += max(arr[i] - i, 0);

    printf("%lld\n", ret);

    return 0;
}