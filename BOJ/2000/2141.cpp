#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX_N=100001;

int N;
pair<int,int> arr[MAX_N];
ll acc[MAX_N];

int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++)
        scanf("%d%d", &arr[i].first, &arr[i].second);

    sort(arr, arr + N);

    acc[0] = arr[0].second;
    for (int i=1; i<N; i++)
        acc[i] = acc[i-1] + arr[i].second;

    int l = 0, r = N-1;
    int ret = 2e9;
    while (l <= r) {
        int mid = (l+r) / 2;
        ll lsum = acc[mid];
        ll rsum = acc[N-1] - acc[mid];
        if (lsum < rsum) l = mid + 1;
        else r = mid - 1, ret = min(ret, arr[mid].first);
    }
    printf("%d\n", ret);
    return 0;
}