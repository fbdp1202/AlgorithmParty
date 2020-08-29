/*
대경권 예선 2번
문제가 잘 기억이 안난다 ㅠ...
완전 탐색 문제.
N < 10 이며, K는 최대 100000이다.
각 N줄에 걸쳐 K의 값이 각 줄에 존재한다.

N값이 작으므로 N*N*K 만큼 for문 돌면서 모든 경우를 확인한다.
최대 매치 값을 출력한다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int N, K;
vector<int> id[10];
bool chk[10][100001];

int main(void) {
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < K; j++){
            int a;
            scanf("%d", &a);
            id[i].push_back(a);
            chk[i][a] = true;
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            int cnt = 0;
            for(int k = 0; k < K; k++){
                int cur = id[i][k];
                if(chk[j][cur]) cnt++;
            }
            ans = max(ans, cnt);
        }
    }
    printf("%d", ans);

    return 0;
}