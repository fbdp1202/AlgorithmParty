/*
대경권 본선 1번
문제설명
굉장히 말만 번잡한 시간잡아먹는 더러운 구현 문제... 정확한 문제는 사실 잘 기억안남. 알고리즘만 설명하겠다.

알고리즘:
- N개의 점수가 들어온다.
- N개의 점수는 정렬되어 들어오진 않는다.
- N개의 점수를 정렬하여 3구간으로 나누어서 본다.
- 0~30%, 30~70%, 70~100 구간으로 나누어 본다.
- 이 각각 구역에서, 우측값과 좌측 값과의 차이가 가장 큰 좌표를 pos라고 하자.
- 이 3개의 pos좌표를 구한 뒤, 각 pos 좌표의 좌우 경계선까지 거리를 각각 구한다.
- 여기서 나온 6개의 값 중 가장 큰 값과 작은 값을 출력하여라.
*/
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N = 100001;
int n, score[MAX_N], dif[3], pos[3];

bool cmp(int a, int b){
    return a > b;
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &score[i]);
    }

    sort(score, score+n, cmp);
    int A = n * 0.3;
    int B = n * 0.7;

    int maxi = 0;
    int mini = MAX_N;
    for(int i = 1; i < A; i++){
        if(score[i-1] - score[i] >= dif[0]){
            dif[0] = score[i-1] - score[i];
            pos[0] = i;
        }
    }

    for(int i = A + 1; i < B; i++){
        if(score[i-1] - score[i] >= dif[1]){
            dif[1] = score[i-1] - score[i];
            pos[1] = i;
        }
    }


    for(int i = B + 1; i < n; i++){
        if(score[i-1] - score[i] >= dif[2]){
            dif[2] = score[i-1] - score[i];
            pos[2] = i;
        }
    }

    maxi = max(maxi, pos[0]);
    maxi = max(maxi, A - pos[0]);
    maxi = max(maxi, pos[1] - A);
    maxi = max(maxi, B - pos[1]);
    maxi = max(maxi, pos[2] - B);
    maxi = max(maxi, n - pos[2]);

    mini = min(mini, pos[0]);
    mini = min(mini, A - pos[0]);
    mini = min(mini, pos[1] - A);
    mini = min(mini, B - pos[1]);
    mini = min(mini, pos[2] - B);
    mini = min(mini, n - pos[2]);

    printf("%d %d", maxi, mini);
	return 0;
}