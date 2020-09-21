// baekjoon 3985 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_L=1001;
const int MAX_N=1001;

int N, L;
bool visited[MAX_L];

int main() {
    scanf("%d%d", &L, &N);
    int realMaxL = 0;
    int realMaxIdx = 0;
    int exMaxL = 0;
    int exMaxIdx = 0;
    for (int i=1; i<=N; i++) {
        int P, K;
        scanf("%d%d", &P, &K);
        // real
        int count = 0;
        for (int j=P; j<=K; j++) {
            if (!visited[j]) {
                visited[j] = true;
                count++;
            }
        }
        if (count > realMaxL) {
            realMaxL = count;
            realMaxIdx = i;
        }
        // expect
        if (K-P > exMaxL) {
            exMaxL = K-P;
            exMaxIdx = i;
        }
    }
    printf("%d\n%d\n",exMaxIdx, realMaxIdx);
    return 0;
}