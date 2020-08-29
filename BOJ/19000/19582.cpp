#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N=100001;

int N;
int arr[MAX_N], money[MAX_N];

int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++)
        scanf("%d%d", &arr[i], &money[i]);

    int flag = 1;
    int max_money = 0;
    ll cur_money = 0;
    int count = 0;

    for (int i=0; i<N; i++) {
        if (cur_money <= arr[i]) {
            count++;
            cur_money += money[i];
            max_money = max(max_money, money[i]);
        } else if (flag == 1) {
            flag = 0;
            // pop here
            if (max_money <= money[i]) continue;

            // pop maximum money
            cur_money -= max_money;
            if (cur_money <= arr[i]) cur_money += money[i];
            else cur_money += max_money;
        } else {
            break;
        }
    }
    puts((count >= N-1) ? "Kkeo-eok" : "Zzz");
    return 0;
}