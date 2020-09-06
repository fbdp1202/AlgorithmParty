#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;

const int MAX_N=200001;

int T, N, K, Q;
int cost[MAX_N];
int data[MAX_N];
vector<int> arr;

int main() {
    setbuf(stdout, NULL);
    scanf("%d", &T);
    for (int t=1; t<=T; t++) {
        printf("Case #%d\n", t);
        scanf("%d%d%d", &N, &K, &Q);
        arr = vector<int>(N-K+1);

        for (int i=0; i<N; i++)
            scanf("%d", &cost[i]);

        int tmp = 0;
        for (int i=0; i<K-1; i++)
            tmp += cost[i];

        for (int i=K-1; i<N; i++) {
            tmp += cost[i];
            data[i-K+1] = tmp;
            arr[i-K+1] = data[i-K+1];
            tmp -= cost[i-K+1];
        }
        sort(arr.begin(), arr.end());
        printf("%d ", arr[(N-K+1)/2]);
        for (int q=0; q<Q; q++) {
            int x, y;
            scanf("%d%d", &x, &y);
            x--;
            int diff = y - cost[x];
            cost[x] = y;
            for (int i=max(0,x-K+1); i<=min(x, N-K); i++) {
                arr.erase(lower_bound(arr.begin(), arr.end(), data[i]));
                data[i] += diff;
                arr.insert(lower_bound(arr.begin(), arr.end(), data[i]), data[i]);
            }
            printf("%d ", arr[(N-K+1)/2]);
        }
        puts("");
    }
    return 0;
}