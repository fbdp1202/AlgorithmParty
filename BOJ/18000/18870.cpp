#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;

const int MAX_N=1000001;
const int MAX_INF=2e9;

int N;
int ret[MAX_N];
vector<P> arr;

int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        int x;
        scanf("%d", &x);
        arr.push_back(P(x,i));
    }
    sort(arr.begin(), arr.end());
    int prev = arr[0].first;
    int count = 0;
    for (int i=0; i<N; i++) {
        int now = arr[i].first;
        int pos = arr[i].second;
        if (prev != now) prev=now, count++;
        ret[pos] = count;
    }

    for (int i=0; i<N; i++)
        printf("%d ", ret[i]);
    puts("");
    return 0;
}