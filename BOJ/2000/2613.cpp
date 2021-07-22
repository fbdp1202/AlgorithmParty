// baekjoon 2613 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=301;

int N, M;
int arr[MAX_N];

int search(int limit) {
    int tmp = 0;
    int group = 1;
    for (int i=0; i<N; i++) {
        tmp += arr[i];
        if (limit < tmp)
            tmp = arr[i], group++;
    }
    return group <= M;
}

int main() {
    scanf("%d%d", &N, &M);

    int l = 0, r = 30001;
    for (int i=0; i<N; i++) {
        scanf("%d", &arr[i]);
        l = max(l, arr[i]);
    }

    int ret = 1e9;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (search(mid)) ret = min(ret, mid), r = mid - 1;
        else l = mid + 1;
    }
    printf("%d\n", ret);
    int group = M;
    int tmp = 0;
    int count = 0;
    for (int i=0; i<N; i++) {
        tmp += arr[i];
        if (ret < tmp) {
            printf("%d ", count);
            tmp = arr[i], count = 0;
            group--;
        }
        count++;
        if (N-i == group) break;
    }
    while (group--) {
        printf("%d\n", count);
        count = 1;
    }
    return 0;
}