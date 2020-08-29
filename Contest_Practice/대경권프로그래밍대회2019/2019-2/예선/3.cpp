/*
대경권 예선 3번
문제설명
총 N개의 임의의 R, G, B의 1차원 좌표 값이 주어진다.
이때, 하나의 선이 최소 1개 이상의 R, G, B좌표를 모두 포함하면서
최소의 길이를 가지게 하고 싶다.
이때, 최소의 길이를 출력하시오.

ex)
input:
5
1 3
1 5
2 4
3 6
3 1

output:
2

simulation:
[4:6] 좌표를 커버하는 길이 2인 선분이 최소이다.

알고리즘: 그리디 알고리즘
- 일단 좌표를 정렬한다.
- curr_R, curr_G, curr_B 값을 무한대로 설정한다.
- 작은 좌표부터 R,G,B에 따라 curr_R, curr_G, curr_B에 저장한다.
- 여기서 curr_R, curr_G, curr_B의 최대값과 최소값을 구해 그 차이가 3개의 RGB를 포함하는 '선분의 길이'다.
- N개의 좌표를 순환하며 최소의 선분길이를 찾는다.

- 아래 코드와 알고리즘이 다를 수 있다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> P;
const int MAX_N = 300001;

int N, cnt[4];
vector<int> color[4];
P left, right;

int main(void) {
    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        if(b == 1) color[1].push_back(a);
        else if(b == 2) color[2].push_back(a);
        else color[3].push_back(a);
    }

    if(color[1][0] > color[3][0]){
        if(color[3][0] > color[2][0]) {
            left = make_pair(color[2][0], 2);
            right = make_pair(color[1][0], 1);
        }
        else if(color[1][0] > color[2][0]){
            left = make_pair(color[3][0], 3);
            right = make_pair(color[1][0], 1);
        }
        else{
            left = make_pair(color[3][0], 3);
            right = make_pair(color[2][0], 2);
        }
    }

    else{
        if(color[3][0] < color[2][0]) {
            left = make_pair(color[1][0], 1);
            right = make_pair(color[2][0], 2);
        }
        else if(color[1][0] > color[2][0]){
            left = make_pair(color[2][0], 2);
            right = make_pair(color[3][0], 3);
        }
        else{
            left = make_pair(color[1][0], 1);
            right = make_pair(color[3][0], 3);
        }
    }

    int ans = 1e9;
    while(1){
        int l = left.first;
        int r = right.first;
        int lc = left.second;
        int rc = right.second;
        int oc = 6 - (lc + rc);

        ans = min(ans, r - l);
        cnt[lc]++;
        
        int x = cnt[lc];
        int y = cnt[oc];
        int z = cnt[rc];

        if(x == color[lc].size()) break;

        if(color[lc][x] > color[oc][y]){
            if(color[lc][x] > color[rc][z]){
                right = make_pair(color[lc][x], lc);
            }
            left = make_pair(color[oc][y], oc);
        }

        else {
            if(color[oc][y] > color[rc][z])
                right = make_pair(color[oc][y], oc);
            left = make_pair(color[lc][x], lc);
        }
    }
    printf("%d", ans);

    return 0;
}